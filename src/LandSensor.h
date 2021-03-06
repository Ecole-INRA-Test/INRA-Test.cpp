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
#include <vector>
#include <string>
#include <sstream>
#include "Coordinates.h"
#include "Land.h"
#include "Error.h"

class LandSensor {
public:
    LandSensor(int s=4);
    virtual ~LandSensor();
    

    /*LandSensor(Random random) {
        this.random = random;
    }*/

    double getPointToPointEnergyCoefficient(Coordinates* coordinate1, Coordinates* coordinate2) throw (int);

    virtual bool isAccessible(Coordinates* coordinate) throw (int);

    void cartographier(Coordinates* landPosition) throw (int);

    Coordinates* getTop();
    int getXBottom();

    std::vector<std::string>* displayCarte();
protected:
    std::map<Coordinates*, Land::Lands> carte;
    Land::Lands lazyGet(Coordinates* coordinate1) throw (int);
//private:
    //private Random random;
    
    //std::map<Coordinates*, Land::Lands> carte;
    int seed;
    int PORTEE;
    Coordinates* boxTop;
    Coordinates* boxBottom;
};

#endif	/* LANDSENSOR_H */

