#include <memory>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <iostream>
#include <chrono>
#include <ncurses.h>

#include <Queue.hpp>
#include <Person.hpp>
#include <State.hpp>
#include <RandomGenerator.hpp>


Queue::Queue(const int initialNumberOfPeople, const int floorNumber, std::shared_ptr<State> state)
  : floorNumber(floorNumber), state(state)
{
  for(auto i = 0; i < initialNumberOfPeople; ++i)
  {
    people.push(std::make_shared<Person>(state));
  }

  state->numberOfPeopleOnFloors[floorNumber] = initialNumberOfPeople;
}

void Queue::run()
{
  RandomGenerator randomGenerator(1000, 2000);
  RandomGenerator peopleRandomGenerator(0, state->numberOfPeopleOnFloors[floorNumber]);

	while(true)
	{
		{
			printQueue();

			std::unique_lock<std::mutex> readyToEnterLock(state->elevatorMtx);

			state->elevatorOnFloorCondVar[floorNumber].wait(readyToEnterLock, [&]() { return state->elevatorReadyOnFloor[floorNumber] && !state->addingPerson[floorNumber]; });
			state->peopleEnterElevator = true;


			for(auto j = 0; j < peopleRandomGenerator(); ++j)
			{
				state->peopleMutex.lock();

				if(state->numberOfPeopleOnFloors[floorNumber] > 0)
				{
					--state->numberOfPeopleOnFloors[floorNumber];

					state->addingToElevator = true;
					state->addingpersonToEleveatorCondVar.notify_one();
				}

				printQueue();

				state->peopleMutex.unlock();

				std::this_thread::sleep_for(std::chrono::milliseconds(randomGenerator()));
				state->addingToElevator = false;
			}
		}

		state->peopleEnterElevator = false;
		state->elevatorReadyToRunCondVar.notify_one();

		std::this_thread::sleep_for(std::chrono::milliseconds(randomGenerator()));
	}
}

void Queue::printQueue()
{
	state->printMtx.lock();

	const int yCoord = yCoordOfFloor + 2;
	int row, col;
	getmaxyx(stdscr, row, col);

	move(yCoord, 22);
	clrtoeol();
	move(yCoord + 1, 22);
	clrtoeol();

	for(auto i = 0; i < state->numberOfPeopleOnFloors[floorNumber]; ++i)
	{
		mvprintw(yCoord, i + 22, "O ");
		mvprintw(yCoord + 1, i + 22, "|");
	}

	refresh();
	state->printMtx.unlock();
}

void Queue::addNewPeople()
{
	while(true)
	{
		{
			std::unique_lock<std::mutex> addingPersonLock(state->addingPersonMtx);

			state->addingPersonCondVars[floorNumber].wait(addingPersonLock, [&]() { return state->addingPerson[floorNumber]; });
			state->addingPerson[floorNumber] = false;

			state->peopleMutex.lock();

			++state->numberOfPeopleOnFloors[floorNumber];

			printQueue();

			state->peopleMutex.unlock();

			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
	}
}

Queue::~Queue()
{
}
