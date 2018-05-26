#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <memory>
#include <queue>

#include <Elevator.hpp>
#include <Person.hpp>


class Queue
{
public:
    Queue(const int id, std::shared_ptr<Elevator> elevator);
    ~Queue();
private:
    const int id;
    std::weak_ptr<Elevator> elevator;
    std::queue<std::shared_ptr<Person>> people;
};

#endif // QUEUE_HPP