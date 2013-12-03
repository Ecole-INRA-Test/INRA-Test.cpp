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

double LandSensor::getPointToPointEnergyCoefficient(Coordinates* coordinate1, Coordinates* coordinate2, int seed) throw (int){
	srand(seed);
	if(carte.find(coordinate1) == carte.end()){
		try{
		carte[coordinate1] = Land::getLandByOrdinal(rand()%5);
		} catch(int e) {
		throw ERROR_LANDSENSOR_FAIL;
		}
	}
	if(carte.find(coordinate2) == carte.end()){
		try{
		carte[coordinate2] = Land::getLandByOrdinal(rand()%5);
		} catch(int e) {
		throw ERROR_LANDSENSOR_FAIL;
		}
	}
	Land::Lands terrain1 = carte.find(coordinate1)->second;
	Land::Lands terrain2 = carte.find(coordinate2)->second;
	if (terrain1 == Land::INFRANCHISSABLE || terrain2 == Land::INFRANCHISSABLE)
		throw ERROR_COORDINATES_INACCESSIBLE;
	double result = (terrain1 + terrain2) / 2.0;
	return result;
    }
