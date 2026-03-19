#include "Simulation.h"
#include <stdexcept>

void Simulation::step(std::vector<Event> requests, Elevator& elevator) {
    elevator.applyEvents(requests);
    elevator.clearRequestsNotActual();
    elevator.move();
    Direction dir = elevator.choiceDirection();
    elevator.setDirection(dir);
    validate(elevator);
}

void Simulation::validate(Elevator elevator) {
    int floor = elevator.getFloor();
    Direction direction = elevator.getDirection();
    if(floor == Elevator::maxFloor && direction == Direction::Up) {
        throw std::logic_error("you reach last floor");
    }

    if(floor == Elevator::minFloor && direction == Direction::Down) {
        throw std::logic_error("The elevator is trying to go below the minimum floor.");
    }
}