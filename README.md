# Sumo-Bot
Sumo Robot Attack and Search Arduino Code

This is the Arduino Code for the sensors, motors as well as the Attack and Searching controls for the Sumo-bot. 

The Searching command forces the robot to stop and rotate 360 degrees to search for a target using the ultrasonic sensors. Once a target has been found, the robot shifts to the Attacking command. 
The Attacking command forces the robot to move towards the target at 100% power to push it out of bounds of the arena. 
If in any of these commands the infrared sensor on the sumo-bot detects a white line (arena boundary) the sumo-bot immediate reverses direction, backs up a few centimetres and rotates in a different direction so that it does not travel out of bounds. 
