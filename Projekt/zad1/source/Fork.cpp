#include <iostream>
#include <ncurses.h>

#include "../include/Fork.hpp"


Fork::Fork(int id, std::shared_ptr<std::mutex> printMtx)
  : id(id), printMtx(printMtx)
{
}

int Fork::startUsing()
{
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

  return 0;
}

Fork::~Fork()
{
}
