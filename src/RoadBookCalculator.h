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
#include "Direction.h"
#include "RoadBook.h"
#include "MapTools.h"

class RoadBookCalculator {
public:
    static RoadBook* calculateRoadBook(Direction direction, Coordinates* position, Coordinates* destination, std::vector<Instruction>* instructions);
   
private:
};

#endif	/* ROADBOOKCALCULATOR_H */

