/* 
 * File:   Direction.h
 * Author: cjoffro2
 *
 * Created on 27 novembre 2013, 13:58
 */

#ifndef DIRECTION_H
#define	DIRECTION_H

class Direction{
public:
typedef enum {
	NORTH, 
	WEST, 
	SOUTH, 
	EAST
}Directions;

static Directions oppositeDirection(Directions direction);
};
#endif	/* DIRECTION_H */

