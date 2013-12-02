/* 
 * File:   Land.cpp
 * Author: cjoffro2
 * 
 * Created on 27 novembre 2013, 14:03
 */

#include "Land.h"


Land::Lands Land::getLandByOrdinal(int ordinal) throw (int){
	switch ( ordinal ) {
	case 0:
		return TERRE;
	case 1:
		return ROCHE;
	case 2:
		return SABLE;
	case 3:
		return BOUE;
	case 4:
		return INFRANCHISSABLE;
	default:
		throw ERROR_LAND_NOT_MANAGED;
	}	
}

int Land::countLand() {
	return 5;
}
