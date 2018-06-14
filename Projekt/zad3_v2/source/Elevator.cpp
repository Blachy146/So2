#include <memory>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>
#include <chrono>
#include <ncurses.h>

#include <Elevator.hpp>
#include <State.hpp>
#include <RandomGenerator.hpp>


Elevator::Elevator(const int capacity, std::shared_ptr<State> state)
  : capacity(capacity), state(state), currentFloor(0)
{
  state->elevatorMtx.lock();
}

void Elevator::run()
{
  RandomGenerator floorRandomGenerator(0, 3);
  RandomGenerator sleepTimeRandomGenerator(1000, 2000);
  RandomGenerator openTimeRandomGenerator(800, 1200);

  while(true)
  {
    state->elevatorMtx.unlock();
    state->elevatorReadyOnFloor[currentFloor] = true;
    state->elevatorOnFloorCondVar[currentFloor].notify_one();

    printElevator();

    std::this_thread::sleep_for(std::chrono::milliseconds(openTimeRandomGenerator()));

		{
			std::unique_lock<std::mutex> readyToRunLock(state->elevatorMtx);

			state->elevatorReadyToRunCondVar.wait(readyToRunLock, [&]() { return !state->peopleEnterElevator; });
			state->elevatorReadyOnFloor[currentFloor] = false;

			removeElevator();

			currentFloor = floorRandomGenerator();

			std::this_thread::sleep_for(std::chrono::milliseconds(sleepTimeRandomGenerator()));
		}
	}
}

void Elevator::openDoor()
{
}

void Elevator::closeDoor()
{
}

void Elevator::removeElevator()
{
	const int yCoord = yCoordsOfFloors[currentFloor] + 1;
	int row, col;
	getmaxyx(stdscr, row, col);

	state->printMtx.lock();

	for(auto i = 1; i < 18; ++i)
	{
		mvprintw(yCoord, i, " ");
		mvprintw(yCoord + 3, i, " ");
	}

	for(auto i = yCoord + 1; i < yCoord + 3; ++i)
	{
		mvprintw(i, 1, " ");
		mvprintw(i, 18, " ");
	}

	refresh();
	state->printMtx.unlock();
}

void Elevator::printElevator()
{
	const int yCoord = yCoordsOfFloors[currentFloor] + 1;
	int row, col;
	getmaxyx(stdscr, row, col);

	state->printMtx.lock();

	for(auto i = 1; i < 18; ++i)
	{
		mvprintw(yCoord, i, "-");
		mvprintw(yCoord + 3, i, "-");
	}

	for(auto i = yCoord + 1; i < yCoord + 3; ++i)
	{
		mvprintw(i, 1, "|");
		mvprintw(i, 18, "|");
	}

	refresh();
	state->printMtx.unlock();
}

Elevator::~Elevator()
{
	state->elevatorMtx.unlock();
}
