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

  myInstructions = new std::vector<Instruction>();
  myInstructions->push_back(TURNLEFT);
  myRoadBook = new RoadBook(myInstructions);

}

void RoadBookTest::hasInstructionTest(){
  CPPUNIT_ASSERT(myRoadBook->hasInstruction());
  myInstructions->clear();
  CPPUNIT_ASSERT(!myRoadBook->hasInstruction());

  
}

void RoadBookTest::tearDown() {
}

