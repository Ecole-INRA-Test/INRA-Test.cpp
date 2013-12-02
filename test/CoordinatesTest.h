/*
 * File:   BatteryTest.h
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:33
 */

#ifndef COORDINATESTEST_H
#define	COORDINATESTEST_H

#include <cppunit/extensions/HelperMacros.h>

class CoordinatesTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(CoordinatesTest);

    CPPUNIT_TEST(testXY);

    CPPUNIT_TEST_SUITE_END();

public:
    CoordinatesTest();
    virtual ~CoordinatesTest();
    void setUp();
    void tearDown();

private:
    void testXY();
};

#endif	/* COORDINATESTEST_H */

