#include <gtest/gtest.h>
#include <Elevator.h>
#include <Simulation.h>
#include <memory>

class ElevatorTest : public ::testing::Test{
protected:
    Elevator e;
    Simulation s;
    std::vector<Event> requests;
    void SetUp() override {
    }

    std::set<int> floorsFromEvents() {
        std::set<int> floors;
        for(const auto& e : requests) {
            floors.insert(e.floor);
        }
        return floors;
    }
};

TEST_F(ElevatorTest,MoveDownNoRequest) {
    e = Elevator(2,Direction::Down);

    s.step(requests,e);
    EXPECT_EQ(e.getFloor(), 1);
    EXPECT_EQ(e.getDirection(), Direction::Stay);
    EXPECT_TRUE(e.getInternal().empty());
}

TEST_F(ElevatorTest,RequestInOtherDirectionBeforeArrival) {
    e = Elevator(2,Direction::Down);
    requests.push_back({5,Event::Type::External});
    std::set<int> sRequests = floorsFromEvents();
    s.step(requests,e);
    EXPECT_EQ(e.getFloor(),1);
    EXPECT_EQ(e.getDirection(),Direction::Up);
    EXPECT_EQ(e.getExternal(),sRequests);
}

TEST_F(ElevatorTest,RequestAboveAndBelow) {
    e = Elevator(3,Direction::Down);
    requests.push_back({1,Event::Type::External});
    requests.push_back({5,Event::Type::External});
    std::set<int> sRequests = floorsFromEvents();
    s.step(requests,e);
    EXPECT_EQ(e.getFloor(),2);
    EXPECT_EQ(e.getDirection(),Direction::Down);
    EXPECT_EQ(e.getExternal(),sRequests);
}

TEST_F(ElevatorTest,CorrectStay) {
    e = Elevator(3,Direction::Stay);
    requests.push_back({7,Event::Type::External});
    s.step(requests,e);
    EXPECT_EQ(e.getFloor(), 4);
    EXPECT_EQ(e.getDirection(), Direction::Up);
    EXPECT_TRUE(e.getExternal().empty());
}

TEST_F(ElevatorTest,ClearRequestOnCurrentFloor) {
    e = Elevator(4,Direction::Up);
    requests.push_back({4,Event::Type::External});
    requests.push_back({7,Event::Type::External});
    std::set<int> sRequests = {7};

    s.step(requests,e);
    EXPECT_EQ(e.getFloor(),5);
    EXPECT_EQ(e.getDirection(),Direction::Up);
    EXPECT_EQ(e.getExternal(),sRequests);
}

TEST_F(ElevatorTest,Bug_DownOnFirstFloor) {
    e = Elevator(2,Direction::Down);
    std::set<int> sRequests = {};
    s.step(requests,e);
    EXPECT_EQ(e.getFloor(),1);
    EXPECT_EQ(e.getDirection(),Direction::Stay);
    EXPECT_EQ(e.getExternal(),sRequests);
}