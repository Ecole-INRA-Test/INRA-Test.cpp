/*
 * File:   RobotTest.cpp
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:34
 */

#include "RobotTest.h"
#include <iostream>
using ::testing::Return;
using ::testing::ReturnNull;
using ::testing::Throw;
using ::testing::_;
using ::testing::AnyNumber;

CPPUNIT_TEST_SUITE_REGISTRATION(RobotTest);

RobotTest::RobotTest() {
}

RobotTest::~RobotTest() {
}

void RobotTest::setUp() {
    m = new MockBattery();
    mls = new MockLandSensor();

  
    r = new Robot(1.1, new Battery());
}

void RobotTest::tearDown() {
    delete(m);
    delete(mls);
}

void RobotTest::testGetChargeLevel() {
  CPPUNIT_ASSERT(true);
}

void RobotTest::testMoveForward(){
    ON_CALL(*mls, mockGetPointToPointEnergyCoefficient(_,_)).WillByDefault(Return(1.1));
    
    r->land(new Coordinates(0,0), mls);
    try{
    r->moveForward();
    }catch(int e) {std::cout << "Error: " << e << std::endl;}
    CPPUNIT_ASSERT(-1 == r->getYposition());
    CPPUNIT_ASSERT(0 == r->getXposition());
}

void RobotTest::testMoveForwardException(){
    ON_CALL(*mls, mockGetPointToPointEnergyCoefficient(_,_)).WillByDefault(Throw(2));
    
    r->land(new Coordinates(0,0), mls);
    CPPUNIT_ASSERT_THROW(r->moveForward(), int);
}

