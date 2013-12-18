# language: en
Feature: Robot
 
	The map during the land is the same that the manual mapping 

  Scenario: Land the robot and get the map
    Given I have land the robot in X : 0, Y : 0 on the planet
    When I press cartographier
    Then we have the same map

