/*
 * File:   RoadBookCalculatorTest.h
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:33
 */

#ifndef ROADBOOKCALCULATORTEST_H
#define	ROADBOOKCALCULATORTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/RoadBookCalculator.h"

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
    void testMethod();
    void testFailedMethod();
};

#endif	/* ROADBOOKCALCULATORTEST_H */

