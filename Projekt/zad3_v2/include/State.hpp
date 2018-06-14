#pragma once

#include <mutex>
#include <condition_variable>
#include <vector>


class State
{
public:
  State(const int numberOfFloors);
  ~State();

  const int numberOfFloors;
  bool peopleEnterElevator;
  bool peopleLeavingElevator;
  std::vector<bool> elevatorReadyOnFloor;
  std::vector<std::condition_variable> elevatorOnFloorCondVar;
  std::condition_variable elevatorReadyToRunCondVar;
  std::mutex elevatorMtx;
  std::mutex printMtx;
};
