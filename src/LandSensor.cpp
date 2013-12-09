/* 
 * File:   LandSensor.cpp
 * Author: cjoffro2
 * 
 * Created on 27 novembre 2013, 14:03
 */
#include "LandSensor.h"
LandSensor::LandSensor(int s) {
   seed = s;
   srand(seed);
   PORTEE=4;
   boxTop = NULL;
   boxBottom = NULL;
}


LandSensor::~LandSensor() {
}

double LandSensor::getPointToPointEnergyCoefficient(Coordinates* coordinate1, Coordinates* coordinate2) throw (int){
	Land::Lands terrain1 = lazyGet(coordinate1);
	Land::Lands terrain2 = lazyGet(coordinate2);
	if (terrain2 == Land::INFRANCHISSABLE)
		throw ERROR_COORDINATES_INACCESSIBLE;
	double result = (terrain1 + terrain2) / 2.0;
	return result;
    }

Land::Lands LandSensor::lazyGet(Coordinates* coordinate1) throw (int){
	bool findCoordinate = false;
	Coordinates* tmpCoordinate = coordinate1;
	for(std::map<Coordinates*, Land::Lands>::iterator it = carte.begin(); it!=carte.end(); ++it){
		if(it->first->operator==(*coordinate1)) {
			findCoordinate = true;
			tmpCoordinate = it->first;
		}
	}
	if(!findCoordinate){
		try{
		  //int val = rand()%5;
		  Land::Lands land;
                  if (rand()%10 == 0) {
			land = Land::INFRANCHISSABLE;
		  }
		  else 
	 	  land = Land::getLandByOrdinal(rand()%4);
		  carte[tmpCoordinate] = land;
		} catch(int e) {
		throw ERROR_LANDSENSOR_FAIL;
		}
	}
	Land::Lands landToSend = carte.find(tmpCoordinate)->second;
	return carte.find(tmpCoordinate)->second;
}

bool LandSensor::isAccessible(Coordinates* coordinate) throw (int){
	//Land::Lands terrain = lazyGet(coordinate);
	bool findCoordinate = false;
	Coordinates* tmpCoordinate = coordinate;
	for(std::map<Coordinates*, Land::Lands>::iterator it = carte.begin(); it!=carte.end(); ++it){
		if(it->first->operator==(*coordinate)) {
			findCoordinate = true;
			tmpCoordinate = it->first;
		}
	}
        if(findCoordinate){
		return carte[tmpCoordinate] != Land::INFRANCHISSABLE;
	}
	return false;
}

void LandSensor::cartographier(Coordinates* landPosition) throw (int) {
        if (boxTop == NULL) boxTop = new Coordinates(landPosition->getX() - PORTEE, landPosition->getY() - PORTEE);
        else if (boxTop->getX() > landPosition->getX() - PORTEE && boxTop->getY() > landPosition->getY() - PORTEE)
            boxTop = new Coordinates(landPosition->getX() - PORTEE, landPosition->getY() - PORTEE);
        else if (boxTop->getX() > landPosition->getX() - PORTEE)
            boxTop = new Coordinates(landPosition->getX() - PORTEE, boxTop->getY());
        else if (boxTop->getY() > landPosition->getY() - PORTEE)
            boxTop = new Coordinates(boxTop->getX(), landPosition->getY() - PORTEE);
        if (boxBottom == NULL) boxBottom = new Coordinates(landPosition->getX() + PORTEE, landPosition->getY() + PORTEE);
        else if (boxBottom->getX() < landPosition->getX() + PORTEE && boxBottom->getY() < landPosition->getY() + PORTEE)
            boxBottom = new Coordinates(landPosition->getX() + PORTEE, landPosition->getY() - PORTEE);
        else if (boxBottom->getX() < landPosition->getX() + PORTEE)
            boxBottom = new Coordinates(landPosition->getX() + PORTEE, boxBottom->getY());
        else if (boxBottom->getY() < landPosition->getY() + PORTEE)
            boxBottom = new Coordinates(boxBottom->getX(), landPosition->getY() + PORTEE);
        for (int i = landPosition->getX() - PORTEE; i < landPosition->getX() + PORTEE + 1; i++) {
            for (int j = landPosition->getY() - PORTEE; j < landPosition->getY() + PORTEE + 1; j++) {
                lazyGet(new Coordinates(i, j));
            }
        }
    }


Coordinates* LandSensor::getTop() {
return boxTop;
}

int LandSensor::getXBottom() {
return boxBottom->getX();
}

std::vector<std::string>* LandSensor::displayCarte(){
        int i, j;
	std::vector<std::string>* grille = new std::vector<std::string>();
	//std::stringstream ligne;
	Land::Lands land;
	Coordinates* coordinate;
	Coordinates* tmpCoordinate;
	bool findCoordinate = false;
	std::string text;
	text = boxTop->toString() + "<->" + boxBottom->toString();
	//ligne << boxTop->toString() << "<->" << boxBottom->toString();
	//grille->push_back(ligne.str());
	grille->push_back(text);
	//ligne.flush();
        for (i = boxTop->getY() ; i < boxBottom->getY() + 1 ; i++) {
		text =  i + "\t|\t";
		//ligne << i << "\t|\t";
		//ligne << i << "|";
		for (j = boxTop->getX() ; j < boxBottom->getX() + 1 ; j++) {
			coordinate = new Coordinates(j,i);
			for(std::map<Coordinates*, Land::Lands>::iterator it = carte.begin(); it!=carte.end(); ++it){
				if(it->first->operator==(*coordinate)) {
					findCoordinate = true;
					tmpCoordinate = it->first;
				}
			}
			if(!findCoordinate)
				text = text + " |\t";
				//ligne << " |\t";
				//ligne << " |";
			else{
				land = carte[tmpCoordinate];
				switch (land) {
				case Land::INFRANCHISSABLE :
					text = text + "\u2610|\t" ;
					//ligne << "\u2610|\t" ;
					//ligne << "\u2610|" ;
					break;
				case Land::ROCHE :
					text = text + "\u203B|\t" ;
					//ligne << "\u203B|\t" ;
					//ligne << "\u203B|" ;
					break;
				case Land::BOUE :
					text = text + "\u2744|\t" ;
					//ligne << "\u2744|\t" ;
					//ligne << "\u2744|" ;
					break;
				case Land::SABLE :
					text = text + "\u2652|\t" ;
					//ligne << "\u2652|\t" ;
					//ligne << "\u2652|" ;
					break;
				case Land::TERRE :
					text = text + "-|\t" ;
					//ligne << "-|\t" ;
					//ligne << "-|" ;
					break;

				default:
					text = text +  " |\t";
					//ligne << " |\t";
					//ligne << " |";
				}
			}
		}
		//grille->push_back(ligne.str());
		grille->push_back(text);
		//ligne.flush();
	}
	//ligne.flush();
	
	text = "Légende : Infranchissable \u2610\tRoche \u203B\tBoue \u2744\tSable \u2652\tTerre -";
	//ligne << "Légende : " << "Infranchissable " << "\u2610" << "\tRoche " << "\u203B" << "\tBoue " << "\u2744" << "\tSable " << "\u2652" << "\tTerre " << "-";
	grille->push_back(text);
	return grille;
}
