#include <memory>

#include <Person.hpp>


Person::Person(const int id)
	: id(id)
{
}

void Person::joinQueue(std::shared_ptr<Queue> queue)
{
	this->queue = queue;
}

void Person::leaveQueue()
{
	this->queue.reset();
}

void Person::enterElevator(std::shared_ptr<Elevator> elevator)
{
	this->elevator = elevator;
}

void Person::leaveElevator()
{
	this->elevator.reset();
}

Person::~Person()
{
}
