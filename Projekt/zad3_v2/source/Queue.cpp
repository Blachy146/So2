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
}

void Queue::run()
{
//  std::cout << "Queue running...\n";

  RandomGenerator randomGenerator(1000, 2000);
  RandomGenerator addMoreToQueueGenerator(0, 1);
  RandomGenerator peaopleRandomGenerator(0, people.size());

	while(true)
	{
		{
			printQueue();

			std::unique_lock<std::mutex> readyToEnterLock(state->elevatorMtx);

			state->elevatorOnFloorCondVar[floorNumber].wait(readyToEnterLock, [&]() { return state->elevatorReadyOnFloor[floorNumber]; });
			state->peopleEnterElevator = true;

			for(auto j = 0; j < peaopleRandomGenerator(); ++j)
			{
				{
					std::unique_lock<std::mutex> canChangePeopleLock(state->changePeopleMtxs[floorNumber]);

					state->changePeopleCondVars[floorNumber].wait(canChangePeopleLock, [&]() { return state->canChangePeople; });
					state->canChangePeople = false;

					if(people.size() > 0)
					{
						people.pop();
					}

					printQueue();
				}

				state->canChangePeople = true;
				state->changePeopleCondVars[floorNumber].notify_one();

				std::this_thread::sleep_for(std::chrono::milliseconds(randomGenerator()));
			}
		}

		state->peopleEnterElevator = false;
		state->elevatorReadyToRunCondVar.notify_one();

		std::this_thread::sleep_for(std::chrono::milliseconds(randomGenerator()));
	}
}

void Queue::printQueue()
{
	const int yCoord = yCoordOfFloor + 2;
	int row, col;
	getmaxyx(stdscr, row, col);

	state->printMtx.lock();

	move(yCoord, 22);
	clrtoeol();
	move(yCoord + 1, 22);
	clrtoeol();

	for(auto i = 0; i < people.size(); ++i)
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
			std::unique_lock<std::mutex> addPersonLock(state->addPersonToQueueMtx);

			state->personJoinQueueCondVar[floorNumber].wait(addPersonLock, [&]() { return state->addPerson; });
			state->addPerson = false;

			{
				std::unique_lock<std::mutex> canChangePeopleLock(state->changePeopleMtxs[floorNumber]);

				state->changePeopleCondVars[floorNumber].wait(canChangePeopleLock, [&]() { return state->canChangePeople; });
				state->canChangePeople = false;

				people.push(std::make_shared<Person>(state));

				printQueue();
			}

			state->canChangePeople = true;
			state->changePeopleCondVars[floorNumber].notify_one();
		}
	}
}

Queue::~Queue()
{
}
