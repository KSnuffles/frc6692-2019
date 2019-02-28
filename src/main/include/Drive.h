#pragma once

#include <frc/Spark.h>

#include "RobotInfo.h"
#include "OpenloopArcadeDriveController.h"

using namespace frc;

namespace frc6692 {

/**
 * Drive provides an interface to control the drive-base (to do both
 * teleoperated and autonomous movements).  To do this, it makes
 * a bunch of DriveControllers (autonomous PID, autonomous trap,
 * teleop arcade, maybe someday a state space drive controller).  When
 * a command is issued (one of these routines is called), Drive determines
 * which controller is best suited to service that command and makes it
 * the "active" controller.
 *
 * DriveBase: calls on the active controller to calculate motor output.
 * DriveStateProvider: provides the controller with position/angle/speed etc.
 * DrivecontrolSignalReceiver: translates controller output signal to motor
 * input signal.
 */
class Drive {
public:
    /**
     * Construct a drive.
     */
    Drive(Spark *leftDriveA, Spark *leftDriveB, Spark *rightDriveA,
          Spark *rightDriveB);
    virtual ~Drive();

    /**
     * Set a drive to use the openloop arcade drive controller.
     * @param throttle Forward/backwards amount.
     * @param turn Left/right amount.
     */
    void OpenloopArcadeDrive(double throttle, double turn);

    /**
     * Return the average current in amperes through Talon SRX output.
     * @return The average current.
     */
    double GetDriveCurrent() const;

    /**
     * Used by the DriveController to set motor values in percent.
     * @param left Percent output to send to left motors.
     * @param right Percent output to send to right motors.
     */
    void SetDriveOutputVBus(double left, double right);

private:
    Spark *m_leftDriveA;
    Spark *m_leftDriveB;
    Spark *m_rightDriveA;
    Spark *m_rightDriveB;

    double m_leftDriveOutput;
    double m_rightDriveOutput;

    OpenloopArcadeDriveController *m_openloopArcadeDriveController;
};
}