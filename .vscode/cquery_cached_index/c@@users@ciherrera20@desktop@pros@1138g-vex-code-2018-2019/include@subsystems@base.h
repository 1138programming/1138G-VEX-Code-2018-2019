#include "abstractBaseClasses/PIDController.h"

#ifndef EXAMPLESUBSYSTEM_H
#define EXAMPLESUBSYSTEM_H

#include "main.h"

class Base : public Subsystem {
  private:
    static Base* instance;

    // Base motors
    Motor* leftMotor1;
    Motor* leftMotor2;
    Motor* leftMotor3;
    Motor* leftMotor4;

    Motor* rightMotor1;
    Motor* rightMotor2;
    Motor* rightMotor3;
    Motor* rightMotor4;

    // Base encoder
    //Encoder exampleEncoder;

    // Base PIDControllers
    //PIDController* exampleSubsystemController;
    PIDController* leftController;
    PIDController* rightController;

    Base();
  public:
    void initDefaultCommand();
    void move(int leftSpeed, int rightSpeed);

    // PID functions
    void setSetpoint(int leftSetpoint, int rightSetpoint);
    void setSetpointRelative(int leftSetpoint, int rightSetpoint);
    bool atSetpoint();
    void disablePID(); // PID starts off disabled
    void enablePID();

    static Base* getInstance();
};

#endif
