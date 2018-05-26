#include <memory>
#include <queue>

#include <Queue.hpp>
#include <Elevator.hpp>


Queue::Queue(const int id, std::shared_ptr<Elevator> elevator)
    : id(id), elevator(elevator)
{
}

Queue::~Queue()
{
}