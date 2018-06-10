#include <memory>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>
#include <chrono>

#include <Elevator.hpp>
#include <State.hpp>
#include <RandomGenerator.hpp>


Elevator::Elevator(const int capacity, std::shared_ptr<State> state)
  : capacity(capacity), state(state), currentFloor(0)
{
  state->elevatorMtx.lock();
}

void Elevator::run()
{
  std::cout << "Elevator is running...\n";

  RandomGenerator floorRandomGenerator(0, 1);
  RandomGenerator sleepTimeRandomGenerator(1000, 2000);

  for(auto i = 0; i < 2; ++i)
  {
    state->elevatorMtx.unlock();
    state->elevatorReadyOnFloor[currentFloor] = true;
    state->elevatorOnFloorCondVar[currentFloor].notify_one();

    std::cout << "Elevator's door open on floor: " << currentFloor << "\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(sleepTimeRandomGenerator()));

		{
			std::unique_lock<std::mutex> readyToRunLock(state->elevatorMtx);

			state->elevatorReadyToRunCondVar.wait(readyToRunLock, [&]() { return state->peopleNotEnterElevator; });
			state->elevatorReadyOnFloor[currentFloor] = false;

			std::cout << "Elevator's door close\n";

			currentFloor = floorRandomGenerator();

			std::this_thread::sleep_for(std::chrono::milliseconds(sleepTimeRandomGenerator()));
		}
	}
}

void Elevator::openDoor()
{
}

void Elevator::closeDoor()
{
}

Elevator::~Elevator()
{
	state->elevatorMtx.unlock();
}
