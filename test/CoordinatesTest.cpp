/*
 * File:   BatteryTest.cpp
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:34
 */

#include "CoordinatesTest.h"
#include "../src/Coordinates.h"

CPPUNIT_TEST_SUITE_REGISTRATION(CoordinatesTest);

CoordinatesTest::CoordinatesTest() {
}

CoordinatesTest::~CoordinatesTest() {
}

void CoordinatesTest::setUp() {
}

void CoordinatesTest::tearDown() {
}

void CoordinatesTest::testXY() {
    Coordinates* c = new Coordinates(10,5);
    CPPUNIT_ASSERT(c->getX() == 10);
    CPPUNIT_ASSERT(c->getY() == 5);
}
