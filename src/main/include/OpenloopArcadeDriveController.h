#pragma once

#include "Util.h"

namespace frc6692 {

/**
 * Openloop Arcade Drive controller.
 */
class OpenloopArcadeDriveController {
public:
    /**
     * Construct a Openloop Arcade Drive controller.
     */
    OpenloopArcadeDriveController();
    virtual ~OpenloopArcadeDriveController();

    struct DriveOutput {
        double leftOutput;
        double rightOutput;
    };

    /**
     * Calculate motor output given the most recent joystick commands. In this
     * case just return the most recent joystick commands.
     * @param state The state provider for handling incoming messages.
     * @param out The signal receiver for handling outgoing messages.
     */
    DriveOutput& CalcDriveOutput();

    /**
     * Checks with the controller to see if we are on target.
     * @return false, this controller is open-loop.
     */
    bool OnTarget() {
        return false;
    }

    /**
     * Set the joystick values (which in this case will be output).
     * @param throttle Forward/backwards amount.
     * @param turn Left/right amount.
     */
    void SetJoysticks(double throttle, double turn);

private:
    double m_leftOutput;
    double m_rightOutput;

    DriveOutput m_driveOutput;
};
}