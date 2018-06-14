#include <iostream>
#include <ncurses.h>

#include <Building.hpp>


int main()
{
  initscr();

  const int numberOfFloors = 4;
  const int elevatorCapacity = 4;
  const int numberOfPeoplePerFloor = 4;

  Building building(numberOfFloors, elevatorCapacity, numberOfPeoplePerFloor);

  building.run();

  endwin();
}
