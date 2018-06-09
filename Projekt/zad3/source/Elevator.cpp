#include <memory>
#include <list>

#include <Elevator.hpp>


Elevator::Elevator(int capacity, std::shared_ptr<Building> building)
  : capacity(capacity), building(building)
{
}

Elevator::Elevator(int capacity, std::shared_ptr<Building>&& building)
  : capacity(capacity), building(building)
{
}

void Elevator::addPerson(std::shared_ptr<Person> person)
{
}

void Elevator::removePerson()
{
}

Elevator::~Elevator()
{
}
