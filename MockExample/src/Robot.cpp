/* 
 * File:   Robot.cpp
 * Author: cjoffro2
 * 
 * Created on 26 novembre 2013, 13:30
 */

#include "Robot.h"


Robot::Robot(double energy, Battery* battery, Coordinates* coordinates) {
  position = coordinates;
  isLanded = false;
  energyConsumption = energy;
  cells = battery;
}

Robot::~Robot() {
}


int Robot::getXposition() throw (int){
  if(!isLanded) throw UNLANDED_ROBOT;
  return position->getX();
}
int Robot::getYposition() throw (int){
  if(!isLanded) throw UNLANDED_ROBOT;
  return position->getY();
}

void Robot::moveForward() throw (int) {
  if(!isLanded) throw UNLANDED_ROBOT;
  position->setY(position->getY() + 1);
  cells->use(1.0);
}
void Robot::moveBackward() throw (int){
  if(!isLanded) throw UNLANDED_ROBOT;
  position->setY(position->getY() - 1);
  cells->use(1.0);
}
