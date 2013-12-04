/* 
 * File:   Coordinates.cpp
 * Author: cjoffro2
 * 
 * Created on 26 novembre 2013, 13:30
 */

#include "Direction.h"

Direction::Directions Direction::oppositeDirection(Direction::Directions direction) {
	switch (direction) {
	case NORTH: return SOUTH;
	case SOUTH: return NORTH;
	case WEST: return EAST;
	default: return WEST;
	}
}
