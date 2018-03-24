#include <iostream>

#include "../include/Fork.hpp"


Fork::Fork(int id)
  : id(id)
{
}

int Fork::startUsing()
{
  std::cout << "Fork " << id << ": startUsing\n";
  return 0;
}

int Fork::stopUsing()
{
  std::cout << "Fork " << id << ": stopUsing\n";
  return 0;
}

Fork::~Fork()
{
}
