/* 
 * File:   Coordinates.cpp
 * Author: cjoffro2
 * 
 * Created on 26 novembre 2013, 13:30
 */

#include "Coordinates.h"

int x,y;

Coordinates::Coordinates(int xval, int yval) {
    x = xval;
    y = yval;
}

Coordinates::~Coordinates() {
}

int Coordinates::getX(){
    return x;
}

int Coordinates::getY(){
    return y;
}