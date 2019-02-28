#include "OpenloopArcadeDriveController.h"
#include "RobotInfo.h"
#include "Drive.h"

using namespace frc;

namespace frc6692 {
Drive::Drive(Spark *leftDriveA, Spark *leftDriveB, Spark *rightDriveA,
             Spark *rightDriveB)
        : m_leftDriveA(leftDriveA)
        , m_leftDriveB(leftDriveB)
        , m_rightDriveA(rightDriveA)
        , m_rightDriveB(rightDriveB)
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
        // set 0.0
    }
    else {
        // set values
    }
}
}