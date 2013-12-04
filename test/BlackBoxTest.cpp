/*
 * File:   BlackBoxTest.cpp
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:34
 */

#include "BlackBoxTest.h"
 
CPPUNIT_TEST_SUITE_REGISTRATION(BlackBoxTest);

BlackBoxTest::BlackBoxTest() {
}

BlackBoxTest::~BlackBoxTest() {
}

void BlackBoxTest::setUp() {
  b = new BlackBox();
}

void BlackBoxTest::tearDown() {
}

void BlackBoxTest::getChargeLevelTest() {
  CPPUNIT_ASSERT(true);
}

void BlackBoxTest::useTest(){
  CPPUNIT_ASSERT(true);
}

void BlackBoxTest::canDeliverTest(){
  CPPUNIT_ASSERT(true);
}

