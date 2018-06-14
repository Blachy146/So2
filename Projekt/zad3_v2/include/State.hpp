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
  std::vector<bool> addingPerson;
  std::vector<bool> elevatorReadyOnFloor;
  std::vector<std::condition_variable> elevatorOnFloorCondVar;
  std::condition_variable elevatorReadyToRunCondVar;
  std::vector<std::condition_variable> addingPersonCondVars;
  std::mutex elevatorMtx;
  std::mutex printMtx;
  std::mutex addingPersonMtx;
  std::mutex peopleMutex;
  std::vector<int> numberOfPeopleOnFloors;
  int numberOfPeopleInElevator;
  bool addingToElevator;
  std::condition_variable addingpersonToEleveatorCondVar;
  std::mutex addingPersonToElevatorMtx;
  std::mutex elevatorPeopleMutex;
  int elevatorCurrentFloor;
};
