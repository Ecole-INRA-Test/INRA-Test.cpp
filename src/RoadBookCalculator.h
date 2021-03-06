/* 
 * File:   RoadBook.h
 * Author: cjoffro2
 *
 * Created on 27 novembre 2013, 13:14
 */

#ifndef ROADBOOKCALCULATOR_H
#define	ROADBOOKCALCULATOR_H

#include <algorithm>
#include <vector>
#include "Instruction.h"
#include "Error.h"
#include "Direction.h"
#include "RoadBook.h"
#include "MapTools.h"
#include "LandSensor.h"
#include "InstructionListTool.h"

class RoadBookCalculator {
public:
    static RoadBook* calculateRoadBook(Direction::Directions direction, Coordinates* position, Coordinates* destination, std::vector<Instruction>* instructions);
    static RoadBook* calculateRoadBook(LandSensor* sensor, Direction::Directions direction, Coordinates* position, Coordinates* destination, std::vector<Instruction>* instructions, std::vector<Coordinates*>* trace);
   
private:
    static int lastIndex(std::vector<Instruction>* v, Instruction elem, int pos=-1);
    static void eraseElement(std::vector<Direction::Directions>* v, Direction::Directions d);
};

#endif	/* ROADBOOKCALCULATOR_H */

