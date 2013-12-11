# language: en
Feature: Robot
 
  I want to verify that the robot move correctly

  Scenario Outline: Move the robot in any directions
    Given I have land the robot in X : <position_x_1>, Y : <position_y_1> on the planet
    When I press <doSomething>
    Then the robot is in X : <position_x_2>, Y : <position_y_2>

  Examples:
    | position_x_1 | position_y_1 | doSomething | position_x_2 | position_y_2 |
    | 5                           | 5                           | moveForward | 5                          | 4                          |
    | 0                           | 0                           | moveForward | 0                          | -1                          |
