/* 
 * File:   BlackBox.cpp
 * Author: cjoffro2
 * 
 * Created on 26 novembre 2013, 13:30
 */

#include "BlackBox.h"


BlackBox::BlackBox() {
    checkPointList = new std::vector<CheckPoint*> ();
}

BlackBox::~BlackBox() {
}

void BlackBox::addCheckPoint(Coordinates* position, Direction direction, bool manualDirective){
    checkPointList->push_back(new CheckPoint(position, direction, manualDirective));
}
void BlackBox::addCheckPoint(CheckPoint* checkPoint){
    checkPointList->push_back(checkPoint);
}
std::vector<CheckPoint*>* BlackBox::getCheckPointList(){
    return checkPointList;
}
