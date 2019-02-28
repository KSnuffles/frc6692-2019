/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

using namespace frc;
using namespace ctre;

namespace frc6692 {
Robot::Robot()
        : m_driverJoystick(new Joystick(DRIVER_JOYSTICK_PORT))
        , m_leftDrive(new Spark(LEFT_DRIVE_PWM_ID))
        , m_rightDrive(new Spark(RIGHT_DRIVE_PWM_ID))
        , m_cargoIntakeMotor(new VictorSPX(CARGO_INTAKE_CAN_ID))
        , m_hatchGrabberMotor(new VictorSPX(HATCH_GRABBER_CAN_ID))
        , m_drive(new Drive(m_leftDrive, m_rightDrive))
        , m_cargoIntake(new CargoIntake(m_cargoIntakeMotor))
        , m_hatchGrabber(new HatchGrabber(m_hatchGrabberMotor)) {
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
    double y = -m_driverJoystick->GetRawAxis(1);
    double x = -m_driverJoystick->GetRawAxis(0);
    double trigger = m_driverJoystick->GetRawButton(1);
    double thumb = m_driverJoystick->GetRawButton(2);
    double hatchUp = m_driverJoystick->GetRawButton(8);
    double hatchDown = m_driverJoystick->GetRawButton(7);

    m_drive->OpenloopArcadeDrive(y, x);

    if (trigger && thumb) {
        m_cargoIntake->StopIntake();
    }
    if (trigger) {
        m_cargoIntake->RunIntake(1.0);
    }
    if (thumb) {
        m_cargoIntake->RunIntake(-1.0);
    }
    if (!trigger && !thumb) {
        m_cargoIntake->StopIntake();
    }

    if (hatchUp && hatchDown) {
        m_hatchGrabber->StopGrabber();
    }
    if (hatchUp) {
        m_hatchGrabber->RunGrabber(1.0);
    }
    if (hatchDown) {
        m_hatchGrabber->RunGrabber(-1.0);
    }
    if (!hatchUp && !hatchDown) {
        m_hatchGrabber->StopGrabber();
    }
}

void Robot::TestPeriodic() {
}
}

#ifndef RUNNING_FRC_TESTS
int main() {
    return StartRobot<frc6692::Robot>();
}
#endif