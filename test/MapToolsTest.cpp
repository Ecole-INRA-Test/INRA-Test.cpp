/*
 * File:   MapToolsTest.cpp
 * Author: pepi2013
 *
 * Created on 30 nov. 2013, 15:50:34
 */

#include "MapToolsTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(MapToolsTest);

MapToolsTest::MapToolsTest() {
}

MapToolsTest::~MapToolsTest() {
}

void MapToolsTest::setUp() {
  robotCoordinates = new Coordinates(5, 5);
}

void MapToolsTest::tearDown() {
}


void MapToolsTest::nextForwardPositionTest_ALL() {
  oracleCoordinates = new Coordinates(5, 6);
  CPPUNIT_ASSERT(MapTools::nextForwardPosition(robotCoordinates, NORTH)->getX() == oracleCoordinates->getX() and MapTools::nextForwardPosition(robotCoordinates, NORTH)->getY() == oracleCoordinates->getY()); //Test du cas NORTH
  oracleCoordinates = new Coordinates(5, 4);
  CPPUNIT_ASSERT(MapTools::nextForwardPosition(robotCoordinates, SOUTH)->getX() == oracleCoordinates->getX() and MapTools::nextForwardPosition(robotCoordinates, SOUTH)->getY() == oracleCoordinates->getY()); //Test du cas SOUTH
  oracleCoordinates = new Coordinates(6, 5);
  CPPUNIT_ASSERT(MapTools::nextForwardPosition(robotCoordinates, EAST)->getX() == oracleCoordinates->getX() and MapTools::nextForwardPosition(robotCoordinates, EAST)->getY() == oracleCoordinates->getY()); //Test du cas EAST
  oracleCoordinates = new Coordinates(4, 5);
  CPPUNIT_ASSERT(MapTools::nextForwardPosition(robotCoordinates,WEST)->getX() == oracleCoordinates->getX() and MapTools::nextForwardPosition(robotCoordinates, WEST)->getY() == oracleCoordinates->getY()); //Test du cas WEST
}

void MapToolsTest::nextBackwardPositionTest_NORTH() {
  oracleCoordinates = new Coordinates(5, 4);
  CPPUNIT_ASSERT(MapTools::nextBackwardPosition(robotCoordinates, NORTH)->getX() == oracleCoordinates->getX() and MapTools::nextBackwardPosition(robotCoordinates, NORTH)->getY() == oracleCoordinates->getY());
}

void MapToolsTest::nextBackwardPositionTest_SOUTH() {
  oracleCoordinates = new Coordinates(5, 6);
  CPPUNIT_ASSERT(MapTools::nextBackwardPosition(robotCoordinates, SOUTH)->getX() == oracleCoordinates->getX() and MapTools::nextBackwardPosition(robotCoordinates, SOUTH)->getY() == oracleCoordinates->getY());
}

void MapToolsTest::nextBackwardPositionTest_EAST() {
  oracleCoordinates = new Coordinates(4, 5);
  CPPUNIT_ASSERT(MapTools::nextBackwardPosition(robotCoordinates, EAST)->getX() == oracleCoordinates->getX() and MapTools::nextBackwardPosition(robotCoordinates, EAST)->getY() == oracleCoordinates->getY());
}

void MapToolsTest::nextBackwardPositionTest_WEST() {
  oracleCoordinates = new Coordinates(6, 5);
  CPPUNIT_ASSERT(MapTools::nextBackwardPosition(robotCoordinates, WEST)->getX() == oracleCoordinates->getX() and MapTools::nextBackwardPosition(robotCoordinates, WEST)->getY() == oracleCoordinates->getY());
}

void MapToolsTest::counterclockwiseTest_ALL(){
  CPPUNIT_ASSERT(MapTools::counterclockwise(NORTH) == WEST);
  CPPUNIT_ASSERT(MapTools::counterclockwise(WEST) == SOUTH);
  CPPUNIT_ASSERT(MapTools::counterclockwise(SOUTH) == EAST);
  CPPUNIT_ASSERT(MapTools::counterclockwise(EAST) == NORTH);
}

void MapToolsTest::clockwiseTest_ALL(){
  CPPUNIT_ASSERT(MapTools::clockwise(NORTH) == EAST);
  CPPUNIT_ASSERT(MapTools::clockwise(EAST) == SOUTH);
  CPPUNIT_ASSERT(MapTools::clockwise(SOUTH) == WEST);
  CPPUNIT_ASSERT(MapTools::clockwise(WEST) == NORTH);
}
