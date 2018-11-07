#include "Robot.h"
#include "events/EventScheduler.h"
#include "events/JoystickButton.h"
#include "events/JoystickChannel.h"

// Include commands and command groups here
#include "commands/ExampleCommand.h"
#include "commands/ExampleCommandGroup.h"
#include "commands/LoopPID.h"
#include "commands/StopBase.h"
#include "commands/DriveWithJoy.h"
#include "commands/AutonGroup1.h"

Robot* Robot::instance = 0;

// Define pointers to subsystems here
Base*  Robot::base = 0;

Robot::Robot() {
  printf("Overridden robot constructor!\n");
  // Initialize any subsystems
  base = Base::getInstance();

  // Initialize joystick buttons and channels
  JoystickChannel* leftY = new JoystickChannel(MainJoystick, ChRightY);
  JoystickChannel* rightY = new JoystickChannel(MainJoystick, ChLeftY);
  //JoystickButton* exampleJoystickButton = new JoystickButton(MainJoystick, Btn5U);

  // Add commands to buttons and channels when certain events occur
  leftY->whilePastThreshold(new DriveWithJoy());
  rightY->whilePastThreshold(new DriveWithJoy());
  //exampleJoystickChannel->whilePastThreshold(new ExampleCommand());
  //exampleJoystickButton->whenPressed(new ExampleCommandGroup());
}

void Robot::robotInit() {
  //printf("Robot created.\n");
}

void Robot::autonInit() {
  // Initialize any commands to run throughout auton
  LoopPID* loopPID = new LoopPID();
  loopPID->run();

  AutonGroup1* autonGroup1 = new AutonGroup1();
  autonGroup1->run();
}

void Robot::autonPeriodic() {
  EventScheduler::getInstance()->update();
  Motor::periodicUpdate();
}

void Robot::teleopInit() {
  // Initialize any commands to run throughout teleop
  LoopPID* loopPID = new LoopPID();
  loopPID->run();
}

void Robot::teleopPeriodic() {
  EventScheduler::getInstance()->update();
  Motor::periodicUpdate();
}

void Robot::disabledInit() {
}

void Robot::disabledPeriodic() {
}

Robot* Robot::getInstance() {
    if (instance == NULL) {
        instance = new Robot();
    }
    return instance;
}
