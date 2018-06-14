#include <iostream>
#include <memory>
#include <future>
#include <functional>
#include <ncurses.h>
#include <algorithm>

#include <Building.hpp>
#include <Elevator.hpp>
#include <State.hpp>
#include <Person.hpp>


Building::Building(const int numberOfFloors, const int elevatorCapacity, const int numberOfPeoplePerFloor)
	: numberOfFloors(numberOfFloors),
		elevatorCapacity(elevatorCapacity),
		numberOfPeoplePerFloor(numberOfPeoplePerFloor),
		state(std::make_shared<State>(numberOfFloors))
{
	elevator = std::make_shared<Elevator>(elevatorCapacity, state);

	for(auto i = 0; i < numberOfFloors; ++i)
	{
		queues.push_back(std::make_shared<Queue>(numberOfPeoplePerFloor, i, state));
	}

	for(auto i = 0; i < 10; ++i)
	{
		additionalPeople.push_back(std::make_shared<Person>(numberOfFloors, state));
	}
}

void Building::run()
{
//  std::cout << "Building running...\n";

  auto yCoordsOfFloors = printBuilding();

  elevator->yCoordsOfFloors = yCoordsOfFloors;

  std::vector<std::future<void>> queuesFutures;
  std::vector<std::future<void>> peopleFutures;
  std::vector<std::future<void>> addPeopleToQueuesFutures;
  auto elevatorFuture = std::async(std::launch::async, std::bind(&Elevator::run, *elevator));

  for(auto i = 0; i < queues.size(); ++i)
  {
    queues[i]->yCoordOfFloor = yCoordsOfFloors[i];
    queuesFutures.push_back(std::async(std::launch::async, std::bind(&Queue::run, *queues[i])));
  }

  for(auto i = 0; i < queues.size(); ++i)
  {
    addPeopleToQueuesFutures.push_back(std::async(std::launch::async, std::bind(&Queue::addNewPeople, *queues[i])));
  }

  for(auto i = 0; i < additionalPeople.size(); ++i)
  {
    peopleFutures.push_back(std::async(std::launch::async, std::bind(&Person::joinRandomQueue, *additionalPeople[i])));
  }

  elevatorFuture.get();

  for(auto i = 0; i < queuesFutures.size(); ++i)
  {
    queuesFutures[i].get();
  }

  for(auto i = 0; i < peopleFutures.size(); ++i)
  {
    peopleFutures[i].get();
  }

  for(auto i = 0; i < addPeopleToQueuesFutures.size(); ++i)
  {
    addPeopleToQueuesFutures[i].get();
  }
}

std::vector<int> Building::printBuilding()
{
	std::vector<int> yCoordsOfFloors;
	int row, col;
	getmaxyx(stdscr, row, col);

	state->printMtx.lock();


	for(auto j = 0; j < 80; ++j)
	{
		mvprintw(0, j, "-");
	}

	for(auto i = 1; i < numberOfFloors * 5; ++i)
	{
		if (i % 5 == 0)
		{
			for(auto j = 0; j < 80; ++j)
			{
				mvprintw(i, j, "-");
			}

			yCoordsOfFloors.push_back(i);
		}

		mvprintw(i, 0, "|");
		mvprintw(i, 19, "|");
	}

	for(auto j = 0; j < 80; ++j)
	{
		mvprintw(numberOfFloors * 5, j, "-");
	}

	refresh();
	state->printMtx.unlock();
	std::reverse(yCoordsOfFloors.begin(), yCoordsOfFloors.end());

	return yCoordsOfFloors;
}

Building::~Building()
{
}
