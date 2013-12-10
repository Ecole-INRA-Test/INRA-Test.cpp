/*
 * File:   MapToolsTest.h
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:33
 */

#ifndef MAPTOOLSTEST_H
#define	MAPTOOLSTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/MapTools.h"

class MapToolsTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(MapToolsTest);

    CPPUNIT_TEST( testNextForwardPos );
    CPPUNIT_TEST( testNextBackwardPos );
    CPPUNIT_TEST( testCounterclockwise );
    CPPUNIT_TEST( testClockwise );
    CPPUNIT_TEST_SUITE_END();

public:
    MapToolsTest();
    virtual ~MapToolsTest();
    void setUp();
    void tearDown();
    void testNextForwardPos();
    void testNextBackwardPos();
    void testCounterclockwise();
    void testClockwise();

private:
};

#endif	/* MAPTOOLTESTS_H */

