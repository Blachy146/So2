#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <vector>
#include <memory>

#include <Elevator.hpp>
#include <Queue.hpp>

class Building
{
public:
    explicit Building(const int numberOfFloors);

    ~Building();
private:
    const int numberOfFloors;
    std::shared_ptr<Elevator> elevator;
    std::vector<std::shared_ptr<Queue>> floors;
};

#endif // BUILDING_HPP