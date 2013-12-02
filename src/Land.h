/* 
 * File:   Land.h
 * Author: cjoffro2
 *
 * Created on 27 novembre 2013, 14:01
 */

#ifndef LAND_H
#define	LAND_H

#include "Error.h"

class Land {
public:
typedef enum {
	TERRE=1,
	ROCHE=2,
	SABLE=4,
	BOUE=3,
	INFRANCHISSABLE=0
} Lands;
static Lands getLandByOrdinal(int ordinal) throw (int);
static int countLand();
private:
};
#endif	/* LAND_H */
