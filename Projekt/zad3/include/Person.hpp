#pragma once

#include <memory>

#include <Queue.hpp>
#include <Elevator.hpp>


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
