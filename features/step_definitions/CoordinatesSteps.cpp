#include <boost/test/unit_test.hpp>
#include <cucumber-cpp/defs.hpp>

#include <Coordinates.h>

using cucumber::ScenarioScope;

struct CoordinatesCtx {
  Coordinates* c;
  int x_result;
  int y_result;
};

GIVEN("^I have a coordinates (X : (\\d+), Y : (\\d+))$") {
    REGEX_PARAM(int, x);
    REGEX_PARAM(int, y);
    ScenarioScope<CoordinatesCtx> context;
    context->c = new Coordinates(x, y);
}

THEN("^the coordinates are (X : (.*), Y : (.*))$") {
    REGEX_PARAM(int, expected_x);
    REGEX_PARAM(int, expected_y);

    ScenarioScope<CoordinatesCtx> context;
    context->x_result = context->c->getX();
    context->y_result = context->c->getY();

    BOOST_CHECK_EQUAL(expected_x, context->x_result);
    BOOST_CHECK_EQUAL(expected_y, context->y_result);
}
