/*
 * File:   BlackBoxTest.h
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:33
 */

#ifndef BLACKBOXTEST_H
#define	BLACKBOXTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/BlackBox.h"

class BlackBoxTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(BlackBoxTest);

    CPPUNIT_TEST(getChargeLevelTest);
    CPPUNIT_TEST(useTest);
    CPPUNIT_TEST(canDeliverTest);

    CPPUNIT_TEST_SUITE_END();

public:
    BlackBoxTest();
    virtual ~BlackBoxTest();
    void setUp();
    void tearDown();

private:
    BlackBox* b;
    void getChargeLevelTest();
    void useTest();
    void canDeliverTest();
};

#endif	/* BLACKBOXTEST_H */

