#include <gtest/gtest.h>
#include <cucumber-cpp/defs.hpp>

#include "Robot.h"
#include <vector>
#include <string>
#include <iostream>
using cucumber::ScenarioScope;

struct RobotCtx {
  Robot* robot;
  int x_result;
  int y_result;
  int error;
  std::vector<std::string>* landingMap;
  std::vector<std::string>* manualMap;
};

GIVEN("^I have land the robot in X : (\\d+), Y : (\\d+) on the planet$") {
    REGEX_PARAM(int, x);
    REGEX_PARAM(int, y);
    ScenarioScope<RobotCtx> context;
    context->robot = new Robot(1.0, new Battery());
    context->robot->land(new Coordinates(x, y), new LandSensor(4));
    context->landingMap = context->robot->displayCarte();
}

GIVEN("^a robot flying$") {
    ScenarioScope<RobotCtx> context;
    context->robot = new Robot(1.0, new Battery());
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
WHEN("^I press cartographier") {
    ScenarioScope<RobotCtx> context;
    try{
      context->robot->cartographier();         
      context->manualMap = context->robot->displayCarte();
    } catch (int e) {context->error = e;std::cout << "dans le catch" << std::endl;}
    
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

THEN("^we have the same map$"){
  ScenarioScope<RobotCtx> context;
  for(int i=0; i < context->landingMap->size(); i++){
    EXPECT_EQ(context->landingMap->at(i), context->manualMap->at(i));
  }
}

THEN("^I get the exception UNLANDED_ROBOT : (.*)$"){
  ScenarioScope<RobotCtx> context;
  REGEX_PARAM(int, expected_error);
  EXPECT_EQ(expected_error, context->error);
}
