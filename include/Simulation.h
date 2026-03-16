#include "Elevator.h"

class Simulation
{
private:
    /* data */
public:
    Simulation(){};
    ~Simulation(){};
    void step(std::vector<Event> requests, Elevator& elevator);
    void validate(Elevator elevator);
};


