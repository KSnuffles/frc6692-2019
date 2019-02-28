/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

using namespace frc;
using namespace ctre;

namespace frc6692 {
Robot::Robot()
        : m_driverJoystick(new Joystick(DRIVER_JOYSTICK_PORT))
        , m_leftDriveA(new Spark(LEFT_DRIVE_A_PWM_ID))
        , m_leftDriveB(new Spark(LEFT_DRIVE_B_PWM_ID))
        , m_rightDriveA(new Spark(RIGHT_DRIVE_A_PWM_ID))
        , m_rightDriveB(new Spark(RIGHT_DRIVE_B_PWM_ID))
        , m_cargoIntake(new VictorSPX(CARGO_INTAKE_CAN_ID))
        , m_drive(new Drive(m_leftDriveA, m_leftDriveB, m_rightDriveA,
                            m_rightDriveB)) {
}

void Robot::RobotInit() {
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
}

void Robot::AutonomousPeriodic() {
}

void Robot::TeleopInit() {
}

void Robot::TeleopPeriodic() {
    double y = m_driverJoystick->GetRawAxis(1);
    double x = m_driverJoystick->GetRawAxis(0);

    m_drive->OpenloopArcadeDrive(y, x);
}

void Robot::TestPeriodic() {
}
}

#ifndef RUNNING_FRC_TESTS
int main() {
    return StartRobot<frc6692::Robot>();
}
#endif