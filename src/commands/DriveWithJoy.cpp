#include "commands/DriveWithJoy.h"
#include "Robot.h"

DriveWithJoy::DriveWithJoy() {
  // Add all requirements using requires()
  requires(Robot::base);

  // Set the command's priority
  this->priority = 2;
}

bool DriveWithJoy::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void DriveWithJoy::initialize() {
  // Perform any initialization steps for this command here, not in the constructor
}

void DriveWithJoy::execute() {
  // Code that runs when this command is scheduled to run
  Robot::base->move(joystickGetAnalog(1, 2), joystickGetAnalog(1, 3));
}

bool DriveWithJoy::isFinished() {
  return true; // This is the default value anyways, so this method can be removed
}

void DriveWithJoy::end() {
  // Code that runs when isFinished() returns true.
}

void DriveWithJoy::interrupted() {
  // Code that runs when this command is interrupted by another one with a higher priority.
}
