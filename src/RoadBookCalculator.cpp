/* 
 * File:   RoadBookCalculator.cpp
 * Author: cjoffro2
 * 
 * Created on 27 novembre 2013, 13:14
 */

#include "RoadBookCalculator.h"

RoadBook* RoadBookCalculator::calculateRoadBook(Direction::Directions direction, Coordinates* position, Coordinates* destination, std::vector<Instruction>* instructions){
  std::vector<Direction::Directions>* directionList = new std::vector<Direction::Directions>();
  if (destination->getX() < position->getX()) directionList->push_back(Direction::WEST);
  if (destination->getX() > position->getX()) directionList->push_back(Direction::EAST);
  if (destination->getY() < position->getY()) directionList->push_back(Direction::SOUTH);
  if (destination->getY() > position->getY()) directionList->push_back(Direction::NORTH);
  if (directionList->empty()) return new RoadBook(instructions);
  if (std::find(directionList->begin(),directionList->end(), direction) != directionList->end()) {
    instructions->push_back(FORWARD);
    return calculateRoadBook(direction, MapTools::nextForwardPosition(position, direction), destination, instructions);
  } else {
    instructions->push_back(TURNRIGHT);
    return calculateRoadBook(MapTools::clockwise(direction), position, destination, instructions);
  }
}

RoadBook* RoadBookCalculator::calculateRoadBook(LandSensor* sensor, Direction::Directions direction, Coordinates* position, Coordinates* destination, std::vector<Instruction>* instructions, std::vector<Coordinates*>* trace){
  if (position->operator==(*destination)) {
    return new RoadBook(InstructionListTool::compacte(instructions));
  }
  std::vector<Direction::Directions>* directionList = new std::vector<Direction::Directions>();
  if (destination->getX() < position->getX()) directionList->push_back(Direction::WEST);
  if (destination->getX() > position->getX()) directionList->push_back(Direction::EAST);
  if (destination->getY() > position->getY()) directionList->push_back(Direction::SOUTH);
  if (destination->getY() < position->getY()) directionList->push_back(Direction::NORTH);
  std::vector<Direction::Directions>* directionsToExplore = new std::vector<Direction::Directions> ();
  directionsToExplore->push_back(Direction::NORTH); 
  directionsToExplore->push_back(Direction::SOUTH); 
  directionsToExplore->push_back(Direction::EAST); 
  directionsToExplore->push_back(Direction::WEST);
  //directionsToExplore->erase(directionsToExplore->begin() + (std::find(directionsToExplore->begin(), directionsToExplore->end(),Direction::oppositeDirection(direction)) - directionsToExplore->begin()));
  //directionList->erase(directionList->begin() + (std::find(directionList->begin(), directionList->end(),Direction::oppositeDirection(direction)) - directionList->begin()));
  eraseElement(directionsToExplore, Direction::oppositeDirection(direction));
  eraseElement(directionList, Direction::oppositeDirection(direction));
  while (!directionsToExplore->empty()) {
    if((std::find(directionList->begin(), directionList->end(), direction) != directionList->end()) && sensor->isAccessible(MapTools::nextForwardPosition(position, direction)) && (std::find(trace->begin(), trace->end(), MapTools::nextForwardPosition(position, direction)) == trace->end())) {
      try {
	eraseElement(directionsToExplore, direction);
	eraseElement(directionList, direction);
	//instructions->push_back(FORWARD);
	//return calculateRoadBook(sensor, direction, MapTools::nextForwardPosition(position, direction), destination, instructions);
	Coordinates* nextPos = MapTools::nextForwardPosition(position, direction);
	return calculateRoadBook(sensor, direction, nextPos, destination, InstructionListTool::concateneInstruction(instructions, FORWARD), InstructionListTool::concateneCoordinates(trace, nextPos));
      } catch (int e) {
//	int last = lastIndex(instructions, FORWARD);
//	for (int i= (instructions->size() - 1); i>= last; i--)
//	  instructions->erase(instructions->begin() + i);
      }
    }
    else if(std::find(directionList->begin(), directionList->end(), direction) != directionList->end()) {
      eraseElement(directionsToExplore, direction);
      eraseElement(directionList, direction);
      //directionsToExplore->erase(directionsToExplore->begin() + (std::find(directionsToExplore->begin(), directionsToExplore->end(),direction) - directionsToExplore->begin()));
      //directionList->erase(directionList->begin() + (std::find(directionList->begin(), directionList->end(),direction) - directionList->begin()));
      instructions->push_back(TURNRIGHT);
      direction = MapTools::clockwise(direction);
    }
    else if (!directionList->empty()){
      instructions->push_back(TURNRIGHT);
      direction = MapTools::clockwise(direction);
    }
    else if(directionList->empty() && (std::find(directionsToExplore->begin(), directionsToExplore->end(), direction) != directionsToExplore->end()) && sensor->isAccessible(MapTools::nextForwardPosition(position, direction)) && (std::find(trace->begin(), trace->end(), MapTools::nextForwardPosition(position, direction)) == trace->end())) 
 {
      try {
	eraseElement(directionsToExplore, direction);
	//directionsToExplore->erase(directionsToExplore->begin() + (std::find(directionsToExplore->begin(), directionsToExplore->end(),direction) - directionsToExplore->begin()));
//	instructions->push_back(FORWARD);
//	return calculateRoadBook(sensor, direction, MapTools::nextForwardPosition(position, direction), destination, instructions);
	Coordinates* nextPos = MapTools::nextForwardPosition(position, direction);
	return calculateRoadBook(sensor, direction, nextPos, destination, InstructionListTool::concateneInstruction(instructions, FORWARD), InstructionListTool::concateneCoordinates(trace, nextPos));
      } catch (int e) {
//	int last = lastIndex(instructions, FORWARD);
//	for (int i= (instructions->size() - 1); i>= last; i--)
//	  instructions->erase(instructions->begin() + i);
      }
    }
    else if(directionList->empty() && (std::find(directionsToExplore->begin(), directionsToExplore->end(), direction) != directionsToExplore->end())) {
      eraseElement(directionsToExplore, direction);
      //directionsToExplore->erase(directionsToExplore->begin() + (std::find(directionsToExplore->begin(), directionsToExplore->end(),direction) - directionsToExplore->begin()));
      instructions->push_back(TURNRIGHT);
      direction = MapTools::clockwise(direction);
    }
    else {
      instructions->push_back(TURNRIGHT);
      direction = MapTools::clockwise(direction);
    }
  }
  throw UNDEFINED_ROADBOOK_EXCEPTION;
}

int RoadBookCalculator::lastIndex(std::vector<Instruction>* v, Instruction elem, int pos){
  int decalage = 0;
  if (pos != -1) decalage = pos + 1;
  int posTemp = std::find(v->begin()+decalage, v->end(), elem) - v->begin();
  if (find(v->begin()+decalage, v->end(), elem) == v->end()) return pos;
  else return lastIndex(v, elem, posTemp);
}

void RoadBookCalculator::eraseElement(std::vector<Direction::Directions>* v, Direction::Directions d){
  if(std::find(v->begin(), v->end(), d) != v->end())
    v->erase(v->begin() + (std::find(v->begin(), v->end(),d) - v->begin()));
}
