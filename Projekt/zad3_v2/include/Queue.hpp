#pragma once

#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>

#include <Person.hpp>
#include <State.hpp>


class Queue
{
public:
  Queue(const int initialNumberOfPeople, const int floorNumber, std::shared_ptr<State> state);

  void run();
  void personTryToEnterElevator();

  ~Queue();
private:
  const int floorNumber;
  std::shared_ptr<State> state;
  std::queue<std::shared_ptr<Person>> people;
};
