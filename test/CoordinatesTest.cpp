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
    CPPUNIT_ASSERT(c->getX() == 10);
}

void CoordinatesTest::testY() {
    CPPUNIT_ASSERT(c->getY() == 5);
}

void CoordinatesTest::testEquals(){
  Coordinates* c1 = new Coordinates(0, 0);
  Coordinates* c2 = new Coordinates(0, 0);
  CPPUNIT_ASSERT(c1 < c2);
}
