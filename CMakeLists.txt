project(Coordinates)

include_directories(${CUKE_INCLUDE_DIRS} src)

add_library(Coordinates src/Coordinates)

if(Boost_UNIT_TEST_FRAMEWORK_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(CoordinatesSteps features/step_definitions/CoordinatesSteps)
    target_link_libraries(CoordinatesSteps Coordinates ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${CUKE_LIBRARIES})
endif()
