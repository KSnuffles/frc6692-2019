/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/Joystick.h>
#include <frc/Spark.h>

#include <ctre/Phoenix.h>

#include "RobotInfo.h"
#include "Drive.h"

using namespace frc;
using namespace ctre;

namespace frc6692 {
class Robot : public TimedRobot {
public:
    Robot();
    void RobotInit() override;
    void RobotPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void TestPeriodic() override;

private:
    Joystick *m_driverJoystick;
    Spark *m_leftDriveA;
    Spark *m_leftDriveB;
    Spark *m_rightDriveA;
    Spark *m_rightDriveB;

    VictorSPX *m_cargoIntake;

    Drive *m_drive;
};
}
