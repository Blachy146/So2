#include <mutex>
#include <condition_variable>

#include <State.hpp>


State::State(const int numberOfFloors)
	: numberOfFloors(numberOfFloors)
{
	elevatorOnFloor = std::vector<std::condition_variable>(numberOfFloors);
}

void State::startChangingState()
{
}

void State::stopChangingState()
{
}

State::~State()
{
}
