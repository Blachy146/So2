#include "../include/Philosopher.hpp"


Philosopher::Philosopher(int id, std::pair<std::shared_ptr<Fork>, std::shared_ptr<Fork>> forks)
  : id(id), leftFork(forks.first), rightFork(forks.second)
{
}

int Philosopher::eat(int numberOfMeals)
{
  return 0;
}

Philosopher::~Philosopher()
{
}
