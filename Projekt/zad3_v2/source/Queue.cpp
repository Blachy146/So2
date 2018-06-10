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

  for(auto i = 0; i < 10; ++i)
  {
    state->peopleNotEnterElevator = false;

    {
      std::unique_lock<std::mutex> readyToEnterLock(state->elevatorMtx);

      state->elevatorOnFloorCondVar[floorNumber].wait(readyToEnterLock, [&]() { return state->elevatorReadyOnFloor; });

      std::cout << "People entering to elevator from queue\n";

      std::this_thread::sleep_for(std::chrono::milliseconds(randomGenerator()));
    }

    state->peopleNotEnterElevator = true;
    state->elevatorReadyToRunCondVar.notify_one();
  }
}

void Queue::personTryToEnterElevator()
{
}

Queue::~Queue()
{
}
