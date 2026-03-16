cmake_minimum_required(VERSION "4.2.3")
set(CMAKE_CXX_STANDART 17)

add_executable(tests
    ElevatorTest.cpp
)


target_link_libraries(tests
    PRIVATE
    gtest_main
)

target_link_libraries(tests PRIVATE elevator_lib)
include(GoogleTest)

add_test(NAME tests COMMAND tests)

gtest_discover_tests(tests)