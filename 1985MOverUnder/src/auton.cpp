#include "auton.h"
#include "main.h"

using namespace vex;

const double movementFactor = 0.9090909;
const double rotationFactor = .58;

const int defaultWaitTime = 100;
const bool defaultWaitForCompletion = true;

void drive(directionType dir, double distance, bool waitForCompletion, int waitTime)
{
	Drivetrain.driveFor(dir, distance * movementFactor, distanceUnits::in, waitForCompletion);
	wait(waitTime, timeUnits::msec);
}

void drive(directionType dir, double distance, int wait) { drive(dir, distance, defaultWaitForCompletion, wait); }
void drive(directionType dir, double distance, bool waitForCompletion) { drive(dir, distance, waitForCompletion, defaultWaitTime); }
void drive(directionType dir, double distance) { drive(dir, distance, defaultWaitForCompletion, defaultWaitTime); }

const bool defaultWaitForCompletion = true;
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
	drive(reverse, 6, 1000);
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
	turn(right, 11);
	drive(forward, 30);

	// Quick Piston Flash to Secure the Ball In
	setPistons(true, 200);
	setPistons(false, 100);

	// Backup and Turn Into the Middle
	drive(reverse, 12);
	turn(left, 70);
	drive(forward, 22);

	// Get Near But Not Over Middle Line
	turn(right, 60);
	drive(forward, 23);

	// Turn and Push Middle Triballs with Pistons
	turn(left, 95); // MAKE THIS 90 IF THE TILTING IS FIXED
	setPistons(true, 100);
	drive(forward, 40);
	setPistons(false, 100);

	// Backup and Turn Back for Corner
	drive(reverse, 8);
	turn(right, 135); // USED TO BE 160
	drive(forward, 36);

	// Turn and Try and get the Corner Tribal
	turn(left, 45); // turn(right, 135);
	drive(forward, 10);
	turn(left, 90);
	drive(forward, 24, 0);

	// Go Back to Corner for Shooting
	drive(reverse, 48);
}

void pushAuton(void)
{
	// Inital Colored Triball into Goal
	setPistons(false);
	turn(left, 11);
	drive(forward, 30);

	// Quick Piston Flash to Secure the Ball In
	setPistons(true);
	setPistons(false, 100);

	// Backup and Turn Into the Center
	drive(reverse, 6);
	turn(right, 90 + 11);
	drive(forward, 36);

	// Reset and Get into the Middle
	drive(reverse, 8);
	turn(left, 90);
	drive(forward, 24);

	// Move Inital Triball at the Bar
	setPistons(true);
	turn(left, 90, 300);

	// Re-adjust robot to the center of field
	setPistons(false, 100);
	turn(right, 90);
	drive(forward, 8);

	// Push in Triballs into Goal
	turn(left, 90);
	setPistons(true, 100);
	drive(forward, 42);

	// Reset
	setPistons(false);
	drive(reverse, 36);
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
