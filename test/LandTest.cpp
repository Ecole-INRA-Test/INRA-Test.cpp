/*
 * File:   LandTest.cpp
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:34
 */

#include "LandTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(LandTest);

LandTest::LandTest() {
}

LandTest::~LandTest() {
}

void LandTest::setUp() {
}

void LandTest::tearDown() {
}

void LandTest::getLandByOrdinalTest() {
  CPPUNIT_ASSERT_EQUAL(Land::TERRE, Land::getLandByOrdinal(0));
}

void LandTest::testFailedMethod() {
    CPPUNIT_ASSERT(true);
}

