/* 
 * File:   BlackBox.h
 * Author: cjoffro2
 *
 * Created on 26 novembre 2013, 13:30
 */

#ifndef BLACKBOX_H
#define	BLACKBOX_H

#include <vector>
#include "CheckPoint.h"
#include "Coordinates.h"
#include "Direction.h"

class BlackBox {
public:
    BlackBox();
    ~BlackBox();
    void addCheckPoint(Coordinates* position, Direction direction, bool manualDirective);
    void addCheckPoint(CheckPoint* checkPoint);
    std::vector<CheckPoint*>* getCheckPointList();
private:
    std::vector<CheckPoint*>* checkPointList;
};

#endif	/* BLACKBOX_H */

