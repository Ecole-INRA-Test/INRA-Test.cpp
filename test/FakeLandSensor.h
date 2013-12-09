#ifndef FAKELANDSENSOR_H
#define FAKELANDSENSOR_H

#include "../src/LandSensor.h"

class FakeLandSensor : public LandSensor{
public:
   virtual bool isAccessible(Coordinates* coordinate) throw (int);
};

#endif  /* FAKELANDSENSOR_H */
