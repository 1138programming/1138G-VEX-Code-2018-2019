#include "main.h"
#include "subsystems/Base.h"

// Include the default command or command group
#include "commands/StopBase.h"

Base* Base::instance = 0;

Base::Base() {
  // Get Base motors
  rightMotor1 = Motor::getMotor(rightMotor1Port);
  rightMotor2 = Motor::getMotor(rightMotor2Port);
  rightMotor3 = Motor::getMotor(rightMotor3Port);
  rightMotor4 = Motor::getMotor(rightMotor4Port);

  leftMotor1 = Motor::getMotor(leftMotor1Port);
  leftMotor2 = Motor::getMotor(leftMotor2Port);
  leftMotor3 = Motor::getMotor(leftMotor3Port);
  leftMotor4 = Motor::getMotor(leftMotor4Port);

  // Reverse motors as necessary
  //exampleMotor2->reverse();

  // Slave motors as necessary
  //exampleMotor1->addFollower(exampleMotor2);
  leftMotor1->addFollower(leftMotor2);
  leftMotor1->addFollower(leftMotor3);
  leftMotor1->addFollower(leftMotor4);

  rightMotor1->addFollower(rightMotor2);
  rightMotor1->addFollower(rightMotor3);
  rightMotor1->addFollower(rightMotor4);

  // Initialize encoders
  //exampleEncoder = encoderInit(exampleEncoderTopPort, exampleEncoderBottomPort, true);

  // Set up PID controllers
  //exampleSubsystemController = new PIDController(exampleMotor1, 0.32, 0, 0.05);
  leftController = new PIDController(leftMotor1, 0.2, 0, 0);
  rightController = new PIDController(rightMotor1, 0.2, 0, 0);

  leftController->setSensorIME(leftIME1Address);
  rightController->setSensorIME(rightIME1Address);

  leftController->setThreshold(30);
  rightController->setThreshold(30);
  // Set PID controller sensors
  //exampleSubsystemController->setSensorEncoder(exampleEncoder);
  // Alternatively, the PID controller can use an IME:
  // exampleSubsystemController->setSensorIME(exampleIMEAddress);
}

void Base::initDefaultCommand() {
  setDefaultCommand(new StopBase());
}

void Base::move(int leftSpeed, int rightSpeed) {
  leftSpeed = threshold((int)leftSpeed);
  rightSpeed = threshold((int)rightSpeed);

  leftMotor1->setSpeed(leftSpeed);
  rightMotor1->setSpeed(rightSpeed);
}

void Base::setSetpoint(int leftSetpoint, int rightSetpoint) {
  leftController->setSetpoint(leftSetpoint);
  rightController->setSetpoint(rightSetpoint);
}

void Base::setSetpointRelative(int leftSetpoint, int rightSetpoint) {
  leftController->setSetpointRelative(leftSetpoint);
  rightController->setSetpointRelative(rightSetpoint);
}

bool Base::atSetpoint() {
  return leftController->atSetpoint() && rightController->atSetpoint();
}

void Base::disablePID() {
  //exampleSubsystemController->enabled = false;
  leftController->enabled = false;
  rightController->enabled = false;
}

void Base::enablePID() {
  //exampleSubsystemController->enabled = true;
  leftController->enabled = true;
  rightController->enabled = true;
}

Base* Base::getInstance() {
    if (instance == 0) {
      instance = new Base();
    }

    return instance;
}
