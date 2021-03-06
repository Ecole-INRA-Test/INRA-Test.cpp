/* 
 * File:   MapTools.h
 * Author: cjoffro2
 *
 * Created on 27 novembre 2013, 13:14
 */

#ifndef MAPTOOLS_H
#define	MAPTOOLS_H

#include "Direction.h"
#include "Coordinates.h"

class MapTools {
public:
    MapTools();
    ~MapTools();
static Coordinates* nextForwardPosition(Coordinates* position, Direction::Directions direction);

static Coordinates* nextBackwardPosition(Coordinates* position, Direction::Directions direction);

static Direction::Directions counterclockwise(Direction::Directions direction);

static Direction::Directions clockwise(Direction::Directions direction);

private:
};

#endif	/* MAPTOOLS_H */

