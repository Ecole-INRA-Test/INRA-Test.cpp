/* 
 * File:   Robot.h
 * Author: cjoffro2
 *
 * Created on 26 novembre 2013, 13:30
 */

#ifndef ROBOT_H
#define	ROBOT_H

#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Error.h"
#include "Coordinates.h"
#include "Direction.h"
#include "RoadBook.h"
#include "RoadBookCalculator.h"
#include "LandSensor.h"
#include "MapTools.h"
#include "Battery.h"
#include "BlackBox.h"
#include "CheckPoint.h"

class Robot {
public:
//    Robot();
    Robot(double energy, Battery* batt);
    ~Robot();
    void land(Coordinates* landPosition, LandSensor* sensor) throw(int);
    int getXposition() throw (int);
    int getYposition() throw (int);
    Direction::Directions getDirection() throw (int);
    void moveForward() throw (int);
    void moveBackward() throw (int);
    void moveTo(Coordinates* nextPosition) throw (int);
    void turnLeft() throw (int);
    void turnRight() throw (int);
    void turnTo(Direction::Directions newDirection) throw (int);
    void setRoadBook(RoadBook* rb);
    std::vector<CheckPoint*>* letsGo() throw (int);
    void computeRoadTo(Coordinates* destination) throw (int);
    void cartographier() throw (int);
    std::vector<std::string>* displayCarte();
    BlackBox* blackbox;
private:
    Coordinates* position;
    Direction::Directions direction;
    bool isLanded;
    RoadBook* roadBook = NULL;
    double energyConsumption;
    LandSensor* landSensor;
    Battery* cells;
};

#endif	/* ROBOT_H */

