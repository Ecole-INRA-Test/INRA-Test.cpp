project(Robot)

set(ROBOT_SOURCES
  src/Battery.cpp
  src/LandSensor.cpp
  src/BlackBox.cpp
  src/CheckPoint.cpp
  src/Coordinates.cpp
  src/Direction.cpp
  src/InstructionListTool.cpp
  src/Land.cpp
  src/MapTools.cpp
  src/RoadBook.cpp
  src/RoadBookCalculator.cpp    	
)

include_directories(${CUKE_INCLUDE_DIRS} src)

add_library(Robot STATIC ${ROBOT_SOURCES} src/Robot)

#
# Boost
#

if(MSVC11)
    # Boost 1.51 fixed a bug with MSVC11
    message(STATUS "Forcing Boost 1.51+ on MSVC11")
    set(BOOST_MIN_VERSION "1.51")
else()
    set(BOOST_MIN_VERSION "1.40")
endif()

set(CUKE_CORE_BOOST_LIBS thread system regex date_time)
if(NOT CUKE_DISABLE_BOOST_TEST)
    set(CUKE_TEST_BOOST_LIBS unit_test_framework)
endif()

if(CUKE_USE_STATIC_BOOST)
    set(CUKE_STATIC_BOOST_LIBS ${CUKE_CORE_BOOST_LIBS})
    # "An external test runner utility is required to link with dynamic library" (Boost User's Guide)
    set(CUKE_DYNAMIC_BOOST_LIBS ${CUKE_TEST_BOOST_LIBS})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DBOOST_TEST_DYN_LINK")

    if(NOT MSVC)
        find_package(Threads)
        set(CUKE_EXTRA_LIBRARIES ${CUKE_EXTRA_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
    endif()
else()
    set(CUKE_DYNAMIC_BOOST_LIBS ${CUKE_CORE_BOOST_LIBS} ${CUKE_TEST_BOOST_LIBS})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DBOOST_ALL_DYN_LINK")
endif()

if(CUKE_STATIC_BOOST_LIBS)
    set(Boost_USE_STATIC_LIBS ON)
    find_package(Boost ${BOOST_MIN_VERSION} COMPONENTS ${CUKE_STATIC_BOOST_LIBS})
endif()

if(CUKE_DYNAMIC_BOOST_LIBS)
    set(Boost_USE_STATIC_LIBS OFF)
    find_package(Boost ${BOOST_MIN_VERSION} COMPONENTS ${CUKE_DYNAMIC_BOOST_LIBS})
endif()

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    set(CUKE_EXTRA_LIBRARIES ${CUKE_EXTRA_LIBRARIES} ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_REGEX_LIBRARY} ${Boost_DATE_TIME_LIBRARY})
endif()

#
# Cucumber-Cpp
#

set(CUKE_LIBRARIES cucumber-cpp ${CUKE_EXTRA_LIBRARIES})

#
# GTest
#

if(NOT CUKE_DISABLE_GTEST)
    find_package(GTest)
    find_package(GMock)
    if(GMOCK_FOUND AND GTEST_FOUND)
        set(CUKE_TEST_LIBRARIES ${GTEST_LIBRARIES} ${GMOCK_BOTH_LIBRARIES})
        if(UNIX)
            find_package(Threads) # GTest needs this and it's a static library
            set(CUKE_TEST_LIBRARIES ${CUKE_TEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
        endif()
    endif()
endif()

if(GTEST_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS})
    add_executable(RobotSteps features/step_definitions/RobotSteps)
    target_link_libraries(RobotSteps Robot ${GTEST_LIBRARIES} ${CUKE_LIBRARIES})
endif()

