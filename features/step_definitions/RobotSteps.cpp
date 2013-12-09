#include <gtest/gtest.h>
#include <cucumber-cpp/defs.hpp>

#include "Robot.h"

using cucumber::ScenarioScope;

struct RobotCtx {
  Robot* robot;
  int x_result;
  int y_result;
};

GIVEN("^I have land the robot in X : (\\d+), Y : (\\d+) on the planet$") {
    REGEX_PARAM(int, x);
    REGEX_PARAM(int, y);
    ScenarioScope<RobotCtx> context;
    context->robot = new Robot(1.0, new Battery());
    context->robot->land(new Coordinates(x, y), new LandSensor(4));
}

WHEN("^I press moveForward") {
    ScenarioScope<RobotCtx> context;

    context->robot->moveForward();   
}

WHEN("^I press moveBackward") {
    ScenarioScope<RobotCtx> context;

    context->robot->moveBackward();   
}
WHEN("^I press turnLeft") {
    ScenarioScope<RobotCtx> context;

    context->robot->turnLeft();   
}
WHEN("^I press turnRight") {
    ScenarioScope<RobotCtx> context;

    context->robot->turnRight();   
}



THEN("^the robot is in X : (.*), Y : (.*)$") {
    REGEX_PARAM(int, expected_x);
    REGEX_PARAM(int, expected_y);

    ScenarioScope<RobotCtx> context;
    context->x_result = context->robot->getXposition();
    context->y_result = context->robot->getYposition();

    EXPECT_EQ(expected_x, context->x_result);
    EXPECT_EQ(expected_y, context->y_result);
}
