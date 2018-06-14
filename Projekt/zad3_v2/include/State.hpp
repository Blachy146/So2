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
  bool addPerson;
  std::vector<bool> elevatorReadyOnFloor;
  std::vector<std::condition_variable> elevatorOnFloorCondVar;
  std::vector<std::condition_variable> personJoinQueueCondVar;
  std::condition_variable elevatorReadyToRunCondVar;
  std::mutex elevatorMtx;
  std::mutex printMtx;
  std::mutex addPersonToQueueMtx;
  std::vector<std::condition_variable> changePeopleCondVars;
  std::vector<std::mutex> changePeopleMtxs;
  bool canChangePeople;
};
