#pragma once

#include <memory>

#include "./Fork.hpp"


class Philosopher
{
public:
  Philosopher(int id, std::pair<std::shared_ptr<Fork>, std::shared_ptr<Fork>> forks);

  int eat(int numberOfMeals);

  ~Philosopher();
private:
  const int id;
  std::shared_ptr<Fork> leftFork;
  std::shared_ptr<Fork> rightFork;
};
