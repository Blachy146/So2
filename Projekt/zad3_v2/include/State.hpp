#pragma once

#include <mutex>
#include <condition_variable>
#include <vector>


class State
{
public:
  State(const int numberOfFloors);

  void startChangingState();
  void stopChangingState();

  ~State();

  const int numberOfFloors;
  std::vector<std::condition_variable> elevatorOnFloor;
  std::condition_variable elevatorDoorOpen;
  std::mutex elevatorMtx;
  std::mutex changeStateMtx;
};
