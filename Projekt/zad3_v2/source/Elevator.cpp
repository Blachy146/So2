#include <memory>
#include <mutex>
#include <condition_variable>

#include <Elevator.hpp>
#include <State.hpp>


Elevator::Elevator(const int capacity, std::shared_ptr<State> state)
  : capacity(capacity), state(state), currentFloor(0)
{
}

void Elevator::openDoor()
{
}

void Elevator::closeDoor()
{
}

Elevator::~Elevator()
{
}
