/* 
 * File:   main.cpp
 * Author: cjoffro2
 *
 * Created on 26 novembre 2013, 13:25
 */

#include <algorithm>
#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "BlackBox.h"
#include "CheckPoint.h"
#include "Coordinates.h"
#include "Direction.h"
#include "Robot.h"
#include "Battery.h"
#include "Error.h"
using namespace std;

static string getOrientationToDisplay(Direction::Directions direct){
  string direction;
  switch(direct){
  case 0:
    direction = "nord";
    break;
  case 1:
    direction = "ouest";
    break;
  case 2:
    direction = "sud";
    break;
  default:
    direction = "est";
    break;
  }
  return direction;
}

static void displayCheckPoint(CheckPoint* checkPoint){
  string manual;
  string direction = getOrientationToDisplay(checkPoint->getDirection());
  if(checkPoint->getManualDirective()) manual = "manuel"; 
  else manual = "automatique";
  cout << "Position : (" << checkPoint->getPosition()->getX() << ", " << checkPoint->getPosition()->getY() << ") - orientation : " << direction << " - mode commande : " << manual << endl;
}
		   
static void displayBlackBox(BlackBox* blackbox){
  cout << "Contenu de la boite noire" << endl;
  vector<CheckPoint*>* v = blackbox->getCheckPointList();
  for(vector<CheckPoint*>::iterator it=v->begin(); it != v->end(); ++it){
    displayCheckPoint(*it);
  }
}


static void displayMenu(){
  cout << "Panneau de commandes" << endl;
  cout << "A : poser le robot" << endl;
  cout << "Z : avancer" << endl;
  cout << "Q : tourner a gauche" << endl;
  cout << "D : tourner a droite" << endl;
  cout << "S : reculer" << endl;
  cout << "M : donner une coordonnee a atteindre" << endl;
  cout << "X : quitter" << endl;
  cout << "Saisir la commande" << endl;
}

static void displayPosition(Robot* robot){
  cout << "Position actuelle : (" << robot->getXposition() << ", " << robot->getYposition() << ") - orientation : " << getOrientationToDisplay(robot->getDirection()) << endl;
}

static void displayException(int e){
  if (e == ERROR_INSUFFICIENT_CHARGE){
    cout << "Desole, je n'ai pas suffisamment d'energie pour terminer mon parcours" << endl;
  }
  if (e == ERROR_LAND_NOT_MANAGED){
    cout << "" << endl;
  }
  if (e == ERROR_LANDSENSOR_FAIL){
    cout << "Allo Houston, on a un probleme. On a perdu le retour sol" << endl;
  }
  if (e == ERROR_COORDINATES_INACCESSIBLE){
    cout << "Je suis malheureusement dans l'impossibilite de rejoindre la destination demandee" << endl;
  }
  if (e == UNDEFINED_ROADBOOK_EXCEPTION){
    cout << "Il semblerait que le road book soit manquant" << endl;
  }
  if (e == UNLANDED_ROBOT){
    cout << "Le robot est encore en l'air, il doit se poser d'abord" << endl;
  }
}

int main(int argc, char** argv) {
  cout << "Consommation de base du robot d'exploration" << endl;
  double energy;
  cin >> energy;
  int x,y;
  Robot* robot = new Robot(energy, new Battery());
  char c;
  bool continu = true;
  while(continu) {
    displayMenu();
    cin >> c;
    switch (c) {
    case 'A' :
      cout << "Coordonnees x,y de depose du robot" << endl;
      cout << "x: ";
      cin >> x;
      cout << "y: ";
      cin >> y;
      robot->land(new Coordinates(x, y), new LandSensor(4));
      try {
	//cout << "Position actuelle : (" << robot->getXposition() << ", " << robot->getYposition() << ") - orientation : " << getOrientationToDisplay(robot->getDirection()) << endl;
	displayPosition(robot);
      } catch (int e) {cout << "Probleme d'atterrissage" << endl;}
      break;
    case 'Z' :
      try {
	robot->moveForward();
	displayPosition(robot);
      } catch(int e) {
	displayException(e);
      }
      break;
    case 'Q' :
      try {
	robot->turnLeft();
	displayPosition(robot);
      } catch(int e) {
	displayException(e);
      }
      break;
    case 'D' :
      try {
	robot->turnRight();
	displayPosition(robot);
      } catch(int e) {
	displayException(e);
      }
      break;
    case 'S' :
      try {
	robot->moveBackward();
	displayPosition(robot);
      } catch(int e) {
	displayException(e);
      }
      break;
    case 'M' :
      cout << "Coordonnees x,y de la destination" << endl;
      cout << "x: ";
      cin >> x;
      cout << "y: ";
      cin >> y;
      try {
	robot->computeRoadTo(new Coordinates(x, y));
      } catch(int e) {
	displayException(e);
      }
      try{
	vector<CheckPoint*>* v = robot->letsGo();
	for(vector<CheckPoint*>::iterator it=v->begin(); it != v->end(); ++it){
	  displayCheckPoint(*it);
	}
      } catch (int e) {
	displayException(e);
	if (e == ERROR_INSUFFICIENT_CHARGE)
	  {
	    displayBlackBox(robot->blackbox);
	  }
      }
      break;
    case 'X' :
      continu = false;
      cout << "Au revoir" << endl;
      break;
    }
  }
}
