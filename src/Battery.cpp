/* 
 * File:   Battery.cpp
 * Author: cjoffro2
 * 
 * Created on 27 novembre 2013, 13:14
 */

#include "Battery.h"

Battery::Battery() {
    chargeLevel = 100;
    setUp();
}

Battery::~Battery() {
}

void Battery::setUp(){
	chargeClock = std::time(NULL);	
}


float Battery::chargeFunction(float charge, double time) {
        return charge+CHARGE_STEP*time/CHARGE_TOP;
}

void Battery::charge() {
	std::time_t lastChargeClock = chargeClock;
	float tmpCharge;
	chargeClock = std::time(NULL);
	tmpCharge = chargeFunction(chargeLevel, std::difftime(chargeClock, lastChargeClock));
	if (tmpCharge < 100) chargeLevel = tmpCharge;
	else chargeLevel = 100;
    }

float Battery::getChargeLevel(){
	charge();
        return chargeLevel;
    }

void Battery::use(double energy) throw (int){
	charge();
        if (chargeLevel < energy) throw ERROR_INSUFFICIENT_CHARGE;
        chargeLevel -= energy;
    }

bool Battery::canDeliver(double neededEnergy){
	charge();
	return (chargeLevel >= neededEnergy);
}
