/*
 * File:   BatteryTest.cpp
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:34
 */

#include "BatteryTest.h"
 
CPPUNIT_TEST_SUITE_REGISTRATION(BatteryTest);

BatteryTest::BatteryTest() {
}

BatteryTest::~BatteryTest() {
}

void BatteryTest::setUp() {
  b = new Battery();
}

void BatteryTest::tearDown() {
}

void BatteryTest::getChargeLevelTest() {
  b->use(25.0);
  std::time_t temp = std::time(NULL);
  while(std::difftime(std::time(NULL), temp) <= 1){}  
  CPPUNIT_ASSERT(b->getChargeLevel() > 75.0);

  b = new Battery();
  
}

void BatteryTest::testFailedMethod() {
    CPPUNIT_ASSERT(true);
}

