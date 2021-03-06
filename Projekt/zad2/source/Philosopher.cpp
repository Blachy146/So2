#include <iostream>
#include <chrono>
#include <thread>
#include <ncurses.h>
#include <condition_variable>
#include <mutex>

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
    mvprintw(id, 0, "%s %d: %s\t|\t[Fork %d, Fork %d]", "Philosopher", id, "Glodny", leftFork->getId(), rightFork->getId());
    refresh();
    printMtx->unlock();

    eatMeal();

    printMtx->lock();
    move(id, 0);
    clrtoeol();
    mvprintw(id, 0, "%s %d: %s\t|\t[Fork %d, Fork %d]", "Philosopher", id, "Mysli", leftFork->getId(), rightFork->getId());
    refresh();
    printMtx->unlock();

    std::this_thread::sleep_for(std::chrono::milliseconds(randomGenerator()));
  }

  return 0;
}

int Philosopher::eatMeal()
{
  std::condition_variable leftForkCondVariable;
  std::condition_variable rightForkCondVariable;

  {
    std::lock(leftFork->mtx, rightFork->mtx);
    std::unique_lock<std::mutex> leftLock(leftFork->mtx, std::adopt_lock);
    std::unique_lock<std::mutex> rightLock(rightFork->mtx, std::adopt_lock);

    leftForkCondVariable.wait(leftLock, [&]() { return leftFork->isReady(); });
    rightForkCondVariable.wait(rightLock, [&]() { return rightFork->isReady(); });

    int row, col;
    getmaxyx(stdscr, row, col);

    leftFork->startUsing();
    rightFork->startUsing();

    printMtx->lock();
    move(id, 0);
    clrtoeol();
    mvprintw(id, 0, "%s %d: %s\t|\t[Fork %d, Fork %d]", "Philosopher", id, "Je", leftFork->getId(), rightFork->getId());
    refresh();
    printMtx->unlock();

    std::this_thread::sleep_for(std::chrono::milliseconds(randomGenerator()));

    leftFork->stopUsing();
    rightFork->stopUsing();
  }

  leftForkCondVariable.notify_one();
  rightForkCondVariable.notify_one();


  return 0;
}

Philosopher::~Philosopher()
{
}
