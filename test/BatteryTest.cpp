/*
 * File:   BatteryTest.cpp
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:34
 */

#include "BatteryTest.h"

using ::testing::Return;
 
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
  CPPUNIT_ASSERT_EQUAL((double)100.0, b->getChargeLevel());
}

void BatteryTest::useTest(){
  b->use(25.0);
  CPPUNIT_ASSERT_EQUAL((double)75.0, b->getChargeLevel());
  CPPUNIT_ASSERT_THROW(b->use(80.0), int);
}

void BatteryTest::chargeLevelTestMock(){
  MockBattery* m = new MockBattery();
  ON_CALL (*m, getChargeLevel()).WillByDefault(Return(95.0));
  CPPUNIT_ASSERT_EQUAL(95.0, m->getChargeLevel());
  delete(m);
}


void BatteryTest::canDeliverTest(){
  b->use(25.0);
  CPPUNIT_ASSERT(b->canDeliver(74.0));
  CPPUNIT_ASSERT(!b->canDeliver(76.0));
}
