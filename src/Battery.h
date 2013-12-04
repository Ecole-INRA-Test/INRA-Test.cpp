/* 
 * File:   Battery.h
 * Author: cjoffro2
 *
 * Created on 27 novembre 2013, 13:14
 */

#ifndef BATTERY_H
#define	BATTERY_H

#include "Error.h"
#include <ctime>

class Battery {
public:
    Battery();
    ~Battery();
    void setUp();
    void charge() ;
    float getChargeLevel();
    void use(double energy) throw(int);
    bool canDeliver(double neededEnergy);
    static const long CHARGE_TOP = 1000;
    static const long CHARGE_STEP = 10;
private:
    float chargeLevel;
    std::time_t chargeClock;
    float chargeFunction(float charge, double time);
};

#endif	/* BATTERY_H */

