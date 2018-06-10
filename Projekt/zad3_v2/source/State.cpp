#include <mutex>
#include <condition_variable>

#include <State.hpp>


State::State(const int numberOfFloors)
	: numberOfFloors(numberOfFloors), peopleNotEnterElevator(true)
{
	elevatorReadyOnFloor = std::vector<bool>(numberOfFloors, false);
	elevatorOnFloorCondVar = std::vector<std::condition_variable>(numberOfFloors);
}

State::~State()
{
}
