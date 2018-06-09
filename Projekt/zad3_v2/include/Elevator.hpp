#pragma once

#include <memory>
#include <mutex>
#include <condition_variable>

#include <State.hpp>


class Elevator
{
public:
  Elevator(const int capacity, std::shared_ptr<State> state);

  void openDoor();
  void closeDoor();

  ~Elevator();
private:
  const int capacity;
  std::shared_ptr<State> state;
  const int currentFloor;
};
