
#include <RandomGenerator.hpp>


RandomGenerator::RandomGenerator(int lower, int upper)
  : engine(std::random_device{}()), distribution(lower, upper)
{
}

int RandomGenerator::operator()()
{
  return distribution(engine);
}

RandomGenerator::~RandomGenerator()
{
}
