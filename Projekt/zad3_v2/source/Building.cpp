#include <iostream>
#include <memory>

#include <Building.hpp>
#include <Elevator.hpp>


Building::Building(const int numberOfFloors, const int elevatorCapacity, const int numberOfPeoplePerFloor)
	: numberOfFloors(numberOfFloors),
		elevatorCapacity(elevatorCapacity),
		numberOfPeoplePerFloor(numberOfPeoplePerFloor)
{
	elevator = std::make_shared<Elevator>();

	for(auto i = 0; i < numberOfFloors; ++i)
	{
		queues.push_back(std::make_shared<Queue>(numberOfPeoplePerFloor));
	}
}

void Building::run()
{
  std::cout << "Building running...\n";
}

Building::~Building()
{
}
