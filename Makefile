CPP = g++

default: main

all: main test

main: src/main.cpp build/Coordinates.o build/LandSensor.o build/Land.o
		$(CPP) -o build/main src/main.cpp build/Coordinates.o build/LandSensor.o build/Land.o

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

build/LandSensor.o: src/LandSensor.cpp src/LandSensor.h
		$(CPP) -c src/LandSensor.cpp -o build/LandSensor.o 

build/Land.o: src/Land.cpp src/Land.h
		$(CPP) -c src/Land.cpp -o build/Land.o

test: test/TestRunner.cpp build-test/CoordinatesTest.o build-test/LandSensorTest.o
		$(CPP) -o build-test/test test/TestRunner.cpp build-test/CoordinatesTest.o build/Coordinates.o build-test/LandSensorTest.o build/LandSensor.o -lcppunit

build-test/BatteryTest.o: test/BatteryTest.cpp test/BatteryTest.h
		$(CPP) -c test/BatteryTest.cpp -o build-test/BatteryTest.o -lcppunit

build-test/LandSensorTest.o: test/LandSensorTest.cpp test/LandSensorTest.h build/LandSensor.o
		$(CPP) -c test/LandSensorTest.cpp build/LandSensor.o -o build-test/LandSensorTest.o -lcppunit

build-test/CoordinatesTest.o: test/CoordinatesTest.cpp test/CoordinatesTest.h build/Coordinates.o
		$(CPP) -c test/CoordinatesTest.cpp build/Coordinates.o -o build-test/CoordinatesTest.o -lcppunit

clean:
		rm -rf build/* build-test/* src/*.*~ src/*.*~

run-test: test
		./build-test/test

run: main
		./build/main
