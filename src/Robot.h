/* 
 * File:   Robot.h
 * Author: cjoffro2
 *
 * Created on 26 novembre 2013, 13:30
 */

#ifndef ROBOT_H
#define	ROBOT_H

#include <vector>
#include "Error.h"
#include "Coordinates.h"
#include "Direction.h"
#include "RoadBook.h"
#include "RoadBookCalculator.h"
#include "LandSensor.h"
#include "MapTools.h"
//#include "Battery.h"

class Robot {
public:
    Robot();
    //Robot(double, Battery*);
    ~Robot();
    void land(Coordinates* landPosition, LandSensor* sensor);
    int getXposition() throw (int);
    int getYposition() throw (int);
    Direction::Directions getDirection() throw (int);
    void moveForward() throw (int);
    void moveBackward() throw (int);
    void moveTo(Coordinates* nextPosition) throw (int);
    void turnLeft() throw (int);
    void turnRight() throw (int);
    void setRoadBook(RoadBook* rb);
    void letsGo() throw (int);
    void computeRoadTo(Coordinates* destination) throw (int);
private:
    Coordinates* position;
    Direction::Directions direction;
    bool isLanded;
    RoadBook* roadBook = NULL;
    double energyConsumption;
    LandSensor* landSensor;
    //Battery* cells;
};

#endif	/* ROBOT_H */

