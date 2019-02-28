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
        m_leftDriveA->Set(0.0);
        m_leftDriveB->Set(0.0);
        m_rightDriveA->Set(0.0);
        m_rightDriveB->Set(0.0);
    }
    else {
        m_leftDriveA->Set(m_leftDriveOutput);
        m_leftDriveB->Set(m_leftDriveOutput);
        m_rightDriveA->Set(m_rightDriveOutput);
        m_rightDriveB->Set(m_rightDriveOutput);
    }
}
}