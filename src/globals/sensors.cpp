#include "main.h"
#include "chassis.h"
#include "globals.h"

// Encoders
pros::ADIEncoder encoderLeft(ENC_LEFT_TOP, ENC_LEFT_BOT);
pros::ADIEncoder encoderRight(ENC_RIGHT_TOP, ENC_RIGHT_BOT);

// IMU
pros::IMU myImu(IMU_PORT);

// Potentiometer
pros::ADIAnalogIn pot(POT_PORT);

/*
// Accel
pros::ADIAnalogIn accel_z(ACCEL_Z);
*/