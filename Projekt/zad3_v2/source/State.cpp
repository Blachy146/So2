#include <mutex>
#include <condition_variable>

#include <State.hpp>


State::State(const int numberOfFloors)
	: numberOfFloors(numberOfFloors), peopleEnterElevator(false)
{
	elevatorReadyOnFloor = std::vector<bool>(numberOfFloors, false);
	elevatorOnFloorCondVar = std::vector<std::condition_variable>(numberOfFloors);
	addingPerson = std::vector<bool>(numberOfFloors, false);
	addingPersonCondVars = std::vector<std::condition_variable>(numberOfFloors);
	numberOfPeopleOnFloors = std::vector<int>(numberOfFloors, 0);
	numberOfPeopleInElevator = 0;
	addingToElevator = false;
	elevatorCurrentFloor = 0;
}

State::~State()
{
}
