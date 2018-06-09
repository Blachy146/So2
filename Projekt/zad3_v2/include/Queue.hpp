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
  Queue(const int initialNumberOfPeople, std::shared_ptr<State> state);
  ~Queue();
private:
  std::shared_ptr<State> state;
  std::queue<std::shared_ptr<Person>> people;
};
