# Elevator Simulation

## Elevator Operation Model

The elevator simulation follows these rules:

- The elevator starts at **floor 1** with the default state **"stay"** if no starting floor or direction is specified.
- It removes irrelevant requests (calls that are no longer valid based on the current direction and position).
- The elevator moves to the next floor according to its current direction.
- If the state was "stay", the elevator stops and processes requests on the current floor.
- Direction selection logic:
  - If there are pending requests in the **current direction**, the elevator continues moving in that direction.
  - If there are no requests in the current direction, it **switches to the opposite direction**.
  - If there are no requests at all, the elevator stops.
- The elevator always stops when it reaches the **first floor** or the **top floor** (last floor).
This logic ensures efficient handling of both internal (from inside the elevator) and external (floor calls) requests while preventing unnecessary movement

# Model demonstration example
![Alt text](docs/Elevator_rise_from1_to_5_floor.png)


# Build
mkdir build
cd build
cmake ..
make

# Run
./build/ElevatorApp.exe

# Run tests
```bash
cd build/tests
./tests.exe
```
or

```bash
cd build
ctest
```
# Requirements
C++ 17
CMake 4.2.3
gtest
