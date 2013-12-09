/*
 * File:   RobotTest.h
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:33
 */

#ifndef ROBOTTEST_H
#define	ROBOTTEST_H

#include "gmock/gmock.h"
#include <cppunit/extensions/HelperMacros.h>
#include "../src/Robot.h"
#include "MockBattery.h"

class RobotTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(RobotTest);

    CPPUNIT_TEST(testMethod);
    CPPUNIT_TEST(testFailedMethod);

    CPPUNIT_TEST_SUITE_END();

public:
    RobotTest();
    virtual ~RobotTest();
    void setUp();
    void tearDown();

private:
    Robot* r;
    MockBattery* m;
    void testMethod();
    void testFailedMethod();
};

#endif	/* ROBOTTEST_H */

