#ifndef MYLANDSENSOR_H
#define MYLANDSENSOR_H

#include "../src/LandSensor.h"
#include "../src/Coordinates.h"
#include "../src/Land.h"

class MyLandSensor : public LandSensor{
public:
  MyLandSensor(int s=4);
  void setValue(Coordinates* coordinate, Land::Lands land); 
};

#endif  /* MYLANDSENSOR_H */
