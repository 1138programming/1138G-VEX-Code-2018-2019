#include "commands/StopBase.h"
#include "Robot.h"

StopBase::StopBase() {
  // Add all requirements using requires()
  requires(Robot::base);

  // Set the command's priority
  this->priority = DefaultCommandPriority;
}

bool StopBase::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void StopBase::initialize() {
  // Perform any initialization steps for this command here, not in the constructor
  Robot::base->disablePID();
  Robot::base->move(0, 0);
}

void StopBase::execute() {
  // Code that runs when this command is scheduled to run
}

bool StopBase::isFinished() {
  return true; // This is the default value anyways, so this method can be removed
}

void StopBase::end() {
  // Code that runs when isFinished() returns true.
}

void StopBase::interrupted() {
  // Code that runs when this command is interrupted by another one with a higher priority.
}
