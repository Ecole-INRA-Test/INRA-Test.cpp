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
  CPPUNIT_ASSERT(MapTools::nextForwardPosition(robotCoordinates, Direction::NORTH)->getX() == oracleCoordinates->getX() and MapTools::nextForwardPosition(robotCoordinates, Direction::NORTH)->getY() == oracleCoordinates->getY()); //Test du cas NORTH
  oracleCoordinates = new Coordinates(5, 4);
  CPPUNIT_ASSERT(MapTools::nextForwardPosition(robotCoordinates, Direction::SOUTH)->getX() == oracleCoordinates->getX() and MapTools::nextForwardPosition(robotCoordinates, Direction::SOUTH)->getY() == oracleCoordinates->getY()); //Test du cas SOUTH
  oracleCoordinates = new Coordinates(6, 5);
  CPPUNIT_ASSERT(MapTools::nextForwardPosition(robotCoordinates, Direction::EAST)->getX() == oracleCoordinates->getX() and MapTools::nextForwardPosition(robotCoordinates, Direction::EAST)->getY() == oracleCoordinates->getY()); //Test du cas EAST
  oracleCoordinates = new Coordinates(4, 5);
  CPPUNIT_ASSERT(MapTools::nextForwardPosition(robotCoordinates,Direction::WEST)->getX() == oracleCoordinates->getX() and MapTools::nextForwardPosition(robotCoordinates, Direction::WEST)->getY() == oracleCoordinates->getY()); //Test du cas WEST
}

void MapToolsTest::nextBackwardPositionTest_NORTH() {
  oracleCoordinates = new Coordinates(5, 4);
  CPPUNIT_ASSERT(MapTools::nextBackwardPosition(robotCoordinates, Direction::NORTH)->getX() == oracleCoordinates->getX() and MapTools::nextBackwardPosition(robotCoordinates, Direction::NORTH)->getY() == oracleCoordinates->getY());
}

void MapToolsTest::nextBackwardPositionTest_SOUTH() {
  oracleCoordinates = new Coordinates(5, 6);
  CPPUNIT_ASSERT(MapTools::nextBackwardPosition(robotCoordinates, Direction::SOUTH)->getX() == oracleCoordinates->getX() and MapTools::nextBackwardPosition(robotCoordinates, Direction::SOUTH)->getY() == oracleCoordinates->getY());
}

void MapToolsTest::nextBackwardPositionTest_EAST() {
  oracleCoordinates = new Coordinates(4, 5);
  CPPUNIT_ASSERT(MapTools::nextBackwardPosition(robotCoordinates, Direction::EAST)->getX() == oracleCoordinates->getX() and MapTools::nextBackwardPosition(robotCoordinates, Direction::EAST)->getY() == oracleCoordinates->getY());
}

void MapToolsTest::nextBackwardPositionTest_WEST() {
  oracleCoordinates = new Coordinates(6, 5);
  CPPUNIT_ASSERT(MapTools::nextBackwardPosition(robotCoordinates,Direction:: WEST)->getX() == oracleCoordinates->getX() and MapTools::nextBackwardPosition(robotCoordinates, Direction::WEST)->getY() == oracleCoordinates->getY());
}

void MapToolsTest::counterclockwiseTest_ALL(){
  CPPUNIT_ASSERT(MapTools::counterclockwise(Direction::NORTH) == Direction::WEST);
  CPPUNIT_ASSERT(MapTools::counterclockwise(Direction::WEST) == Direction::SOUTH);
  CPPUNIT_ASSERT(MapTools::counterclockwise(Direction::SOUTH) == Direction::EAST);
  CPPUNIT_ASSERT(MapTools::counterclockwise(Direction::EAST) == Direction::NORTH);
}

void MapToolsTest::clockwiseTest_ALL(){
  CPPUNIT_ASSERT(MapTools::clockwise(Direction::NORTH) == Direction::EAST);
  CPPUNIT_ASSERT(MapTools::clockwise(Direction::EAST) == Direction::SOUTH);
  CPPUNIT_ASSERT(MapTools::clockwise(Direction::SOUTH) == Direction::WEST);
  CPPUNIT_ASSERT(MapTools::clockwise(Direction::WEST) == Direction::NORTH);
}
