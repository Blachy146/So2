#include <iostream>
#include <memory>
#include <vector>
#include <future>
#include <functional>
#include <ncurses.h>

#include "../include/Philosopher.hpp"


std::vector<std::shared_ptr<Fork>> createForks(int numberOfForks, std::shared_ptr<std::mutex> printMtx)
{
  std::vector<std::shared_ptr<Fork>> forks;

  for (auto i = 0; i < numberOfForks; ++i)
  {
    forks.push_back(std::make_shared<Fork>(i, printMtx));
  }

  return forks;
}

std::vector<Philosopher> createPhilosophers(std::vector<std::shared_ptr<Fork>>& forks, std::shared_ptr<std::mutex> printMtx)
{
  std::vector<Philosopher> philosophers;

  for (auto i = 0u; i < forks.size() - 1; ++i)
  {
    philosophers.push_back(Philosopher(i, std::make_pair(forks[i], forks[i+1]), printMtx));
  }

  philosophers.push_back(Philosopher(forks.size() - 1, std::make_pair(forks[forks.size() - 1], forks[0]), printMtx));

  return philosophers;
}

int main()
{
  const int numberOfPhilosophers = 5;
  const int numberOfMeals = 5;
  std::shared_ptr<std::mutex> printMtx = std::make_shared<std::mutex>();

  auto forks = createForks(numberOfPhilosophers, printMtx);
  auto philosophers = createPhilosophers(forks, printMtx);

  std::vector<std::future<int>> philosopherFutures;

  initscr();

  for (auto& philosopher : philosophers)
  {
    auto philosopherFuture = std::async(std::launch::async, std::bind(&Philosopher::eat, philosopher, std::placeholders::_1), numberOfMeals);

    philosopherFutures.push_back(std::move(philosopherFuture));
  }

  for (auto& future : philosopherFutures)
  {
    future.get();
  }

  endwin();
}
