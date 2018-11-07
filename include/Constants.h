/**
 * @file Constants.h
 * @brief Provides constants used throughout the entire code. Contains user-readable motor names
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define DEFAULT_TASK_TIME 10000
#define DELAY_TIME 10
#define MAX_MOTORS 29
#define MAX_FOLLOWERS 3

// Motor ports
const int leftMotor1Port = 1;
const int leftMotor2Port = 2;
const int leftMotor3Port = 3;
const int leftMotor4Port = 4;

const int rightMotor1Port = 5;
const int rightMotor2Port = 6;
const int rightMotor3Port = 7;
const int rightMotor4Port = 8;

//Motor and encoder constants
const int KMaxMotorSpeed = 127;
const int KMaxJoystickValue = 127;
const int encoderTicks = 360; // Encoder ticks in one revolution
const float rotationsPerInch = 31.400156410256; // TODO check if this is correct

// IME addresses
//const unsigned char exampleIMEAddress = 0;
const unsigned char leftIME1Address = 1;
const unsigned char leftIME2Address = 2;

const unsigned char rightIME1Address = 3;
const unsigned char rightIME2Address = 4;

// Encoder ports
const int exampleEncoderTopPort = 0;
const int exampleEncoderBottomPort = 1;

// Global things that we need

#endif
