# language: en
Feature: Robot
 
  The map is controlled and we land the robot in the center to use it.

  Scenario: Map controlled and use it
    Given A specific land
    And a coordinate X : -4, Y : -4 the land is 0
    And a coordinate X : -3, Y : -4 the land is 0
    And a coordinate X : -2, Y : -4 the land is 0
    And a coordinate X : -1, Y : -4 the land is 0
    And a coordinate X : 0, Y : -4 the land is 0
    And a coordinate X : 1, Y : -4 the land is 0
    And a coordinate X : 2, Y : -4 the land is 0
    And a coordinate X : 3, Y : -4 the land is 0
    And a coordinate X : 4, Y : -4 the land is 0
    And a coordinate X : -4, Y : -3 the land is 0
    And a coordinate X : -3, Y : -3 the land is 0
    And a coordinate X : -2, Y : -3 the land is 0
    And a coordinate X : -1, Y : -3 the land is 0
    And a coordinate X : 0, Y : -3 the land is 0
    And a coordinate X : 1, Y : -3 the land is 0
    And a coordinate X : 2, Y : -3 the land is 0
    And a coordinate X : 3, Y : -3 the land is 0
    And a coordinate X : 4, Y : -3 the land is 0
    And a coordinate X : -4, Y : -2 the land is 0
    And a coordinate X : -3, Y : -2 the land is 0
    And a coordinate X : -2, Y : -2 the land is 0
    And a coordinate X : -1, Y : -2 the land is 0
    And a coordinate X : 0, Y : -2 the land is 0
    And a coordinate X : 1, Y : -2 the land is 0
    And a coordinate X : 2, Y : -2 the land is 0
    And a coordinate X : 3, Y : -2 the land is 0
    And a coordinate X : 4, Y : -2 the land is 0
    And a coordinate X : -4, Y : -1 the land is 0
    And a coordinate X : -3, Y : -1 the land is 0
    And a coordinate X : -2, Y : -1 the land is 0
    And a coordinate X : -1, Y : -1 the land is 0
    And a coordinate X : 0, Y : -1 the land is 0
    And a coordinate X : 1, Y : -1 the land is 0
    And a coordinate X : 2, Y : -1 the land is 0
    And a coordinate X : 3, Y : -1 the land is 0
    And a coordinate X : 4, Y : -1 the land is 0
    And a coordinate X : -4, Y : 0 the land is 0
    And a coordinate X : -3, Y : 0 the land is 0
    And a coordinate X : -2, Y : 0 the land is 0
    And a coordinate X : -1, Y : 0 the land is 0
    And a coordinate X : 0, Y : 0 the land is 0
    And a coordinate X : 1, Y : 0 the land is 0
    And a coordinate X : 2, Y : 0 the land is 0
    And a coordinate X : 3, Y : 0 the land is 0
    And a coordinate X : 4, Y : 0 the land is 0
    And a coordinate X : -4, Y : 1 the land is 0
    And a coordinate X : -3, Y : 1 the land is 0
    And a coordinate X : -2, Y : 1 the land is 0
    And a coordinate X : -1, Y : 1 the land is 0
    And a coordinate X : 0, Y : 1 the land is 0
    And a coordinate X : 1, Y : 1 the land is 0
    And a coordinate X : 2, Y : 1 the land is 0
    And a coordinate X : 3, Y : 1 the land is 0
    And a coordinate X : 4, Y : 1 the land is 0
    And a coordinate X : -4, Y : 2 the land is 0
    And a coordinate X : -3, Y : 2 the land is 0
    And a coordinate X : -2, Y : 2 the land is 0
    And a coordinate X : -1, Y : 2 the land is 0
    And a coordinate X : 0, Y : 2 the land is 0
    And a coordinate X : 1, Y : 2 the land is 0
    And a coordinate X : 2, Y : 2 the land is 0
    And a coordinate X : 3, Y : 2 the land is 0
    And a coordinate X : 4, Y : 2 the land is 0
    And a coordinate X : -4, Y : 3 the land is 0
    And a coordinate X : -3, Y : 3 the land is 0
    And a coordinate X : -2, Y : 3 the land is 0
    And a coordinate X : -1, Y : 3 the land is 0
    And a coordinate X : 0, Y : 3 the land is 0
    And a coordinate X : 1, Y : 3 the land is 0
    And a coordinate X : 2, Y : 3 the land is 0
    And a coordinate X : 3, Y : 3 the land is 0
    And a coordinate X : 4, Y : 3 the land is 0
    And a coordinate X : -4, Y : 4 the land is 0
    And a coordinate X : -3, Y : 4 the land is 0
    And a coordinate X : -2, Y : 4 the land is 0
    And a coordinate X : -1, Y : 4 the land is 0
    And a coordinate X : 0, Y : 4 the land is 0
    And a coordinate X : 1, Y : 4 the land is 0
    And a coordinate X : 2, Y : 4 the land is 0
    And a coordinate X : 3, Y : 4 the land is 0
    And a coordinate X : 4, Y : 4 the land is 0
    And a robot landed in X : 0, Y : 0 on the planet
    When I press moveForward
    And I press moveBackward
    And I press cartographier
    Then we have the same map
    And I have 9 rows
