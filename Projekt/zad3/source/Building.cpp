#include <memory>

#include <Building.hpp>
#include <Elevator.hpp>
#include <Queue.hpp>


Building::Building(const int numberOfFloors)
    : numberOfFloors(numberOfFloors), elevator(std::make_shared<Elevator>())
{
    for (auto i = 0; i < numberOfFloors; ++i)
    {
        this->floors.push_back(std::make_shared<Queue>(i, elevator));
    }
}

Building::~Building()
{
}