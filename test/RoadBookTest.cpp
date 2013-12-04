/*
 * File:   RoadBookTest.cpp
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:34
 */

#include "RoadBookTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(RoadBookTest);

RoadBookTest::RoadBookTest() {
}

RoadBookTest::~RoadBookTest() {
}

void RoadBookTest::setUp() {
  instrList = new std::vector<Instruction>();
}

void RoadBookTest::tearDown() {
}

void RoadBookTest::hasInstructionTest() {
  r = new RoadBook(instrList);
  CPPUNIT_ASSERT(!r->hasInstruction());

  instrList->push_back(TURNLEFT);
  r = new RoadBook(instrList);
  CPPUNIT_ASSERT(r->hasInstruction());
  
}

void RoadBookTest::nextTest() {
  instrList->push_back(TURNLEFT);
  r = new RoadBook(instrList);

  CPPUNIT_ASSERT_EQUAL(TURNLEFT, r->next());
}

