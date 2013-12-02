/*
 * File:   LandSensorTest.h
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:33
 */

#ifndef LANDSENSORTEST_H
#define	LANDSENSORTEST_H

#include <cppunit/extensions/HelperMacros.h>

class LandSensorTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(LandSensorTest);

    CPPUNIT_TEST(testMethod);
    CPPUNIT_TEST(testFailedMethod);

    CPPUNIT_TEST_SUITE_END();

public:
    LandSensorTest();
    virtual ~LandSensorTest();
    void setUp();
    void tearDown();

private:
    void testMethod();
    void testFailedMethod();
};

#endif	/* LANDSENSORTEST_H */

