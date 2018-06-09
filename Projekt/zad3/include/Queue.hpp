#pragma once

#include <memory>
#include <queue>

#include <Building.hpp>
#include <Elevator.hpp>


class Queue
{
public:
	Queue(int id, std::shared_ptr<Building> building, std::shared_ptr<Elevator> elevator);
	Queue(int id, std::shared_ptr<Building>&& building, std::shared_ptr<Elevator> elevator);

	void addPerson(std::shared_ptr<Person> person);
	void removePerson();

	~Queue();
private:
	const int id;
	std::weak_ptr<Building> building;
	std::weak_ptr<Elevator> elevator;
	std::queue<std::shared_ptr<Person>> people;
};
