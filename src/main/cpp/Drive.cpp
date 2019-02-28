#include "OpenloopArcadeDriveController.h"
#include "RobotInfo.h"
#include "Drive.h"

using namespace frc;

namespace frc6692 {
Drive::Drive(Spark *leftDrive, Spark *rightDrive)
        : m_leftDrive(leftDrive)
        , m_rightDrive(rightDrive)
        , m_leftDriveOutput(0.0)
        , m_rightDriveOutput(0.0)
        , m_openloopArcadeDriveController(new OpenloopArcadeDriveController()) {
}

Drive::~Drive() {
}

void Drive::OpenloopArcadeDrive(double throttle, double turn) {
    m_openloopArcadeDriveController->SetJoysticks(throttle, turn);
    SetDriveOutputVBus(
        m_openloopArcadeDriveController->CalcDriveOutput().leftOutput,
        m_openloopArcadeDriveController->CalcDriveOutput().rightOutput);
}

void Drive::SetDriveOutputVBus(double left, double right) {
    m_leftDriveOutput = left;
    m_rightDriveOutput = right;

    if (std::isnan(m_leftDriveOutput) || std::isnan(m_rightDriveOutput)) {
        m_leftDrive->Set(0.0);
        m_rightDrive->Set(0.0);
    }
    else {
        m_leftDrive->Set(m_leftDriveOutput);
        m_rightDrive->Set(m_rightDriveOutput);
    }
}
}