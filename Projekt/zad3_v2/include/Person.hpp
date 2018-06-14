#pragma once

#include <State.hpp>
#include <memory>

class Person
{
public:
  explicit Person(std::shared_ptr<State> state);
  Person(const int numberOfFloors, std::shared_ptr<State> state);

  void joinRandomQueue();

  ~Person();
private:
  const int numberOfFloors;
  std::shared_ptr<State> state;
};
