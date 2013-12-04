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

    CPPUNIT_TEST(addCheckPointTest_1);
    CPPUNIT_TEST(addCheckPointTest_2);

    CPPUNIT_TEST_SUITE_END();

public:
    BlackBoxTest();
    virtual ~BlackBoxTest();
    void setUp();
    void tearDown();

private:
    BlackBox* b;
    void addCheckPointTest_1();
    void addCheckPointTest_2();
};

#endif	/* BLACKBOXTEST_H */

