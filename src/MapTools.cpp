/* 
 * File:   MapTools.cpp
 * Author: cjoffro2
 * 
 * Created on 27 novembre 2013, 13:14
 */

#include "MapTools.h"

Coordinates* MapTools::nextForwardPosition(Coordinates* position, Direction direction) {
        if (direction == NORTH)
            return new Coordinates(position->getX(), position->getY() + 1);
        if (direction == SOUTH)
            return new Coordinates(position->getX(), position->getY() - 1);
        if (direction == EAST)
            return new Coordinates(position->getX() + 1, position->getY());
        return new Coordinates(position->getX() - 1, position->getY());
    }

Coordinates* MapTools::nextBackwardPosition(Coordinates* position, Direction direction) {
        if (direction == NORTH)
            return new Coordinates(position->getX(), position->getY() - 1);
        if (direction == SOUTH)
            return new Coordinates(position->getX(), position->getY() + 1);
        if (direction == EAST)
            return new Coordinates(position->getX() - 1, position->getY());
        return new Coordinates(position->getX() + 1, position->getY());
    }

 Direction MapTools::counterclockwise(Direction direction) {
        if (direction == NORTH) return WEST;
        if (direction == WEST) return SOUTH;
        if (direction == SOUTH) return EAST;
        return NORTH;
    }

Direction MapTools::clockwise(Direction direction) {
        if (direction == NORTH) return EAST;
        if (direction == EAST) return SOUTH;
        if (direction == SOUTH) return WEST;
        return NORTH;
    }
