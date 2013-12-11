#include <gtest/gtest.h>
#include <cucumber-cpp/defs.hpp>

#include "Robot.h"
#include "MyLandSensor.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using cucumber::ScenarioScope;

struct RobotCtx {
  Robot* robot;
  int x_result;
  int y_result;
  int error;
  std::vector<std::string>* landingMap;
  std::vector<std::string>* manualMap;
  MyLandSensor* myLand;
};

GIVEN("^I have land the robot in X : (-?\\d+), Y : (-?\\d+) on the planet$") {
    REGEX_PARAM(int, x);
    REGEX_PARAM(int, y);
    ScenarioScope<RobotCtx> context;
    context->robot = new Robot(1.0, new Battery());
    context->robot->land(new Coordinates(x, y), new MyLandSensor());
    context->landingMap = context->robot->displayCarte();
}

GIVEN("^a robot flying$") {
    ScenarioScope<RobotCtx> context;
    context->robot = new Robot(1.0, new Battery());
}

GIVEN("^A specific land$"){
    ScenarioScope<RobotCtx> context;
    context->myLand = new MyLandSensor();
}

GIVEN("^a coordinate X : (-?\\d+), Y : (-?\\d+) the land is (\\d+)$"){
    REGEX_PARAM(int, x);
    REGEX_PARAM(int, y);
    REGEX_PARAM(int, type);
    ScenarioScope<RobotCtx> context;
    context->myLand->setValue(new Coordinates(x,y),Land::getLandByOrdinal(type));
}

GIVEN("^a robot landed in X : (-?\\d+), Y : (-?\\d+) on the planet$"){
    REGEX_PARAM(int, x);
    REGEX_PARAM(int, y);
    ScenarioScope<RobotCtx> context;
    context->robot = new Robot(1.0, new Battery());
    context->robot->land(new Coordinates(x, y), context->myLand);
    context->landingMap = context->robot->displayCarte();
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

THEN("^I have (.*) lines$"){

}

THEN("^I have (.*) rows$"){
  ScenarioScope<RobotCtx> context;
  REGEX_PARAM(int, row);
  for(int i=2; i < context->landingMap->size()-1; i++){
    std::string line = context->manualMap->at(i);
    int n = 0;
    for (int j=0; j<line.size(); j++){
      if(line[j] == '|') {n++;}
    }
    EXPECT_EQ(row, n-1);
  }
}
