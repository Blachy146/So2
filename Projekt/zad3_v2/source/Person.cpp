#include <thread>
#include <chrono>
#include <iostream>

#include <Person.hpp>
#include <RandomGenerator.hpp>
#include <Queue.hpp>


Person::Person(std::shared_ptr<State> state)
  : numberOfFloors(0), state(state)
{
}

Person::Person(const int numberOfFloors, std::shared_ptr<State> state)
  : numberOfFloors(numberOfFloors), state(state)
{
}

void Person::joinRandomQueue()
{
  RandomGenerator randomGenerator(100, 50000);
  RandomGenerator queueGenerator(0, numberOfFloors - 1);

  auto randomFloor = queueGenerator();

  std::this_thread::sleep_for(std::chrono::milliseconds(randomGenerator()));

  state->addingPerson[randomFloor] = true;
  state->addingPersonCondVars[randomFloor].notify_one();
}

Person::~Person()
{
}
