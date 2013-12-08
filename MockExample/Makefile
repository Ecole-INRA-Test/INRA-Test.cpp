CPP = g++

COVERAGE = 
LCOV = 
default: main

all: main test

main: src/main.cpp build/Coordinates.o build/Robot.o build/Battery.o
		$(CPP) -o build/main src/main.cpp build/Coordinates.o build/Robot.o build/Battery.o

build/Coordinates.o: src/Coordinates.cpp src/Coordinates.h
		$(CPP) -c src/Coordinates.cpp -o build/Coordinates.o $(COVERAGE)

build/Robot.o: src/Robot.h src/Robot.cpp src/Error.h src/Coordinates.h
		$(CPP) -c src/Robot.cpp -o build/Robot.o $(COVERAGE)

build/Battery.o: src/Battery.h src/Battery.cpp src/Error.h
		$(CPP) -c src/Battery.cpp -o build/Battery.o $(COVERAGE)

test: test/TestRunner.cpp build-test/BatteryTest.o build-test/CoordinatesTest.o build-test/RobotTest.o build/Battery.o build/Coordinates.o build/Robot.o
		$(CPP) -I/home/pepi2013/gmock-1.7.0/include/ test/TestRunner.cpp build-test/BatteryTest.o build/Battery.o build-test/CoordinatesTest.o build/Coordinates.o build/Robot.o build-test/RobotTest.o -L/home/pepi2013/gmock-1.7.0/build -lgmock -lpthread -lcppunit $(LCOV) -o build-test/test

build-test/BatteryTest.o: test/BatteryTest.cpp test/BatteryTest.h
		$(CPP) -c test/BatteryTest.cpp -o build-test/BatteryTest.o -lcppunit

build-test/CoordinatesTest.o: test/CoordinatesTest.cpp test/CoordinatesTest.h src/Coordinates.h
		$(CPP) -c test/CoordinatesTest.cpp -o build-test/CoordinatesTest.o -lcppunit

build-test/RobotTest.o: test/RobotTest.cpp test/RobotTest.h src/Robot.h
		$(CPP) -c test/RobotTest.cpp -o build-test/RobotTest.o -lcppunit

clean:
		rm -rf build/* build-test/* src/*.*~ src/*.*~ *.gcov

run-test: test
		./build-test/test

run: main
		./build/main
