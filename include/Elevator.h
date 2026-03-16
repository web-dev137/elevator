#pragma once
#include <set>
#include <vector>

enum class Direction {
    Up,
    Down,
    Stay
};


struct Event
{
    enum class Type {External, Internal} type;
    int floor;
    //Event():floor(1),type(Type::External){};
    Event(int f, Type t):floor(f),type(t){};
};


class Elevator
{
private:
    int currentFloor;
    std::set<int> external;
    std::set<int> internal;
    Direction direction;
    bool hasRequestAbove(const std::set<int>& requests);
    bool hasRequestBellow(const std::set<int>& requests);
public:
    static constexpr int minFloor = 1;
    static constexpr int maxFloor = 9;

    Elevator(int startFloor, Direction startDirection)
    :currentFloor(startFloor), direction(startDirection) {}
    Elevator():currentFloor(1),direction(Direction::Stay){};
    ~Elevator(){};
    void move();
    void applyEvents(const std::vector<Event>& events);
    void clearRequestsNotActual();
    Direction choiceDirection();
    void setDirection(Direction newDir);
    int getFloor();
    std::set<int> getExternal();
    std::set<int> getInternal();
    Direction getDirection();
};
