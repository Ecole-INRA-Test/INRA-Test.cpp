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

#include "../src/Error.h"
#include "../src/Battery.h"

//using ::testing::_;


class MockBattery : public Battery {
public:
  
  /*Classe MockBattery qui hérite de la classe Battery
    MOCK_METHOD0 = mocker une méthode avec 0 paramètre
    MOCK_METHOD0(m, type(param)) m = méthode à mocker, type = type de retour de la méthode à mocker
    param = paramètre(s) de la méthode à mocker (0 ou N)
   */
  MOCK_METHOD0(getChargeLevel, double());
 
};

#endif	/* MOCKBATTERY_H */

