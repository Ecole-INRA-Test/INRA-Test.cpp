/* 
 * File:   LandSensor.h
 * Author: cjoffro2
 *
 * Created on 27 novembre 2013, 14:03
 */

#ifndef LANDSENSOR_H
#define	LANDSENSOR_H

#include <math.h>
#include <cstdlib>
#include <map>
#include "Coordinates.h"
#include "Land.h"
#include "Error.h"

class LandSensor {
public:
    LandSensor(int s=4);
    ~LandSensor();
    

    /*LandSensor(Random random) {
        this.random = random;
    }*/

    double getPointToPointEnergyCoefficient(Coordinates* coordinate1, Coordinates* coordinate2) throw (int);

    bool isAccessible(Coordinates* coordinate) throw (int);
private:
    //private Random random;
    Land::Lands lazyGet(Coordinates* coordinate1) throw (int);
    std::map<Coordinates*, Land::Lands> carte;
    int seed;
};

#endif	/* LANDSENSOR_H */

