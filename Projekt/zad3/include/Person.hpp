#ifndef PERSON_HPP
#define PERSON_HPP

#include <memory>

#include <Elevator.hpp>
#include <Queue.hpp>

class Person
{
public:
    explicit Person(const int id);

    void joinQueue(std::shared_ptr<Queue> queue);
    void leaveQueue();
    void enterElevator(std::shared_ptr<Elevator> elevator);
    void leaveElevator();

    ~Person();
private:
    const int id;
    std::weak_ptr<Queue> queue;    
    std::weak_ptr<Elevator> elevator;    
};

#endif // PERSON_HPP