/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       auton.cpp                                                 */
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

#include "auton.h"

using namespace vex;

const double movementFactor = 0.9090909;
const double rotationFactor = .58;

const int defaultWaitTime = 100;
const bool defaultWaitForCompletion = true;

void drive(directionType dir, double distance, bool waitForCompletion, int waitTime)
{
	Drivetrain.driveFor(forward, distance * movementFactor, distanceUnits::in, waitForCompletion);
	wait(waitTime, timeUnits::msec);
}

void drive(directionType dir, double distance, int wait) { drive(dir, distance, defaultWaitForCompletion, wait); }
void drive(directionType dir, double distance, bool waitForCompletion) { drive(dir, distance, waitForCompletion, defaultWaitTime); }
void drive(directionType dir, double distance) { drive(dir, distance, defaultWaitForCompletion, defaultWaitTime); }

void turn(turnType dir, double angle, bool waitForCompletion, int waitTime)
{
	Drivetrain.turnFor(dir, angle, rotationUnits::deg, waitForCompletion);
	wait(waitTime, timeUnits::msec);
}

void turn(turnType dir, double angle, int waitTime) { turn(dir, angle, defaultWaitForCompletion, waitTime); }
void turn(turnType dir, double angle, bool waitForCompletion) { turn(dir, angle, waitForCompletion, defaultWaitTime); }
void turn(turnType dir, double angle) { turn(dir, angle, defaultWaitForCompletion, defaultWaitTime); }

void OLDshootAuton(void)
{
	// Inital Colored Triball into Goal
	setPistons(false);
	turn(left, 10);
	drive(forward, 32);

	// Quick Piston Flash to Secure the Ball In
	setPistons(true);
	setPistons(false, 100);

	// Backup and Turn Into the Front Left Triball
	drive(reverse, 6);
	turn(right, 85);

	// Drive to the Left Triball
	drive(forward, 24);
	setPistons(true);
	drive(forward, 24);

	// Backup and get in Position for Middle
	setPistons(false, 100);
	drive(reverse, 24);
	turn(left, 90);
	drive(forward, 8);

	// Turn and Push Middle Triballs with Pistons
	turn(right, 90);
	setPistons(true, 100);
	drive(forward, 32);
}

void shootAuton(void)
{
	// Inital Colored Triball into Goal
	setPistons(false);
	turn(left, 10);
	drive(forward, 32);

	// Quick Piston Flash to Secure the Ball In
	setPistons(true);
	setPistons(false, 100);

	// Backup and Turn Into the Middle
	drive(reverse, 6);
	turn(right, 75);
	drive(forward, 24);

	// Get Near But Not Over Middle Line
	turn(left, 20);
	drive(forward, 8);

	// Turn and Push Middle Triballs with Pistons
	turn(right, 90);
	setPistons(true, 100);
	drive(forward, 32);
	setPistons(false, 100);

	// Backup and Turn Back for Corner
	drive(reverse, 8);
	turn(right, 160);
	drive(forward, 36);

	// Turn and Try and get the Corner Tribal
	turn(left, 135);
	drive(forward, 24, 0);

	// Go Back to Corner for Shooting
	drive(reverse, 24);
}

void pushAuton(void)
{
	// Inital Colored Triball into Goal
	setPistons(false);
	turn(left, 10);
	drive(forward, 32);

	// Quick Piston Flash to Secure the Ball In
	setPistons(true);
	setPistons(false, 100);

	// Backup and Turn Into the Center
	drive(reverse, 6);
	turn(left, 90);
	drive(forward, 36);

	// Reset and Get into the Middle
	drive(reverse, 4);
	turn(right, 90);
	drive(forward, 30);

	// Push the Middle Triballs in the Goal
	setPistons(true);
	turn(right, 90);
	drive(forward, 36);

	// Reset
	setPistons(false);
	drive(reverse, 30);
}

void autonomous(void)
{
	Drivetrain.setDriveVelocity(100, percent);
	Drivetrain.setTurnVelocity(25, percent);

	shootAuton();
	// pushAuton();

	Brain.Screen.print("Auton Done");
	Brain.Screen.newLine();
}
