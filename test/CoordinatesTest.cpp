/*
 * File:   BatteryTest.cpp
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:34
 */

#include "CoordinatesTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(CoordinatesTest);

CoordinatesTest::CoordinatesTest() {
}

CoordinatesTest::~CoordinatesTest() {
}

void CoordinatesTest::setUp() {
  c = new Coordinates(10,5);
}

void CoordinatesTest::tearDown() {
}

void CoordinatesTest::testX() {
    CPPUNIT_ASSERT(false);
}

void CoordinatesTest::testY() {
    CPPUNIT_ASSERT(false);
}

void CoordinatesTest::testEquals(){
  CPPUNIT_ASSERT(false);
}
