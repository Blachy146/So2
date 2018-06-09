#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <memory>
#include <queue>

#include <Elevator.hpp>
#include <Person.hpp>
#include <Building.hpp>


class Queue
{
public:
    Queue(int id, std::shared_ptr<Building> building, std::shared_ptr<Elevator> elevator);

    void addPerson(std::shared_ptr<Person> person);
    void removePerson();

    ~Queue();
private:
    const int id;
    std::weak_ptr<Building> building;
    std::weak_ptr<Elevator> elevator;
    std::queue<std::shared_ptr<Person>> people;
};

#endif // QUEUE_HPP