#include "main.h"
#include "sensorFunctions.h"
#include "chassis.h"
#include "globals.h"

void encoderMove(int length, int speed) {
    while(encoderLeft.get_value()<length && encoderRight.get_value()<length) {
        frontRightMotor = speed;
        frontLeftMotor = speed;

        pros::delay(50);
    }
    frontRightMotor = 0;
    frontLeftMotor = 0;
}

void IMUMove(int angle, int speed) {
    myImu.reset();

    while(myImu.is_calibrating()) {
        pros::delay(5);
    }

    pros::c::imu_gyro_s_t gyroscope(myImu.get_gyro_rate());

    if(angle) {
        while(gyroscope.z<angle) {
            frontRightMotor = 0 - speed;
            frontLeftMotor = 0 + speed;

            pros::delay(5);
        }
    }
    else {
        while(gyroscope.z>angle) {
            frontRightMotor = 0 + speed;
            frontLeftMotor = 0 - speed;

            pros::delay(5);
    }
    frontRightMotor = 0;
    frontLeftMotor = 0;
}
}

void potentiometerMove(int height, int speed) {
    while(pot.get_value() < height) {
        lift = speed;  

        pros::delay(50);
    }
    lift = 0;
}