#pragma once

#include <memory>
#include <list>

#include <Building.hpp>
#include <Person.hpp>


class Elevator
{
public:
	Elevator(int capacity, std::shared_ptr<Building> building);
	Elevator(int capacity, std::shared_ptr<Building>&& building);

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
