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
  : capacity(capacity), state(state)
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
    state->elevatorReadyOnFloor[state->elevatorCurrentFloor] = true;
    state->elevatorOnFloorCondVar[state->elevatorCurrentFloor].notify_one();

    RandomGenerator peopleRandomGen(0, state->numberOfPeopleInElevator);

    for(auto i = 0; i < peopleRandomGen(); ++i)
    {
      --state->numberOfPeopleInElevator;
      printElevator();

      state->addingPerson[state->elevatorCurrentFloor] = true;
      state->addingPersonCondVars[state->elevatorCurrentFloor].notify_one();

      std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    state->addingPerson[state->elevatorCurrentFloor] = false;

    printElevator();

    std::this_thread::sleep_for(std::chrono::milliseconds(openTimeRandomGenerator()));

		{
			std::unique_lock<std::mutex> readyToRunLock(state->elevatorMtx);

			state->elevatorReadyToRunCondVar.wait(readyToRunLock, [&]() { return !state->peopleEnterElevator; });
			state->elevatorReadyOnFloor[state->elevatorCurrentFloor] = false;

			removeElevator();

			state->elevatorCurrentFloor = floorRandomGenerator();

			std::this_thread::sleep_for(std::chrono::milliseconds(sleepTimeRandomGenerator()));
		}
	}
}

void Elevator::printNumberOfPeople()
{
}

void Elevator::addPeople()
{
	while(true)
	{
		{
			std::unique_lock<std::mutex> addPeopleLock(state->addingPersonToElevatorMtx);

			state->addingpersonToEleveatorCondVar.wait(addPeopleLock, [&]() { return state->addingToElevator; });
			state->addingToElevator = false;
			state->elevatorPeopleMutex.lock();

			++state->numberOfPeopleInElevator;
			printElevator();

			state->elevatorPeopleMutex.unlock();
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void Elevator::removeElevator()
{
	const int yCoord = yCoordsOfFloors[state->elevatorCurrentFloor] + 1;
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

	mvprintw(yCoord + 2, 9, " ");

	refresh();
	state->printMtx.unlock();
}

void Elevator::printElevator()
{
	const int yCoord = yCoordsOfFloors[state->elevatorCurrentFloor] + 1;
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

	mvprintw(yCoord + 2, 9, "%d", state->numberOfPeopleInElevator);

	refresh();
	state->printMtx.unlock();
}

Elevator::~Elevator()
{
	state->elevatorMtx.unlock();
}
