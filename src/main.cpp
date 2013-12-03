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
#include "Coordinates.h"
#include "LandSensor.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
  Coordinates* c1 = new Coordinates(0,0);
  Coordinates* c2 = new Coordinates(1,0);
  LandSensor* l = new LandSensor();
  l->getPointToPointEnergyCoefficient(c1, c2);
  map<Coordinates*, Coordinates*> mymap;
  mymap[c1] = c1;
  Coordinates* ctemp = mymap.find(c1)->second;
  ctemp->getX();
  cout << "test" << rand()%5 <<endl;
  Coordinates* ctemp1 = mymap.find(c2)->second;
  cout << "toto" << rand()%5 << endl;
  cout << &ctemp1 << endl;
  if(mymap.find(c1) == mymap.end())
	cout << "yeah" << endl;
  else
	cout << "youhou" << endl;
//  mymap.find(c1);
  cout << ctemp->getX() << endl;
//  cout << mymap[c2] << endl;
  vector<int> c;
  c.push_back(1);
  c.push_back(3);
  c.push_back(10);
  if(find(c.begin(), c.end(), 4) != c.end())
	cout<< "trouve" << endl;
  else
	cout << "pas trouve" << endl;
  return 0;
}

