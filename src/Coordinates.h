/* 
 * File:   Coordinates.h
 * Author: cjoffro2
 *
 * Created on 26 novembre 2013, 13:30
 */

#ifndef COORDINATES_H
#define	COORDINATES_H
#include <string>
#include <sstream>
class Coordinates {
public:
    Coordinates(int, int);
    ~Coordinates();
    bool operator <(const Coordinates& rhs) const;
    bool operator ==(const Coordinates& rhs) const;

    int getX();
    int getY();
    std::string toString();
private:
    int x;
    int y;
};

#endif	/* COORDINATES_H */

