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
#include "Battery.h"


class Robot {
public:
//    Robot();
   Robot(double energy, Battery* batt, Coordinates* c);
    ~Robot();
    int getXposition() throw (int);
    int getYposition() throw (int);
    void moveForward() throw (int);
    void moveBackward() throw (int);
private:
    Coordinates* position;
    bool isLanded;
    double energyConsumption;
    Battery* cells;
};

#endif	/* ROBOT_H */

