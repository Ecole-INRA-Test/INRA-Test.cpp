/* 
 * File:   Robot.cpp
 * Author: cjoffro2
 * 
 * Created on 26 novembre 2013, 13:30
 */

#include "Robot.h"


Robot::Robot(double energy, Battery* battery) {
	isLanded = false;
	energyConsumption = energy;
	cells = battery;
	blackbox = new BlackBox();	
}

Robot::~Robot() {
}

void Robot::land(Coordinates* landPosition, LandSensor* sensor){
	position = landPosition;
	direction = Direction::NORTH;
	isLanded = true;
	landSensor = sensor;
	cells->setUp();
	blackbox->addCheckPoint(position, direction, true);
}
int Robot::getXposition() throw (int){
	if(!isLanded) throw UNLANDED_ROBOT;
	return position->getX();
}
int Robot::getYposition() throw (int){
	if(!isLanded) throw UNLANDED_ROBOT;
	return position->getY();
}
Direction::Directions Robot::getDirection() throw (int){
	if(!isLanded) throw UNLANDED_ROBOT;
	return direction;
}
void Robot::moveForward() throw (int) {
	if(!isLanded) throw UNLANDED_ROBOT;
	moveTo(MapTools::nextForwardPosition(position, direction));
}
void Robot::moveBackward() throw (int){
	if(!isLanded) throw UNLANDED_ROBOT;
	moveTo(MapTools::nextBackwardPosition(position, direction));
}
void Robot::moveTo(Coordinates* nextPosition) throw (int){
	double neededEnergy = 0;
	neededEnergy = landSensor->getPointToPointEnergyCoefficient(position, nextPosition) * energyConsumption;
	if(!cells->canDeliver(neededEnergy)) throw ERROR_INSUFFICIENT_CHARGE;
	cells->use(neededEnergy);
	position = nextPosition;
	blackbox->addCheckPoint(position, direction, true);
}
void Robot::turnLeft() throw (int){
	if(!isLanded) throw UNLANDED_ROBOT;
	//direction = MapTools::counterclockwise(direction);
	turnTo(MapTools::counterclockwise(direction));
}
void Robot::turnRight() throw (int){
	if(!isLanded) throw UNLANDED_ROBOT;
	//direction = MapTools::clockwise(direction);
	turnTo(MapTools::clockwise(direction));
}
void Robot::turnTo(Direction::Directions newDirection) throw (int){
	if(!cells->canDeliver(energyConsumption)) throw ERROR_INSUFFICIENT_CHARGE;
	cells->use(energyConsumption);
	direction = newDirection;
	blackbox->addCheckPoint(position, direction, true);

}
void Robot::setRoadBook(RoadBook* rb){
	roadBook = rb;
}
std::vector<CheckPoint*>* Robot::letsGo() throw (int){
	if(roadBook == NULL) throw UNDEFINED_ROADBOOK_EXCEPTION;
	std::vector<CheckPoint*>* mouchard = new std::vector<CheckPoint*> ();
	while(roadBook->hasInstruction()){
		Instruction nextInstruction = roadBook->next();
		if (nextInstruction == FORWARD) moveForward();
		else if (nextInstruction == BACKWARD) moveBackward();
		else if (nextInstruction == TURNLEFT) turnLeft();
		else if (nextInstruction == TURNRIGHT) turnRight();
		CheckPoint* checkpoint = new CheckPoint(position, direction, true);
		mouchard->push_back(checkpoint);
		blackbox->addCheckPoint(checkpoint);
	}
	return mouchard;
}
void Robot::computeRoadTo(Coordinates* destination) throw (int){
	if(!isLanded) throw UNLANDED_ROBOT;
	setRoadBook(RoadBookCalculator::calculateRoadBook(direction, position, destination, new std::vector<Instruction> ()));
}
