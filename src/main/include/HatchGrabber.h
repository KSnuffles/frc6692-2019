#pragma once

#include <ctre/Phoenix.h>

using namespace ctre;

namespace frc6692 {
class HatchGrabber {
public:
    HatchGrabber(VictorSPX *hatchGrabberMotor);
    ~HatchGrabber();

    void RunGrabber(double value);
    void StopGrabber();
private:
    VictorSPX *m_hatchGrabberMotor;
};
}