/*
 * File:   BatteryTest.h
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:33
 */

#ifndef COORDINATESTEST_H
#define	COORDINATESTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Coordinates.h"

class CoordinatesTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(CoordinatesTest);

    CPPUNIT_TEST(testX);
    CPPUNIT_TEST(testY);
    CPPUNIT_TEST(testEquals);
    CPPUNIT_TEST_SUITE_END();

public:
    CoordinatesTest();
    virtual ~CoordinatesTest();
    void setUp();
    void tearDown();
    
private:
    Coordinates* c;
    void testX();
    void testY();
    void testEquals();
};

#endif	/* COORDINATESTEST_H */

