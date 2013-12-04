/*
 * File:   RoadBookTest.h
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:33
 */

#ifndef ROADBOOKTEST_H
#define	ROADBOOKTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/RoadBook.h"

class RoadBookTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(RoadBookTest);

    CPPUNIT_TEST(testMethod);
    CPPUNIT_TEST(testFailedMethod);

    CPPUNIT_TEST_SUITE_END();

public:
    RoadBookTest();
    virtual ~RoadBookTest();
    void setUp();
    void tearDown();

private:
    void testMethod();
    void testFailedMethod();
};

#endif	/* ROADBOOKTEST_H */
