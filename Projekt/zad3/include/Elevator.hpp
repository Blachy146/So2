#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP

#include <memory>
#include <list>

#include <Person.hpp>
#include <Building.hpp>


class Elevator
{
public:
    explicit Elevator(int capacity, std::shared_ptr<Building> building);

    void addPerson(std::shared_ptr<Person> person);
    void removePerson();

    void openDoor();
    void closeDoor();

    ~Elevator();
private:
    const int capacity;
    std::weak_ptr<Building> building;
    std::list<std::shared_ptr<Person>> people;
};

#endif // ELEVATOR_HPP