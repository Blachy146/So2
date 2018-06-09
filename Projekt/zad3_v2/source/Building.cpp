#include <iostream>
#include <memory>

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
		queues.push_back(std::make_shared<Queue>(numberOfPeoplePerFloor, state));
	}
}

void Building::run()
{
  std::cout << "Building running...\n";
}

Building::~Building()
{
}
