/*
 * File:   LandSensorTest.h
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:33
 */

#ifndef LANDSENSORTEST_H
#define	LANDSENSORTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/LandSensor.h"

class LandSensorTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(LandSensorTest);

    CPPUNIT_TEST(getPointToPointEnergyCoefficientTest_1);
    CPPUNIT_TEST(testFailedMethod);

    CPPUNIT_TEST_SUITE_END();

public:
    LandSensorTest();
    virtual ~LandSensorTest();
    void setUp();
    void tearDown();

private:
    Coordinates* c1;
    Coordinates* c2;
    LandSensor* l;
    void getPointToPointEnergyCoefficientTest_1();
    void testFailedMethod();
};

#endif	/* LANDSENSORTEST_H */

