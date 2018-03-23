#include <iostream>
#include <memory>
#include <vector>

#include "../include/Philosopher.hpp"


std::vector<std::shared_ptr<Fork>> createForks(int numberOfForks)
{
  std::vector<std::shared_ptr<Fork>> forks;

  for (auto i = 0; i < numberOfForks; ++i)
  {
    forks.push_back(std::make_shared<Fork>(i));
  }

  return forks;
}

std::vector<std::unique_ptr<Philosopher>> createPhilosophers(std::vector<std::shared_ptr<Fork>>& forks)
{
  std::vector<std::unique_ptr<Philosopher>> philosophers;

  for (auto i = 0u; i < forks.size() - 1; ++i)
  {
    philosophers.push_back(std::make_unique<Philosopher>(i, std::make_pair(forks[i], forks[i+1])));
  }

  philosophers.push_back(std::make_unique<Philosopher>(forks.size() - 1, std::make_pair(forks[forks.size() - 1], forks[0])));

  return philosophers;
}

int main()
{
  const int numberOfPhilosophers = 5;

  auto forks = createForks(numberOfPhilosophers);
  auto philosophers = createPhilosophers(forks);
}
