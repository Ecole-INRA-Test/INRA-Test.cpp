/* 
 * File:   CheckPoint.h
 * Author: cjoffro2
 *
 * Created on 26 novembre 2013, 13:30
 */

#ifndef CHECKPOINT_H
#define	CHECKPOINT_H

#include "Coordinates.h"
#include "Direction.h"

class CheckPoint {
public:
    CheckPoint(Coordinates* pos, Direction direct, bool manual);
    ~CheckPoint();
    Coordinates* getPosition();
    Direction getDirection();
    bool getManualDirective();
private:
    Coordinates* position;
    Direction direction;
    bool manualDirective;
};

#endif	/* CHECKPOINT_H */

