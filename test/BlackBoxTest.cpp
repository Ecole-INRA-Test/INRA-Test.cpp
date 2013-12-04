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

void BlackBoxTest::addCheckPointTest_1(){
  Coordinates* c = new Coordinates(0, 1);
  CheckPoint* oracle = new CheckPoint(c, Direction::NORTH, true);
  b->addCheckPoint(c, Direction::NORTH, true);

  CPPUNIT_ASSERT_EQUAL(oracle->getPosition(), b->getCheckPointList()->front()->getPosition());
  CPPUNIT_ASSERT_EQUAL(oracle->getDirection(), b->getCheckPointList()->front()->getDirection());
  CPPUNIT_ASSERT_EQUAL(oracle->getManualDirective(), b->getCheckPointList()->front()->getManualDirective());
}

void BlackBoxTest::addCheckPointTest_2(){
  Coordinates* c = new Coordinates(0, 1);
  CheckPoint* oracle = new CheckPoint(c, Direction::NORTH, true);
  b->addCheckPoint(oracle);

  CPPUNIT_ASSERT_EQUAL(oracle->getPosition(), b->getCheckPointList()->front()->getPosition());
  CPPUNIT_ASSERT_EQUAL(oracle->getDirection(), b->getCheckPointList()->front()->getDirection());
  CPPUNIT_ASSERT_EQUAL(oracle->getManualDirective(), b->getCheckPointList()->front()->getManualDirective());
}
