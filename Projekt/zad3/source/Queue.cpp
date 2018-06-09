#include <memory>
#include <queue>

#include <Queue.hpp>
#include <Elevator.hpp>
#include <Building.hpp>


Queue::Queue(int id, std::shared_ptr<Building> building, std::shared_ptr<Elevator> elevator)
    : id(id), building(building), elevator(elevator)
{
}

void Queue::addPerson(std::shared_ptr<Person> person)
{
}

void Queue::removePerson()
{
}

Queue::~Queue()
{
}