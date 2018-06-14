#include <mutex>
#include <condition_variable>

#include <State.hpp>


State::State(const int numberOfFloors)
	: numberOfFloors(numberOfFloors), peopleEnterElevator(false), addPerson(false), canChangePeople(true)
{
	elevatorReadyOnFloor = std::vector<bool>(numberOfFloors, false);
	elevatorOnFloorCondVar = std::vector<std::condition_variable>(numberOfFloors);
	personJoinQueueCondVar = std::vector<std::condition_variable>(numberOfFloors);
	personJoinQueueCondVar = std::vector<std::condition_variable>(numberOfFloors);
	changePeopleCondVars = std::vector<std::condition_variable>(numberOfFloors);
	changePeopleMtxs = std::vector<std::mutex>(numberOfFloors);
}

State::~State()
{
}
