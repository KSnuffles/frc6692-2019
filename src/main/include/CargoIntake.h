#pragma once

#include <ctre/Phoenix.h>

using namespace ctre;

namespace frc6692 {
    class CargoIntake {
        public:
            CargoIntake(VictorSPX *cargoIntakeMotor);
            ~CargoIntake();

            void RunIntake(double value);
            void StopIntake();
        
        private:
            VictorSPX *m_cargoIntakeMotor;
    };
}