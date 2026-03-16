cmake_minimum_required(VERSION "4.2.3")

project(ElevatorApp)
set(CMAKE_CXX_STANDART 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_PREFIX_PATH "/mysys64/ucrt64")

add_library(elevator_lib 
    src/Elevator.cpp
    src/Simulation.cpp
)
target_include_directories(elevator_lib
    PUBLIC include)
add_executable(ElevatorApp
    src/main.cpp
    src/Elevator.cpp
    src/Simulation.cpp
    include/Elevator.h
    include/Simulation.h
)


enable_testing()



add_subdirectory(external/googletest)
add_subdirectory(tests)

target_link_libraries(ElevatorApp PRIVATE elevator_lib)