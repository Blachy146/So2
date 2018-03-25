#include <iostream>
#include <chrono>
#include <thread>
#include <ncurses.h>

#include "../include/Philosopher.hpp"
#include "../include/RandomGenerator.hpp"


Philosopher::Philosopher(int id, std::pair<std::shared_ptr<Fork>, std::shared_ptr<Fork>> forks, std::shared_ptr<std::mutex> printMtx)
  : id(id), leftFork(forks.first), rightFork(forks.second), printMtx(printMtx), randomGenerator(10000, 20000)
{
}

int Philosopher::eat(int numberOfMeals)
{
  int row, col;
  getmaxyx(stdscr, row, col);

  for (auto i = 0; i < numberOfMeals; ++i)
  {
    printMtx->lock();
    move(id, 0);
    clrtoeol();
    mvprintw(id, 0, "%s %d: %s", "Philosopher", id, "Glodny");
    refresh();
    printMtx->unlock();

    eatMeal();

    printMtx->lock();
    move(id, 0);
    clrtoeol();
    mvprintw(id, 0, "%s %d: %s", "Philosopher", id, "Mysli");
    refresh();
    printMtx->unlock();

    std::this_thread::sleep_for(std::chrono::milliseconds(randomGenerator()));
  }

  return 0;
}

int Philosopher::eatMeal()
{
  int row, col;
  getmaxyx(stdscr, row, col);

  leftFork->startUsing();
  rightFork->startUsing();

  printMtx->lock();
  move(id, 0);
  clrtoeol();
  mvprintw(id, 0, "%s %d: %s", "Philosopher", id, "Je");
  refresh();
  printMtx->unlock();

  std::this_thread::sleep_for(std::chrono::milliseconds(randomGenerator()));

  leftFork->stopUsing();
  rightFork->stopUsing();

  return 0;
}

Philosopher::~Philosopher()
{
}
