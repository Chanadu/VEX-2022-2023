/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\cpedda26                                         */
/*    Created:      Thu Sep 07 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// LauncherMotor        motor         14
// Drivetrain           drivetrain    2, 5, 15, 13
// Solenoid1            digital_out   E
// Solenoid2            digital_out   H
// UpMotor              motor         18
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "main.h"
#include "auton.h"
#include "usercontrol.h"

bool pistonStatus = false;
competition Competition;

void setPistons(bool status, int waitTime)
{
	pistonStatus = status;
	Solenoid1.set(status);
	Solenoid2.set(status);
	Brain.Screen.print(status);
	Brain.Screen.newLine();
	if (waitTime != 0)
	{
		wait(waitTime, timeUnits::msec);
	}
}

void setPistons(bool status)
{
	setPistons(status, 0);
	Brain.Screen.print(&"Status: "[status]);
	Brain.Screen.newLine();
}

bool getPistons(void)
{
	return pistonStatus;
}

void flipPistons(int waitTime)
{
	pistonStatus ^= true;
	Solenoid1.set(pistonStatus);
	Solenoid2.set(pistonStatus);

	if (waitTime != 0)
	{
		wait(waitTime, timeUnits::msec);
	}
}

void flipPistons(void) { flipPistons(0); }

void pre_auton(void)
{
	LauncherMotor.setVelocity(100, percent);
	LauncherMotor.setStopping(brakeType::coast);

	Drivetrain.setStopping(brake);

	UpMotor.setVelocity(100, percent);
	UpMotor.setStopping(brake);

	setPistons(false);

	Brain.Screen.print("Pre Auton Ran");
	Brain.Screen.newLine();
}

int main()
{
	vexcodeInit();

	pre_auton();

	Competition.autonomous(autonomous);

	// Both are for redundancy later
	Drivetrain.setTurnVelocity(25, percent);
	Drivetrain.setDriveVelocity(100, percent);

	Competition.drivercontrol(usercontrol);

	while (true)
	{
		wait(100, msec);
	}
}
