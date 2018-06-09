#include <memory>
#include <mutex>
#include <condition_variable>

#include <Queue.hpp>
#include <Person.hpp>
#include <State.hpp>


Queue::Queue(const int initialNumberOfPeople, std::shared_ptr<State> state)
  : state(state)
{
  for(auto i = 0; i < initialNumberOfPeople; ++i)
  {
    people.push(std::make_shared<Person>());
  }
}

Queue::~Queue()
{
}
