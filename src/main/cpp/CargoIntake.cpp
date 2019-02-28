#include "CargoIntake.h"

namespace frc6692 {
CargoIntake::CargoIntake(VictorSPX *cargoIntakeMotor)
        : m_cargoIntakeMotor(cargoIntakeMotor) {
    m_cargoIntakeMotor->SetInverted(true);
}

void CargoIntake::RunIntake(double value) {
    m_cargoIntakeMotor->Set(ControlMode::PercentOutput, value);
}

void CargoIntake::StopIntake() {
    m_cargoIntakeMotor->Set(ControlMode::PercentOutput, 0.0);
}
}