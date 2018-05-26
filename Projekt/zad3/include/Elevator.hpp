#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP

#include <memory>
#include <list>

#include <Person.hpp>


class Elevator
{
public:
    explicit Elevator(const int capacity);
    ~Elevator();
private:
    const int capacity;
    std::list<std::shared_ptr<Person>> people;
};

#endif // ELEVATOR_HPP