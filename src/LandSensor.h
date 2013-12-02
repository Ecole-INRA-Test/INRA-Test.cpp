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
#include "Coordinates.h"

class LandSensor {
public:
    LandSensor();
    ~LandSensor();
    

    /*LandSensor(Random random) {
        this.random = random;
    }*/

    double getPointToPointEnergyCoefficient(Coordinates coordinate1, Coordinates coordinate2);

    double distance(Coordinates coordinate1, Coordinates coordinate2);
private:
    //private Random random;
};

#endif	/* LANDSENSOR_H */

