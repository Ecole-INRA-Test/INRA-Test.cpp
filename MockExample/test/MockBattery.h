/* 
 * File:   MockBattery.h
 * Author: pepi2013
 *
 * Created on 27 novembre 2013, 13:14
 */

#ifndef MOCKBATTERY_H
#define	MOCKBATTERY_H

#include <gmock/gmock.h>
#include <ctime>

#include "Error.h"
#include "../src/Battery.h"

using ::testing::_;


class MockBattery : public Battery {
public:
   
  MOCK_METHOD0(use, void(double energy));
 
};

#endif	/* MOCKBATTERY_H */

