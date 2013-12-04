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
  CPPUNIT_ASSERT_EQUAL(Land::ROCHE, Land::getLandByOrdinal(1));
  CPPUNIT_ASSERT_EQUAL(Land::SABLE, Land::getLandByOrdinal(2));
  CPPUNIT_ASSERT_EQUAL(Land::BOUE, Land::getLandByOrdinal(3));
  CPPUNIT_ASSERT_EQUAL(Land::INFRANCHISSABLE, Land::getLandByOrdinal(4));
}

void LandTest::getLandByOrdinalTest_Exception() {
  CPPUNIT_ASSERT_THROW(Land::getLandByOrdinal(5), int);
}

void LandTest::countLandTest() {
  CPPUNIT_ASSERT_EQUAL(5, Land::countLand());
}
