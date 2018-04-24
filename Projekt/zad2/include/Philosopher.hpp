#pragma once

#include <memory>
#include <mutex>

#include "./Fork.hpp"
#include "./RandomGenerator.hpp"


class Philosopher
{
public:
  Philosopher(int id, std::pair<std::shared_ptr<Fork>, std::shared_ptr<Fork>> forks, std::shared_ptr<std::mutex> printMtx);

  int eat(int numberOfMeals);
  int eatMeal();

  ~Philosopher();
private:
  const int id;
  std::shared_ptr<Fork> leftFork;
  std::shared_ptr<Fork> rightFork;
  std::shared_ptr<std::mutex> printMtx;
  RandomGenerator randomGenerator;
};
