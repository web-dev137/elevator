#include "Elevator.h"
#include "Simulation.h"
#include <vector>
#include <iostream>

int main() {
    Elevator e;
    Simulation s;
    std::vector<std::vector<Event>> scenario(50);
    scenario[1].push_back(Event(5,Event::Type::External));
    scenario[6].push_back(Event(1,Event::Type::Internal));
    scenario[7].push_back(Event(9,Event::Type::External));

    for (int i = 1; i <= 20; i++)
    {
       std::vector<Event> events = scenario[i];
       s.step(events,e);
       std::cout<<"Iteration:"<<i<<std::endl
            <<"Floor:"<<e.getFloor()<<std::endl
            <<"Direction:"<<(e.getDirection() == Direction::Up ? "Up" : (e.getDirection() == Direction::Down ?"Down":"Stay"))
            << std::endl;
        std::cout<<"---------------"<<std::endl;      
    }
    
}