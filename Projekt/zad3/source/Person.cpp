#include <memory>

#include "Person.hpp"
#include "Queue.hpp"
#include "Elevator.hpp"


Person::Person(const int id)
    : id(id)
{
}

void Person::joinQueue(std::shared_ptr<Queue> queue)
{
}

void Person::enterElevator(std::shared_ptr<Elevator> elevator)
{
}

Person::~Person()
{
}