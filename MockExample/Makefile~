CPP = g++

COVERAGE = 
LCOV = 
default: main

all: main test

main: src/main.cpp build/Coordinates.o build/LandSensor.o build/Land.o build/MapTools.o build/RoadBook.o build/RoadBookCalculator.o build/Robot.o build/Battery.o build/Direction.o build/CheckPoint.o build/BlackBox.o build/InstructionListTool.o
		$(CPP) -o build/main src/main.cpp build/Coordinates.o build/LandSensor.o build/Land.o build/MapTools.o build/RoadBook.o build/RoadBookCalculator.o build/Robot.o build/Battery.o build/Direction.o build/CheckPoint.o build/BlackBox.o build/InstructionListTool.o

build/Coordinates.o: src/Coordinates.cpp src/Coordinates.h
		$(CPP) -c src/Coordinates.cpp -o build/Coordinates.o $(COVERAGE)

build/LandSensor.o: src/LandSensor.cpp src/LandSensor.h src/Error.h src/Coordinates.h src/Land.h
		$(CPP) -c src/LandSensor.cpp -o build/LandSensor.o  $(COVERAGE)

build/Land.o: src/Land.cpp src/Land.h src/Error.h
		$(CPP) -c src/Land.cpp -o build/Land.o $(COVERAGE)

build/MapTools.o: src/MapTools.h src/MapTools.cpp src/Direction.h src/Coordinates.h
		$(CPP) -c src/MapTools.cpp -o build/MapTools.o $(COVERAGE)

build/RoadBook.o: src/RoadBook.h src/RoadBook.cpp src/Instruction.h
		$(CPP) -c src/RoadBook.cpp -o build/RoadBook.o $(COVERAGE)

build/RoadBookCalculator.o: src/RoadBookCalculator.cpp src/RoadBookCalculator.h src/Instruction.h src/Direction.h src/RoadBook.h src/MapTools.h
		$(CPP) -c src/RoadBookCalculator.cpp -o build/RoadBookCalculator.o $(COVERAGE)

build/Robot.o: src/Robot.h src/Robot.cpp src/Error.h src/Coordinates.h src/Direction.h src/RoadBook.h src/LandSensor.h
		$(CPP) -c src/Robot.cpp -o build/Robot.o $(COVERAGE)

build/Battery.o: src/Battery.h src/Battery.cpp src/Error.h
		$(CPP) -c src/Battery.cpp -o build/Battery.o $(COVERAGE)

build/Direction.o: src/Direction.h src/Direction.cpp
		$(CPP) -c src/Direction.cpp -o build/Direction.o $(COVERAGE)

build/CheckPoint.o: src/CheckPoint.cpp src/CheckPoint.h
		$(CPP) -c src/CheckPoint.cpp -o build/CheckPoint.o $(COVERAGE)

build/BlackBox.o: src/BlackBox.cpp src/BlackBox.h
		$(CPP) -c src/BlackBox.cpp -o build/BlackBox.o $(COVERAGE)

build/InstructionListTool.o: src/InstructionListTool.cpp src/InstructionListTool.h
		$(CPP) -c src/InstructionListTool.cpp -o build/InstructionListTool.o $(COVERAGE)

test: test/TestRunner.cpp build-test/BlackBoxTest.o build-test/BatteryTest.o build-test/CoordinatesTest.o build-test/LandSensorTest.o build-test/MapToolsTest.o build-test/RoadBookTest.o build-test/RoadBookCalculatorTest.o build-test/RobotTest.o build-test/LandTest.o build/BlackBox.o build/Battery.o build/Land.o build/LandSensor.o build/Coordinates.o build/MapTools.o build/RoadBook.o build/RoadBookCalculator.o build/Robot.o build/Direction.o build/CheckPoint.o build/BlackBox.o build/InstructionListTool.o
		$(CPP) -I/home/pepi2013/gmock-1.7.0/include/ test/TestRunner.cpp build-test/BlackBoxTest.o build-test/BatteryTest.o build/Battery.o build-test/CoordinatesTest.o build/Coordinates.o build-test/LandSensorTest.o build/LandSensor.o build-test/LandTest.o build/Land.o build/MapTools.o build-test/MapToolsTest.o build/RoadBook.o build-test/RoadBookTest.o build/RoadBookCalculator.o build-test/RoadBookCalculatorTest.o build/Robot.o build-test/RobotTest.o build/Direction.o build/CheckPoint.o build/BlackBox.o build/InstructionListTool.o -L/home/pepi2013/gmock-1.7.0/build -lgmock -lpthread -lcppunit $(LCOV) -o build-test/test

build-test/BatteryTest.o: test/BatteryTest.cpp test/BatteryTest.h
		$(CPP) -c test/BatteryTest.cpp -o build-test/BatteryTest.o -lcppunit

build-test/LandSensorTest.o: test/LandSensorTest.cpp test/LandSensorTest.h src/LandSensor.h 
		$(CPP) -c test/LandSensorTest.cpp -o build-test/LandSensorTest.o -lcppunit

build-test/LandTest.o: test/LandTest.cpp test/LandTest.h src/Land.h 
		$(CPP) -c test/LandTest.cpp -o build-test/LandTest.o -lcppunit

build-test/CoordinatesTest.o: test/CoordinatesTest.cpp test/CoordinatesTest.h src/Coordinates.h
		$(CPP) -c test/CoordinatesTest.cpp -o build-test/CoordinatesTest.o -lcppunit

build-test/MapToolsTest.o: test/MapToolsTest.cpp test/MapToolsTest.h src/MapTools.h src/Direction.h
		$(CPP) -c test/MapToolsTest.cpp -o build-test/MapToolsTest.o -lcppunit

build-test/RoadBookTest.o: test/RoadBookTest.cpp test/RoadBookTest.h src/Instruction.h src/RoadBook.h
		$(CPP) -c test/RoadBookTest.cpp -o build-test/RoadBookTest.o -lcppunit

build-test/RoadBookCalculatorTest.o: test/RoadBookCalculatorTest.cpp test/RoadBookCalculatorTest.cpp 
		$(CPP) -c test/RoadBookCalculatorTest.cpp -o build-test/RoadBookCalculatorTest.o -lcppunit

build-test/RobotTest.o: test/RobotTest.cpp test/RobotTest.h src/Robot.h
		$(CPP) -c test/RobotTest.cpp -o build-test/RobotTest.o -lcppunit

build-test/BlackBoxTest.o: test/BlackBoxTest.cpp test/BlackBoxTest.h
		$(CPP) -c test/BlackBoxTest.cpp -o build-test/BlackBoxTest.o -lcppunit

clean:
		rm -rf build/* build-test/* src/*.*~ src/*.*~ *.gcov

run-test: test
		./build-test/test

run: main
		./build/main
