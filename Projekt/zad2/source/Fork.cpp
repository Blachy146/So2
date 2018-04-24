#include <iostream>
#include <ncurses.h>
#include <thread>

#include "../include/Fork.hpp"
#include "../include/RandomGenerator.hpp"


Fork::Fork(int id, std::shared_ptr<std::mutex> printMtx)
  : id(id), printMtx(printMtx), ready(true)
{
}

bool Fork::isReady() const
{
  return ready;
}

int Fork::startUsing()
{
  ready = false;

  int row, col;
  getmaxyx(stdscr, row, col);

  printMtx->lock();
  move(id+7, 0);
  clrtoeol();
  mvprintw(id+7, 0, "%s %d: %s", "Fork", id, "W uzyciu");
  refresh();
  printMtx->unlock();

  return 0;
}

int Fork::stopUsing()
{
  int row, col;
  getmaxyx(stdscr, row, col);

  printMtx->lock();
  move(id+7, 0);
  clrtoeol();
  mvprintw(id+7, 0, "%s %d: %s", "Fork", id, "Oczekiwanie na uzycie");
  refresh();
  printMtx->unlock();
  ready = true;

  return 0;
}

int Fork::getId()
{
  return id;
}

Fork::~Fork()
{
}
