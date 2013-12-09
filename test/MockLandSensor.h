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

#include "../src/Error.h"
#include "../src/LandSensor.h"
#include "../src/Coordinates.h"
#include "FakeLandSensor.h"
using ::testing::_;
using ::testing::Invoke;


class MockLandSensor : public LandSensor {
public:
   
  MOCK_METHOD1(mockIsAccessible, bool(Coordinates* coordinate));
  virtual bool isAccessible(Coordinates* coordinate) throw (int){
     return mockIsAccessible(coordinate);
  }
  void DelegateToFake() {
    ON_CALL(*this, mockIsAccessible(_)).WillByDefault(Invoke(&fake_, &FakeLandSensor::isAccessible));
  } 
private:
  FakeLandSensor fake_;
};

#endif	/* MOCKLANDSENSOR */

