/* 
 * File:   Coordinates.cpp
 * Author: cjoffro2
 * 
 * Created on 26 novembre 2013, 13:30
 */

#include "Coordinates.h"
#include <iostream>

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
