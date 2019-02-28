#include "HatchGrabber.h"

namespace frc6692 {
HatchGrabber::HatchGrabber(VictorSPX *hatchGrabberMotor)
        : m_hatchGrabberMotor(hatchGrabberMotor) {
}

void HatchGrabber::RunGrabber(double value) {
    m_hatchGrabberMotor->Set(ControlMode::PercentOutput, value);
}

void HatchGrabber::StopGrabber() {
    m_hatchGrabberMotor->Set(ControlMode::PercentOutput, 0.0);
}
}