#include "Elevator.h"
#include "Simulation.h"
#include <vector>
#include <iostream>

int main() {
    Elevator e(1, Direction::Up);
    Simulation s;
    std::vector<std::vector<Event>> scenario(50);
    scenario[12].push_back(Event(5,Event::Type::External));
    scenario[16].push_back(Event(8,Event::Type::Internal));
    scenario[23].push_back(Event(1,Event::Type::External));

    for (int t = 12; t <= 30; t++)
    {
       std::vector<Event> events = scenario[t];
       std::cout<<"iteration"<<t<<std::endl;
       s.step(events,e);
       std::cout<<"t="<<t
            <<"floor:"<<e.getFloor()
            <<"dir"<<(e.getDirection() == Direction::Up ? "Up" : (e.getDirection() == Direction::Down ?"Down":"Stay"))
            << std::endl;
    }
    
}