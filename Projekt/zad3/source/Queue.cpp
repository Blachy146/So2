#include <memory>
#include <queue>

#include <Queue.hpp>


Queue::Queue(int id, std::shared_ptr<Building> building, std::shared_ptr<Elevator> elevator)
  : id(id), building(building), elevator(elevator)
{
}

Queue::Queue(int id, std::shared_ptr<Building>&& building, std::shared_ptr<Elevator> elevator)
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
