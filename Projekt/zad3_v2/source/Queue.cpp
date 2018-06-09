#include <memory>

#include <Queue.hpp>
#include <Person.hpp>


Queue::Queue(const int initialNumberOfPeople)
{
  for(auto i = 0; i < initialNumberOfPeople; ++i)
  {
    people.push(std::make_shared<Person>());
  }
}

Queue::~Queue()
{
}
