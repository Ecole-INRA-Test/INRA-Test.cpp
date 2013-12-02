/*
 * File:   BatteryTest.h
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:33
 */

#ifndef BATTERYTEST_H
#define	BATTERYTEST_H

#include <cppunit/extensions/HelperMacros.h>

class BatteryTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(BatteryTest);

    CPPUNIT_TEST(testMethod);
    CPPUNIT_TEST(testFailedMethod);

    CPPUNIT_TEST_SUITE_END();

public:
    BatteryTest();
    virtual ~BatteryTest();
    void setUp();
    void tearDown();

private:
    void testMethod();
    void testFailedMethod();
};

#endif	/* BATTERYTEST_H */

