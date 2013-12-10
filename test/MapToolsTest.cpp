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
}

void MapToolsTest::tearDown() {
}

void MapToolsTest::testNextForwardPos()
{
   Coordinates c( 1 , 1 ); 
   Coordinates s( 1 , 2 ); 
   Coordinates w( 0 , 1 ); 
   Coordinates e( 2 , 1 ); 

  CPPUNIT_ASSERT( *MapTools::nextForwardPosition( &c , Direction::NORTH ) == Coordinates( 1 , 0 ) );
  CPPUNIT_ASSERT( *MapTools::nextForwardPosition( &c , Direction::SOUTH ) == s );
  CPPUNIT_ASSERT( *MapTools::nextForwardPosition( &c , Direction::WEST ) == w );
  CPPUNIT_ASSERT_EQUAL(2, MapTools::nextForwardPosition(&c , Direction::EAST)->getX());
  CPPUNIT_ASSERT_EQUAL(1, MapTools::nextForwardPosition( &c , Direction::EAST )->getY());

}
void MapToolsTest::testNextBackwardPos()
{
   Coordinates c( 0 , 0 );  

  CPPUNIT_ASSERT( *MapTools::nextBackwardPosition( &c , Direction::NORTH ) == Coordinates(0 , 1 ) );
  CPPUNIT_ASSERT( *MapTools::nextBackwardPosition( &c , Direction::SOUTH ) == Coordinates(0 ,-1 ) );
  CPPUNIT_ASSERT( *MapTools::nextBackwardPosition( &c , Direction::EAST ) == Coordinates(-1 , 0 ) );
  CPPUNIT_ASSERT( *MapTools::nextBackwardPosition( &c , Direction::WEST ) == Coordinates( 1 , 0 ) );

}

void MapToolsTest::testCounterclockwise(){
  CPPUNIT_ASSERT(MapTools::counterclockwise(Direction::NORTH) == Direction::WEST);
  CPPUNIT_ASSERT(MapTools::counterclockwise(Direction::SOUTH) == Direction::EAST);
  CPPUNIT_ASSERT(MapTools::counterclockwise(Direction::EAST) == Direction::NORTH);
  CPPUNIT_ASSERT_EQUAL(Direction::SOUTH, MapTools::counterclockwise(Direction::WEST));

}
void MapToolsTest::testClockwise(){
  CPPUNIT_ASSERT(MapTools::clockwise(Direction::NORTH) == Direction::EAST);
  CPPUNIT_ASSERT(MapTools::clockwise(Direction::EAST) == Direction::SOUTH);
  CPPUNIT_ASSERT(MapTools::clockwise(Direction::SOUTH) == Direction::WEST);
  CPPUNIT_ASSERT_EQUAL(Direction::NORTH, MapTools::clockwise(Direction::WEST));

}
