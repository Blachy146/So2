#include <iostream>
#include <memory>
#include <future>
#include <functional>

#include <Building.hpp>
#include <Elevator.hpp>
#include <State.hpp>


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
}

void Building::run()
{
  std::cout << "Building running...\n";

  std::vector<std::future<void>> queuesFutures;

  auto elevatorFuture = std::async(std::launch::async, std::bind(&Elevator::run, *elevator));

  for(auto i = 0; i < queues.size(); ++i)
  {
    queuesFutures.push_back(std::async(std::launch::async, std::bind(&Queue::run, *queues[i])));
  }

  elevatorFuture.get();

  for(auto i = 0; i < queuesFutures.size(); ++i)
  {
    queuesFutures[i].get();
  }
}

Building::~Building()
{
}
