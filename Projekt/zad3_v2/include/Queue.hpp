#pragma once

#include <queue>
#include <memory>

#include <Person.hpp>


class Queue
{
public:
  Queue(const int initialNumberOfPeople);
  ~Queue();
private:
  std::queue<std::shared_ptr<Person>> people;
};
