/*
 * File:   MockLandSensor.h
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:33
 */

#ifndef MOCKLANDSENSOR_H
#define	MOCKLANDSENSOR_H

#include <gmock/gmock.h>
#include "../src/LandSensor.h"

class MockLandSensor : public LandSensor {
  
public:
    LandSensorTest();
    virtual ~LandSensorTest();
    void setUp();
    void tearDown();

private:
    Coordinates* c1;
    Coordinates* c2;
    Coordinates* c3;
    LandSensor* l;
    void getPointToPointEnergyCoefficientTest_1();
    void getPointToPointEnergyCoefficientTest_2();
    void getPointToPointEnergyCoefficientTest_3();
    void getPointToPointEnergyCoefficientTest_4();
};

#endif	/* MOCKLANDSENSOR_H */

