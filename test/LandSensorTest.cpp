/*
 * File:   LandSensorTest.cpp
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:34
 */

#include "LandSensorTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(LandSensorTest);

LandSensorTest::LandSensorTest() {
}

LandSensorTest::~LandSensorTest() {
}

void LandSensorTest::setUp() {
  c1 = new Coordinates(0, 0);
  c2 = new Coordinates(0, 1);
  c3 = new Coordinates(1, 0);
  l = new LandSensor();
}

void LandSensorTest::tearDown() {
}

void LandSensorTest::getPointToPointEnergyCoefficientTest_1() {
  CPPUNIT_ASSERT(l->getPointToPointEnergyCoefficient(c1, c2) == 1.0);
}

void LandSensorTest::getPointToPointEnergyCoefficientTest_2() {
  double r1 = l->getPointToPointEnergyCoefficient(c1, c2);
  CPPUNIT_ASSERT(l->getPointToPointEnergyCoefficient(c1, c3) == r1);
}

void LandSensorTest::getPointToPointEnergyCoefficientTest_3() {
  double r1 = l->getPointToPointEnergyCoefficient(c1, c2);
  CPPUNIT_ASSERT(l->getPointToPointEnergyCoefficient(c3, c2) == r1);
}

void LandSensorTest::getPointToPointEnergyCoefficientTest_4() {
  double r1 = l->getPointToPointEnergyCoefficient(c1, c2);
  CPPUNIT_ASSERT(l->getPointToPointEnergyCoefficient(c1, c2) == r1);
}
