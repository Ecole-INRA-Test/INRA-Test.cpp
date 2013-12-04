/* 
 * File:   CheckPoint.cpp
 * Author: cjoffro2
 * 
 * Created on 26 novembre 2013, 13:30
 */

#include "CheckPoint.h"


CheckPoint::CheckPoint(Coordinates* pos, Direction::Directions direct, bool manual) {
    position = pos;
    direction = direct;
    manualDirective = manual;
}

CheckPoint::~CheckPoint() {
}

Coordinates* CheckPoint::getPosition() {
    return position;
}
Direction::Directions CheckPoint::getDirection() {
    return direction;
}
bool CheckPoint::getManualDirective() {
    return manualDirective;
}	

