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
    people.push(std::make_shared<Person>());
  }
}

void Queue::run()
{
//  std::cout << "Queue running...\n";

  RandomGenerator randomGenerator(1000, 2000);
  RandomGenerator peaopleRandomGenerator(0, people.size());

	while(true)
	{
		{
//			std::cout << "People are waiting for elevator on floor: " << floorNumber << "\n";

			printQueue();

			std::unique_lock<std::mutex> readyToEnterLock(state->elevatorMtx);

			state->elevatorOnFloorCondVar[floorNumber].wait(readyToEnterLock, [&]() { return state->elevatorReadyOnFloor[floorNumber]; });
			state->peopleEnterElevator = true;

			for(auto j = 0; j < peaopleRandomGenerator(); ++i)
			{
//				std::cout << "People are entering elevator from queue on floor: " << floorNumber << "\n";
				if(people.size() > 0)
				{
					people.pop();
				}

				printQueue();

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

Queue::~Queue()
{
}
