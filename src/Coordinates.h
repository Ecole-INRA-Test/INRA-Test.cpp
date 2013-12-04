/* 
 * File:   Coordinates.h
 * Author: cjoffro2
 *
 * Created on 26 novembre 2013, 13:30
 */

#ifndef COORDINATES_H
#define	COORDINATES_H

class Coordinates {
public:
    Coordinates(int, int);
    ~Coordinates();
    bool operator <(const Coordinates& rhs) const
    {
	return x < rhs.x;
    }
    
    bool operator ==(const Coordinates& rhs) const
    {
	if (x == rhs.x && y==rhs.y) return true;
	return false;
    }

    int getX();
    int getY();
private:
    int x;
    int y;
};

#endif	/* COORDINATES_H */

