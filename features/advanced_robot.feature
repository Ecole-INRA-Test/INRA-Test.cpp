# language: en
Feature: Robot
 
  I want to verify that the robot move correctly

  Scenario: Move the robot in any directions
    Given I have land the robot in X : 5, Y : 5 on the planet
    When I press moveForward
    And I press moveBackward
    Then the robot is in X : 5, Y : 5

