/*
 * File:   RobotTest.cpp
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:34
 */

#include "RobotTest.h"

using ::testing::Return;
using ::testing::_;

CPPUNIT_TEST_SUITE_REGISTRATION(RobotTest);

RobotTest::RobotTest() {
}

RobotTest::~RobotTest() {
}

void RobotTest::setUp() {
    m = new MockBattery();

  
    r = new Robot(1.1, m);
}

void RobotTest::tearDown() {
    delete(m);
}

void RobotTest::testGetChargeLevel() {
    EXPECT_CALL(*m, getChargeLevel()).WillOnce(Return(95.0));

    CPPUNIT_ASSERT(r->getChargeLevel() == 95.0);
    CPPUNIT_ASSERT(true);
}

