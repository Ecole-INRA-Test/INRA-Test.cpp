/* 
 * File:   Coordinates.cpp
 * Author: cjoffro2
 * 
 * Created on 26 novembre 2013, 13:30
 */

#include "Coordinates.h"

Coordinates::Coordinates(int xval, int yval) {
    x = xval;
    y = yval;
}

Coordinates::~Coordinates() {
}

bool Coordinates::operator <(const Coordinates& rhs) const
{
	return x < rhs.x;
}

bool Coordinates::operator ==(const Coordinates& rhs) const
{
        if (x == rhs.x && y==rhs.y) return true;
        return false;
}


int Coordinates::getX(){
    return x;
}

int Coordinates::getY(){
    return y;
}

std::string Coordinates::toString()
{
	std::stringstream ss;
	ss << "(" << x << ", " << y << ")";
	return ss.str();
}
