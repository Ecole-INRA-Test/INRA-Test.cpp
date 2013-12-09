/*
 * File:   RoadBookCalculatorTest.cpp
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:34
 */

#include "RoadBookCalculatorTest.h"
#include <iostream>
using ::testing::Return;
using ::testing::_;

CPPUNIT_TEST_SUITE_REGISTRATION( RoadBookCalculatorTest);

RoadBookCalculatorTest:: RoadBookCalculatorTest() {
}

RoadBookCalculatorTest::~RoadBookCalculatorTest() {
}

void RoadBookCalculatorTest::setUp() {
}

void RoadBookCalculatorTest::tearDown() {
}

void RoadBookCalculatorTest::testMethod() {
    mls = new MockLandSensor();
    Coordinates* c5 = new Coordinates(0,0);
    Coordinates* c9 = new Coordinates(-1,1);
    mls->DelegateToFake();
//    EXPECT_CALL(*mls, mockIsAccessible(_)).Times(3);
    RoadBook* rb = RoadBookCalculator::calculateRoadBook(mls, Direction::NORTH, c5, c9, new std::vector<Instruction> (), new std::vector<Coordinates*>());
    while(rb->hasInstruction()){
	std::cout << rb->next() << std::endl;
    }
    CPPUNIT_ASSERT(true);
    delete(mls);
}

void RoadBookCalculatorTest::testFailedMethod() {
    CPPUNIT_ASSERT(true);
}

