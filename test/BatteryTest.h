/*
 * File:   BatteryTest.h
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:33
 */

#ifndef BATTERYTEST_H
#define	BATTERYTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Battery.h"

class BatteryTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(BatteryTest);

    CPPUNIT_TEST(getChargeLevelTest);
    CPPUNIT_TEST(useTest);
    CPPUNIT_TEST(canDeliverTest);
    CPPUNIT_TEST_SUITE_END();

public:
    BatteryTest();
    virtual ~BatteryTest();
    void setUp();
    void tearDown();

private:
    Battery* b;
    void getChargeLevelTest();
    void useTest();
    void canDeliverTest();
    void chargeLevelTestMock();
};

#endif	/* BATTERYTEST_H */

