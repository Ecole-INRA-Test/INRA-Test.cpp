/* 
 * File:   MockBattery.h
 * Author: pepi2013
 *
 * Created on 27 novembre 2013, 13:14
 */

#ifndef MOCKLANDSENSOR
#define	MOCKLANDSENSOR

#include <gmock/gmock.h>
#include <ctime>
#include <iostream>
#include "../src/Error.h"
#include "../src/LandSensor.h"
#include "../src/Coordinates.h"
#include "FakeLandSensor.h"
using ::testing::_;
using ::testing::Invoke;


class MockLandSensor : public LandSensor {
public:
   
  MOCK_METHOD1(mockIsAccessible, bool(Coordinates* coordinate));
  MOCK_METHOD2(mockGetPointToPointEnergyCoefficient, double(Coordinates* coordinate1, Coordinates* coordinate2));
  virtual bool isAccessible(Coordinates* coordinate) throw (int){
     return mockIsAccessible(coordinate);
  }
  virtual double getPointToPointEnergyCoefficient(Coordinates* coordinate1, Coordinates* coordinate2) throw (int){
     return mockGetPointToPointEnergyCoefficient(coordinate1, coordinate2);
  }

  void DelegateToFake() {
    ON_CALL(*this, mockIsAccessible(_)).WillByDefault(Invoke(&fake_, &FakeLandSensor::isAccessible));
  } 
private:
  FakeLandSensor fake_;
};

#endif	/* MOCKLANDSENSOR */

