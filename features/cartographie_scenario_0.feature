# language: en
Feature: Robot
 
  The map can only be done in the floor.

  Scenario: Get the map during the fly
    Given a robot flying
    When I press cartographier
    Then I get the exception UNLANDED_ROBOT : 6

