/* 
 * File:   MapTools.cpp
 * Author: cjoffro2
 * 
 * Created on 27 novembre 2013, 13:14
 */

#include "MapTools.h"

Coordinates* MapTools::nextForwardPosition(Coordinates* position, Direction::Directions direction) {
        if (direction == Direction::NORTH)
            return new Coordinates(position->getX(), position->getY() - 1);
        if (direction == Direction::SOUTH)
            return new Coordinates(position->getX(), position->getY() + 1);
        if (direction == Direction::EAST)
            return new Coordinates(position->getX() + 1, position->getY());
        return new Coordinates(position->getX() - 1, position->getY());
    }

Coordinates* MapTools::nextBackwardPosition(Coordinates* position, Direction::Directions direction) {
        if (direction == Direction::NORTH)
            return new Coordinates(position->getX(), position->getY() + 1);
        if (direction == Direction::SOUTH)
            return new Coordinates(position->getX(), position->getY() - 1);
        if (direction == Direction::EAST)
            return new Coordinates(position->getX() - 1, position->getY());
        return new Coordinates(position->getX() + 1, position->getY());
    }

Direction::Directions MapTools::counterclockwise(Direction::Directions direction) {
        if (direction == Direction::NORTH) return Direction::WEST;
        if (direction == Direction::WEST) return Direction::SOUTH;
        if (direction == Direction::SOUTH) return Direction::EAST;
        return Direction::NORTH;
    }

Direction::Directions MapTools::clockwise(Direction::Directions direction) {
        if (direction == Direction::NORTH) return Direction::EAST;
        if (direction == Direction::EAST) return Direction::SOUTH;
        if (direction == Direction::SOUTH) return Direction::WEST;
        return Direction::NORTH;
    }
