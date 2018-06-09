#pragma once

#include <memory>
#include <vector>

#include <Elevator.hpp>
#include <Queue.hpp>


class Building
{
public:
  Building(const int numberOfFloors, const int elevatorCapacity, const int numberOfPeoplePerFloor);

  void run();

  ~Building();
private:
  const int numberOfFloors;
  const int elevatorCapacity;
  const int numberOfPeoplePerFloor;
  std::shared_ptr<Elevator> elevator;
  std::vector<std::shared_ptr<Queue>> queues;
};
