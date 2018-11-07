#include "commands/MoveBaseTo.h"
#include "Robot.h"

MoveBaseTo::MoveBaseTo(int leftSetpoint, int rightSetpoint, bool absolute) {
  // Add all requirements using requires()
  requires(Robot::base);

  // Initialize variables
  this->leftSetpoint = leftSetpoint;
  this->rightSetpoint = rightSetpoint;
  this->absolute = absolute;

  // Set the command's priority
  this->priority = 1;
}

bool MoveBaseTo::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void MoveBaseTo::initialize() {
  // Perform any initialization steps for this command here, not in the constructor
  Robot::base->enablePID();
  if (absolute) {
    Robot::base->setSetpoint(leftSetpoint, rightSetpoint);
  } else {
    Robot::base->setSetpointRelative(leftSetpoint, rightSetpoint);
  }
}

void MoveBaseTo::execute() {
  // Code that runs when this command is scheduled to run
}

bool MoveBaseTo::isFinished() {
  return Robot::base->atSetpoint(); // This is the default value anyways, so this method can be removed
}

void MoveBaseTo::end() {
  // Code that runs when isFinished() returns true.
  Robot::base->disablePID();
}

void MoveBaseTo::interrupted() {
  // Code that runs when this command is interrupted by another one with a higher priority.
  Robot::base->disablePID();
}
