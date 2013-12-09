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
    virtual ~Battery();
    void setUp();
    void charge() ;
    virtual double getChargeLevel();
    void use(double energy) throw(int);
    bool canDeliver(double neededEnergy);
    static const long CHARGE_TOP = 1000;
    static const long CHARGE_STEP = 10;
private:
    double chargeLevel;
    std::time_t chargeClock;
    double chargeFunction(double charge, double time);
};

#endif	/* BATTERY_H */

