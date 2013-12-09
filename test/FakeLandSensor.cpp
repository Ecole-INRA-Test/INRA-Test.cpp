#include "FakeLandSensor.h"

bool FakeLandSensor::isAccessible(Coordinates * coordinate) throw (int) {
	if(coordinate->getX() >=-1 && coordinate->getX() <= 1)
		if(coordinate->getY()>= -1 && coordinate->getY() <= 1)
			return true;
	return false;
}
