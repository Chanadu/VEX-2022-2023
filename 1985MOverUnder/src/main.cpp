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
// LauncherMotor        motor         11
// Motor14              motor         14
// IntakeMotors         motor_group   9, 10
// Drivetrain           drivetrain    2, 5, 8, 13
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

competition Competition;

bool fastIntake = true;
bool fastIntakeButtonCurrentlyPressed = false;
bool fastTurning = false;
bool fastTurningButtonCurrentlyPressed = false;
bool fastMovement = false;
bool fastMovementButtonCurrentlyPressed = false;
bool wingsActive = false;
bool wingsActiveButtonCurrentlyPressed = false;

void runBooleanChecks(int boolean) {
  /*
  boolean 1 -> fast Intake
  boolean 2 -> fast Turning
  boolean 3 -> Fast Movement
  boolean 4 -> Wings
  boolean -1 -> All
  */
  if (boolean == 1 || boolean == -1) {
    if (fastIntake)
      IntakeMotors.setVelocity(100, percent);
    else
      IntakeMotors.setVelocity(50, percent);
  }
  if (boolean == 2 || boolean == -1) {
    if (fastTurning)
      Drivetrain.setTurnVelocity(100, percent);
    else
      Drivetrain.setTurnVelocity(50, percent);
  }
  if (boolean == 3 || boolean == -1) {
    if (fastMovement)
      Drivetrain.setDriveVelocity(100, percent);
    else
      Drivetrain.setDriveVelocity(50, percent);
  }
  if (boolean == 4 || boolean == -1) {
    if (wingsActive)
      ;
    else
      ;
  }
}

void pre_auton(void) {
  vexcodeInit();
  Brain.Screen.print("Pre Auton Done");
  Brain.Screen.newLine();
  runBooleanChecks(-1);
  return;
}

void autonomous(void) {
  // Wow this is crazy
  Brain.Screen.print("Auton Done");
  Brain.Screen.newLine();
}

void intakeForwardButtonPressed() { IntakeMotors.spin(forward); }

void intakeReverseButtonPressed() { IntakeMotors.spin(reverse); }

void intakeButtonReleased() { IntakeMotors.stop(); }

void launcherForwardButtonPressed() { LauncherMotor.spin(forward); }

void launcherButtonReleased() { LauncherMotor.stop(); }

void fastIntakeButtonPressed() {
  fastIntakeButtonCurrentlyPressed = true;
  fastIntake ^= true;
  runBooleanChecks(1);
}

void fastIntakeButtonReleased() { fastIntakeButtonCurrentlyPressed = false; }

void fastTurningButtonPressed() {
  fastTurningButtonCurrentlyPressed = true;
  fastTurning ^= true;
  runBooleanChecks(2);
}

void fastTurningButtonReleased() { fastTurningButtonCurrentlyPressed = false; }

void fastMovementButtonPressed() {
  fastMovementButtonCurrentlyPressed = true;
  fastMovement ^= true;
  runBooleanChecks(3);
}

void fastMovementButtonReleased() {
  fastMovementButtonCurrentlyPressed = false;
}

void wingsActiveButtonPressed() {
  wingsActiveButtonCurrentlyPressed = true;
  wingsActive ^= true;
  runBooleanChecks(4);
}

void wingsActiveButtonReleased() { wingsActiveButtonCurrentlyPressed = false; }


void usercontrol(void) {
  Brain.Screen.print("Usercontrol start");
  Brain.Screen.newLine();
  while (true) {

    Controller1.ButtonL1.pressed(intakeReverseButtonPressed);
    Controller1.ButtonL2.pressed(intakeForwardButtonPressed);
    Controller1.ButtonL1.released(intakeButtonReleased);
    Controller1.ButtonL2.released(intakeButtonReleased);

    Controller1.ButtonR2.pressed(launcherForwardButtonPressed);
    Controller1.ButtonR2.released(launcherButtonReleased);

    Controller1.ButtonB.pressed(wingsActiveButtonPressed);
    Controller1.ButtonB.released(wingsActiveButtonReleased);

    Controller1.ButtonY.pressed(fastMovementButtonPressed);
    Controller1.ButtonY.released(fastMovementButtonReleased);

    Controller1.ButtonX.pressed(fastTurningButtonPressed);
    Controller1.ButtonX.released(fastTurningButtonReleased);

    Controller1.ButtonA.pressed(fastIntakeButtonPressed);
    Controller1.ButtonA.released(fastIntakeButtonReleased);

    wait(10, msec);
  }
}

int main() {
  pre_auton();
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  while (true) {
    wait(100, msec);
  }
}
