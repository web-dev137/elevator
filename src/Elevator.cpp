#include "Elevator.h"

void Elevator::move() {
    switch (direction)
    {
    case Direction::Up:
        currentFloor++;
        if(currentFloor > maxFloor) {
            currentFloor = maxFloor;
            direction = Direction::Stay;
        }
        break;
    case Direction::Down:
        currentFloor--;
        if(currentFloor < minFloor) {
            currentFloor = minFloor;
            direction = Direction::Stay;
        }
    default:
        //std::cerr<<"floor stay:";
        break;
    }
}

void Elevator::applyEvents(const std::vector<Event>& events) {
    for (const auto& e : events) {
        switch (e.type){
        case Event::Type::External:
            external.insert(e.floor);
            break;
        case Event::Type::Internal:
            internal.insert(e.floor);
        default:
            break;
        };
    }
    
}

void Elevator::setDirection(Direction newDir) {
    direction = newDir;
}

void Elevator::clearRequestsNotActual() {
    external.erase(currentFloor);
    internal.erase(currentFloor);
}

bool Elevator::hasRequestAbove(const std::set<int>& requests) {
    auto request = requests.upper_bound(currentFloor);
    return request != requests.end();
}

bool Elevator::hasRequestBellow(const std::set<int>& requests) {
    return !requests.empty() && *requests.begin() < currentFloor;
}

Direction Elevator::choiceDirection() {
    bool above = hasRequestAbove(external) || hasRequestAbove(internal);
    bool below = hasRequestBellow(external) || hasRequestBellow(internal);
    switch (direction)
    {
    case Direction::Up:
        return above? Direction::Up : below ?Direction::Down : Direction::Stay;
        break;
    case Direction::Down:
        return below? Direction::Down : above ?Direction::Up : Direction::Stay;
    case Direction::Stay:   
    default:
        return above? Direction::Up : below ?Direction::Down : Direction::Stay;
        break;
    }
}

int Elevator::getFloor() {
    return currentFloor;
}

std::set<int> Elevator::getExternal() {
    return external;
}

std::set<int> Elevator::getInternal() {
    return internal;
}

Direction Elevator::getDirection() {
    return direction;
}