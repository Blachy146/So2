#include <iostream>
#include <chrono>
#include <thread>

#include "../include/Philosopher.hpp"


Philosopher::Philosopher(int id, std::pair<std::shared_ptr<Fork>, std::shared_ptr<Fork>> forks)
  : id(id), leftFork(forks.first), rightFork(forks.second)
{
}

int Philosopher::eat(int numberOfMeals)
{
  std::cout << "Philosopher" << id << ": eat\n";

  for (auto i = 0; i < numberOfMeals; ++i)
  {
    eatMeal();
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  return 0;
}

int Philosopher::eatMeal()
{
  std::cout << "Philosopher" << id << ": eatMeal\n";

  leftFork->startUsing();
  rightFork->startUsing();

    std::this_thread::sleep_for(std::chrono::seconds(1));

  leftFork->stopUsing();
  rightFork->stopUsing();

  return 0;
}

Philosopher::~Philosopher()
{
}
