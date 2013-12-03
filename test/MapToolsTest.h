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

 
    CPPUNIT_TEST(nextForwardPositionTest_ALL);
    CPPUNIT_TEST(nextBackwardPositionTest_NORTH);
    CPPUNIT_TEST(nextBackwardPositionTest_SOUTH);
    CPPUNIT_TEST(nextBackwardPositionTest_EAST);
    CPPUNIT_TEST(nextBackwardPositionTest_WEST);

    CPPUNIT_TEST_SUITE_END();

public:
    Coordinates* oracleCoordinates;
    Coordinates* robotCoordinates;

    MapToolsTest();
    virtual ~MapToolsTest();
    void setUp();
    void tearDown();

private:
    void nextForwardPositionTest_ALL();

    void nextBackwardPositionTest_NORTH();
    void nextBackwardPositionTest_SOUTH();
    void nextBackwardPositionTest_EAST();
    void nextBackwardPositionTest_WEST();
};

#endif	/* MAPTOOLTESTS_H */

