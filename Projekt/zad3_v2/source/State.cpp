#include <mutex>
#include <condition_variable>

#include <State.hpp>


State::State(const int numberOfFloors)
	: numberOfFloors(numberOfFloors), peopleEnterElevator(false)
{
	elevatorReadyOnFloor = std::vector<bool>(numberOfFloors, false);
	elevatorOnFloorCondVar = std::vector<std::condition_variable>(numberOfFloors);
}

State::~State()
{
}
