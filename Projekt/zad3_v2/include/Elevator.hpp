#pragma once

#include <memory>
#include <mutex>
#include <condition_variable>

#include <State.hpp>


class Elevator
{
public:
  Elevator(const int capacity, std::shared_ptr<State> state);

  void run();
  void openDoor();
  void closeDoor();
  void removeElevator();
  void printElevator();

  ~Elevator();

  std::vector<int> yCoordsOfFloors;
private:
  const int capacity;
  std::shared_ptr<State> state;
  int currentFloor;
};
