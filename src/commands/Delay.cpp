#include "commands/Delay.h"
#include "Robot.h"

Delay::Delay(unsigned int duration) {
  // Add all requirements using requires()
  //requires(Robot::exampleSubsystem);

  // Initialize variables
  this->duration = duration;

  // Set the command's priority
  this->priority = DefaultCommandPriority;
}

bool Delay::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void Delay::initialize() {
  // Perform any initialization steps for this command here, not in the constructor
  this->startTime = millis();
}

void Delay::execute() {
  // Code that runs when this command is scheduled to run
}

bool Delay::isFinished() {
  return millis() - startTime > duration; // This is the default value anyways, so this method can be removed
}

void Delay::end() {
  // Code that runs when isFinished() returns true.
}

void Delay::interrupted() {
  // Code that runs when this command is interrupted by another one with a higher priority.
}
