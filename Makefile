CPP = g++

default: main

all: main test

main: src/main.cpp build/Coordinates.o build/LandSensor.o build/Land.o build/MapTools.o build/RoadBook.o
		$(CPP) -o build/main src/main.cpp build/Coordinates.o build/LandSensor.o build/Land.o build/MapTools.o build/RoadBook.o

build/Coordinates.o: src/Coordinates.cpp src/Coordinates.h
		$(CPP) -c src/Coordinates.cpp -o build/Coordinates.o

build/LandSensor.o: src/LandSensor.cpp src/LandSensor.h src/Error.h build/Coordinates.o build/Land.o
		$(CPP) -c src/LandSensor.cpp -o build/LandSensor.o 

build/Land.o: src/Land.cpp src/Land.h src/Error.h
		$(CPP) -c src/Land.cpp -o build/Land.o

build/MapTools.o: src/MapTools.h src/MapTools.cpp src/Direction.h build/Coordinates.o
		$(CPP) -c src/MapTools.cpp -o build/MapTools.o

build/RoadBook.o: src/RoadBook.h src/RoadBook.cpp src/Instruction.h
		$(CPP) -c src/RoadBook.cpp -o build/RoadBook.o

test: test/TestRunner.cpp build-test/CoordinatesTest.o build-test/LandSensorTest.o build-test/MapToolsTest.o build-test/RoadBookTest.o build/Land.o build/LandSensor.o build/Coordinates.o build/MapTools.o buid/RoadBook.o
		$(CPP) -o build-test/test test/TestRunner.cpp build-test/CoordinatesTest.o build/Coordinates.o build-test/LandSensorTest.o build/LandSensor.o build/Land.o build/MapTools.o build-test/MapToolsTest.o build/RoadBook.o build-test/RoadBookTest.o -lcppunit

build-test/BatteryTest.o: test/BatteryTest.cpp test/BatteryTest.h
		$(CPP) -c test/BatteryTest.cpp -o build-test/BatteryTest.o -lcppunit

build-test/LandSensorTest.o: test/LandSensorTest.cpp test/LandSensorTest.h build/LandSensor.o build/Land.o build/Coordinates.o
		$(CPP) -c test/LandSensorTest.cpp build/Coordinates.o build/LandSensor.o build/Land.o -o build-test/LandSensorTest.o -lcppunit

build-test/CoordinatesTest.o: test/CoordinatesTest.cpp test/CoordinatesTest.h build/Coordinates.o
		$(CPP) -c test/CoordinatesTest.cpp build/Coordinates.o -o build-test/CoordinatesTest.o -lcppunit

build-test/MapToolsTest.o: test/MapToolsTest.cpp test/MapToolsTest.h build/Coordinates.o build/MapTools.o src/Direction.h
		$(CPP) -c test/MapToolsTest.cpp build/MapTools.o build/Coordinates.o -o build-test/MapToolsTest.o

build-test/RoadBookTest.o: test/RoadBookTest.cpp test/RoadBookTest.h build/RoadBook.o src/Instruction.h
		$(CPP) -c test/RoadBookTest.cpp build/RoadBook.o -o build-test/RoadBookTest.o
clean:
		rm -rf build/* build-test/* src/*.*~ src/*.*~

run-test: test
		./build-test/test

run: main
		./build/main
