/* 
 * File:   LandSensor.cpp
 * Author: cjoffro2
 * 
 * Created on 27 novembre 2013, 14:03
 */

#include "LandSensor.h"

LandSensor::LandSensor() {
}


LandSensor::~LandSensor() {
}

double LandSensor::getPointToPointEnergyCoefficient(Coordinates coordinate1, Coordinates coordinate2) {
        double dist;
        double r;
	dist = distance(coordinate1, coordinate2);
        //return 1.0;
	r = ((double) rand() / (RAND_MAX));
        return 1 + dist / (dist * r);
    }

double LandSensor::distance(Coordinates coordinate1, Coordinates coordinate2) {
        return sqrt(pow(coordinate1.getX() - coordinate2.getX(), 2) + pow(coordinate1.getY() - coordinate2.getY(),2));
    }
