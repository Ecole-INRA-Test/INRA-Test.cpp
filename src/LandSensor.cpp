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

double LandSensor::getPointToPointEnergyCoefficient(Coordinates* coordinate1, Coordinates* coordinate2) throw (int){
	if(carte.find(coordinate1) == carte.end()){
		carte[coordinate1] = Land::getLandByOrdinal(0);
	}
	if(carte.find(coordinate2) == carte.end()){
		carte[coordinate2] = Land::getLandByOrdinal(0);
	}
	Land::Lands terrain1 = carte.find(coordinate1)->second;
	Land::Lands terrain2 = carte.find(coordinate2)->second;

	double result = (terrain1 + terrain2) / 2.0;
	return result;
    }
