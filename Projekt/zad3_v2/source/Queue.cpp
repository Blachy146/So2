#include <memory>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <iostream>
#include <chrono>

#include <Queue.hpp>
#include <Person.hpp>
#include <State.hpp>
#include <RandomGenerator.hpp>


Queue::Queue(const int initialNumberOfPeople, const int floorNumber, std::shared_ptr<State> state)
  : floorNumber(floorNumber), state(state)
{
  for(auto i = 0; i < initialNumberOfPeople; ++i)
  {
    people.push(std::make_shared<Person>());
  }
}

void Queue::run()
{
  std::cout << "Queue running...\n";

  RandomGenerator randomGenerator(1000, 2000);
  RandomGenerator peaopleRandomGenerator(0, people.size());

	for(auto i = 0; i < 10; ++i)
	{
		{
			std::cout << "People are waiting for elevator on floor: " << floorNumber << "\n";

			std::unique_lock<std::mutex> readyToEnterLock(state->elevatorMtx);

			state->elevatorOnFloorCondVar[floorNumber].wait(readyToEnterLock, [&]() { return state->elevatorReadyOnFloor[floorNumber]; });
			state->peopleNotEnterElevator = false;

			for(auto j = 0; j < peaopleRandomGenerator(); ++i)
			{
				std::cout << "People are entering elevator from queue on floor: " << floorNumber << "\n";

				std::this_thread::sleep_for(std::chrono::milliseconds(randomGenerator()));
			}
		}

		state->peopleNotEnterElevator = true;
		state->elevatorReadyToRunCondVar.notify_one();

		std::this_thread::sleep_for(std::chrono::milliseconds(randomGenerator()));
	}
}

void Queue::personTryToEnterElevator()
{
}

Queue::~Queue()
{
}
