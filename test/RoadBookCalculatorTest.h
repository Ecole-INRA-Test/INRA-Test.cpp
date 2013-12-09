/*
 * File:   RoadBookCalculatorTest.h
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:33
 */

#ifndef ROADBOOKCALCULATORTEST_H
#define	ROADBOOKCALCULATORTEST_H

#include "gmock/gmock.h"
#include <cppunit/extensions/HelperMacros.h>
#include "../src/RoadBookCalculator.h"
#include "MockLandSensor.h"
#include <vector>
#include "../src/Coordinates.h"
#include "../src/Instruction.h"
#include "../src/Direction.h"
#include "../src/RoadBook.h"

class  RoadBookCalculatorTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE( RoadBookCalculatorTest);

    CPPUNIT_TEST(testMethod);
    CPPUNIT_TEST(testFailedMethod);

    CPPUNIT_TEST_SUITE_END();

public:
     RoadBookCalculatorTest();
    virtual ~ RoadBookCalculatorTest();
    void setUp();
    void tearDown();

private:
    MockLandSensor* mls;
    void testMethod();
    void testFailedMethod();
};

#endif	/* ROADBOOKCALCULATORTEST_H */

