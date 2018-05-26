#pragma once

#include <memory>

#include "Queue.hpp"
#include "Elevator.hpp"


class Person
{
public:
    explicit Person(const int id);

    void joinQueue(std::shared_ptr<Queue> queue);
    void enterElevator(std::shared_ptr<Elevator> elevator);

    ~Person();
private:
    const int id;
};
