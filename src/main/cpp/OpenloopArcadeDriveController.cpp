#include <stdio.h>

#include "OpenloopArcadeDriveController.h"

namespace frc6692 {

OpenloopArcadeDriveController::OpenloopArcadeDriveController()
        : m_leftOutput(0.0), m_rightOutput(0.0), m_driveOutput({0.0, 0.0}) {
}

OpenloopArcadeDriveController::~OpenloopArcadeDriveController() {
}

OpenloopArcadeDriveController::DriveOutput&
OpenloopArcadeDriveController::CalcDriveOutput() {
    return m_driveOutput;
}

void OpenloopArcadeDriveController::SetJoysticks(double throttle, double turn) {
    throttle = Util::bound(throttle, -1.0, 1.0);
    turn = Util::bound(turn, -1.0, 1.0) * 0.3;

    m_leftOutput = throttle - turn;
    m_rightOutput = throttle + turn;

    double maxSpeed = Util::max(m_leftOutput, m_rightOutput);
    if (maxSpeed > 1.0) {
        m_leftOutput = m_leftOutput * (1.0 / maxSpeed);
        m_rightOutput = m_rightOutput * (1.0 / maxSpeed);
    }

    m_driveOutput.leftOutput = m_leftOutput;
    m_driveOutput.rightOutput = m_rightOutput;

    printf("left %lf  right %lf\n", m_leftOutput, m_rightOutput);
}
}