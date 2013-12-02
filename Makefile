CPP = g++

default: main

all: main test

main: src/main.cpp build/Coordinates.o
		$(CPP) -o build/main src/main.cpp build/Coordinates.o

#main: main.cpp RoadBook.o MapTools.o Coordinates.o Battery.o LandSensor.o Direction.h Instruction.h
#		$(CPP) -o main main.cpp MapTools.o Coordinates.o Battery.o LandSensor.o
#
##RoadBookCalculator.o: RoadBookCalculator.cpp RoadBookCalculator.h MapTools.o RoadBook.o Instruction.h Direction.h
##		$(CPP) -c RoadBookCalculator.cpp RoadBook.o MapTools.o
#
#RoadBook.o: RoadBook.cpp RoadBook.h Instruction.h
#		$(CPP) -c RoadBook.cpp
#
#MapTools.o: MapTools.cpp MapTools.h Coordinates.o Direction.h
#		$(CPP) -c MapTools.cpp Coordinates.o
#
#LandSensor.o: LandSensor.cpp LandSensor.h Coordinates.o
#		$(CPP) -c LandSensor.cpp Coordinates.o
#
#Battery.o: Battery.cpp Battery.h
#		$(CPP) -c Battery.cpp

build/Coordinates.o: src/Coordinates.cpp src/Coordinates.h
		$(CPP) -c src/Coordinates.cpp -o build/Coordinates.o

test: test/TestRunner.cpp build-test/CoordinatesTest.o
		$(CPP) -o build-test/test test/TestRunner.cpp build-test/CoordinatesTest.o build/Coordinates.o -lcppunit

build-test/BatteryTest.o: test/BatteryTest.cpp test/BatteryTest.h
		$(CPP) -c test/BatteryTest.cpp -o build-test/BatteryTest.o -lcppunit

build-test/CoordinatesTest.o: test/CoordinatesTest.cpp build/Coordinates.o
		$(CPP) -c test/CoordinatesTest.cpp build/Coordinates.o -o build-test/CoordinatesTest.o -lcppunit

clean:
		rm -rf build/* build-test/* src/*.*~ src/*.*~

## build tests
#build-tests: .build-tests-post
#
#.build-tests-pre:
## Add your pre 'build-tests' code here...
#
#.build-tests-post: .build-tests-impl
## Add your post 'build-tests' code here...
#
#
## run tests
#test: .test-post
#
#.test-pre:
## Add your pre 'test' code here...
#
#.test-post: .test-impl
## Add your post 'test' code here...
