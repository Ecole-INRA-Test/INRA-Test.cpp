CPP = g++

default: main

all: main test

main: src/main.cpp build/Coordinates.o build/LandSensor.o build/Land.o
		$(CPP) -o build/main src/main.cpp build/Coordinates.o build/LandSensor.o build/Land.o

build/Coordinates.o: src/Coordinates.cpp src/Coordinates.h
		$(CPP) -c src/Coordinates.cpp -o build/Coordinates.o

build/LandSensor.o: src/LandSensor.cpp src/LandSensor.h src/Error.h build/Coordinates.o build/Land.o
		$(CPP) -c src/LandSensor.cpp build/Coordinates.o build/Land.o -o build/LandSensor.o 

build/Land.o: src/Land.cpp src/Land.h src/Error.h
		$(CPP) -c src/Land.cpp -o build/Land.o

test: test/TestRunner.cpp build-test/CoordinatesTest.o build-test/LandSensorTest.o build/Land.o build/LandSensor.o build/Coordinates.o
		$(CPP) -o build-test/test test/TestRunner.cpp build-test/CoordinatesTest.o build/Coordinates.o build-test/LandSensorTest.o build/LandSensor.o build/Land.o -lcppunit

build-test/BatteryTest.o: test/BatteryTest.cpp test/BatteryTest.h
		$(CPP) -c test/BatteryTest.cpp -o build-test/BatteryTest.o -lcppunit

build-test/LandSensorTest.o: test/LandSensorTest.cpp test/LandSensorTest.h build/LandSensor.o build/Land.o build/Coordinates.o
		$(CPP) -c test/LandSensorTest.cpp build/Coordinates.o build/LandSensor.o build/Land.o -o build-test/LandSensorTest.o -lcppunit

build-test/CoordinatesTest.o: test/CoordinatesTest.cpp test/CoordinatesTest.h build/Coordinates.o
		$(CPP) -c test/CoordinatesTest.cpp build/Coordinates.o -o build-test/CoordinatesTest.o -lcppunit

clean:
		rm -rf build/* build-test/* src/*.*~ src/*.*~

run-test: test
		./build-test/test

run: main
		./build/main
