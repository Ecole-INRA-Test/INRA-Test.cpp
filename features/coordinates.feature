# language: en
Feature: Coordinates
 
  I want to verify that the coordinates

  Scenario Outline: Move the robot in any directions
    Given I have a coordinates (X : <position_x_1>, Y : <position_y_1>)
    Then the coordinates are (X : <position_x_2>, Y : <position_y_2>)

  Examples:
    | position_x_1 | position_y_1 | doSomething | position_x_2 | position_y_2 |
    | 5                           | 5                           | getX, getY        | 5                          | 5                           |
  
