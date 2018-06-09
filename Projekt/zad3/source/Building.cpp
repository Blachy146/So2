#include <memory>

#include <Building.hpp>
#include <Elevator.hpp>
#include <Queue.hpp>


Building::Building(const int numberOfFloors, const int elevatorCapacity, const int numberOfPeoplePerFloor)
    : numberOfFloors(numberOfFloors),
      elevatorCapacity(elevatorCapacity),
      numberOfPeoplePerFloor(numberOfPeoplePerFloor)
{
    elevator = std::make_shared<Elevator>(elevatorCapacity, std::shared_ptr<Building>(this));

    for (auto i = 0; i < numberOfFloors; ++i)
    {
        this->floors.push_back(std::make_shared<Queue>(i, std::shared_ptr<Building>(this), elevator));
    }
}

void Building::runElevator()
{
}

Building::~Building()
{
}