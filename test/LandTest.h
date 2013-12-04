/*
 * File:   LandTest.h
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:33
 */

#ifndef LANDTEST_H
#define	LANDTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Land.h"

class LandTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(LandTest);

    CPPUNIT_TEST(getLandByOrdinalTest);
    CPPUNIT_TEST(testFailedMethod);

    CPPUNIT_TEST_SUITE_END();

public:
    LandTest();
    virtual ~LandTest();
    void setUp();
    void tearDown();

private:
    void getLandByOrdinalTest();
    void testFailedMethod();
};

#endif	/* LANDTEST_H */

