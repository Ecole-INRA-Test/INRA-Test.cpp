#include "MyLandSensor.h"
MyLandSensor::MyLandSensor(int s) {
   seed = s;
   srand(seed);
   PORTEE=4;
   boxTop = NULL;
   boxBottom = NULL;
}

void MyLandSensor::setValue(Coordinates* coordinate, Land::Lands land){
	carte[coordinate] = land;
}
