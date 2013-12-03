/* 
 * File:   RoadBookCalculator.cpp
 * Author: cjoffro2
 * 
 * Created on 27 novembre 2013, 13:14
 */

#include "RoadBookCalculator.h"

RoadBook* RoadBookCalculator::calculateRoadBook(Direction direction, Coordinates* position, Coordinates* destination, std::vector<Instruction>* instructions){
    	std::vector<Direction>* directionList = new std::vector<Direction>();
        if (destination->getX() < position->getX()) directionList->push_back(WEST);
        if (destination->getX() > position->getX()) directionList->push_back(EAST);
        if (destination->getY() < position->getY()) directionList->push_back(SOUTH);
        if (destination->getY() > position->getY()) directionList->push_back(NORTH);
        if (directionList->empty()) return new RoadBook(instructions);
        if (std::find(directionList->begin(),directionList->end(), direction) != directionList->end()) {
            instructions->push_back(FORWARD);
            return calculateRoadBook(direction, MapTools::nextForwardPosition(position, direction), destination, instructions);
        } else {
            instructions->push_back(TURNRIGHT);
            return calculateRoadBook(MapTools::clockwise(direction), position, destination, instructions);
        }
    }
