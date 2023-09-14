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
// Drivetrain           drivetrain    2, 5, 8, 13     
// LauncherMotor        motor         11              
// Motor14              motor         14              
// IntakeMotors         motor_group   9, 10           
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

competition Competition;

bool fastIntake = true;
bool fastIntakeButtonCurrentlyPressed = false;
bool fastTurning = true;
bool fastTurningButtonCurrentlyPressed = false;
bool fastMovement = true;
bool fastMovementButtonCurrentlyPressed = false;
bool wingsActive = false;
bool wingsActiveButtonCurrentlyPressed = false;

void pre_auton(void) {
  vexcodeInit();
  return;
}

void autonomous(void) {
  // Wow this is crazy
}

void intakeForwardButtonPressed() {
  IntakeMotors.spin(forward);
}

void intakeReverseButtonPressed() {
  IntakeMotors.spin(reverse);
}

void intakeButtonReleased() {
  IntakeMotors.stop();
}

void launcherForwardButtonPressed() {
  LauncherMotor.spin(forward);
}

void launcherButtonReleased() {
  LauncherMotor.stop();
}

void fastIntakeButtonPressed() {
  fastIntakeButtonCurrentlyPressed = true;
  fastIntake ^= true;
}

void fastIntakeButtonReleased() {
  fastIntakeButtonCurrentlyPressed = false;
}

void fastTurningButtonPressed() {
  fastTurningButtonCurrentlyPressed = true;
  fastTurning ^= true;
}

void fastTurningButtonReleased() {
  fastTurningButtonCurrentlyPressed = false;
}

void fastMovementButtonPressed() {
  fastMovementButtonCurrentlyPressed = true;
  fastMovement ^= true;
}

void fastMovementButtonReleased() {
  fastMovementButtonCurrentlyPressed = false;
}

void wingsActiveButtonPressed() {
  wingsActiveButtonCurrentlyPressed = true;
  wingsActive ^= true;
}

void wingsActiveButtonReleased() {
  wingsActiveButtonCurrentlyPressed = false;
}

void usercontrol(void) {
  while (true) {
    if (fastIntake) IntakeMotors.setVelocity(100, percent);
    else IntakeMotors.setVelocity(50, percent);

    if (fastTurning) Drivetrain.setTurnVelocity(100, percent);
    else Drivetrain.setTurnVelocity(50, percent);

    if (fastMovement) Drivetrain.setDriveVelocity(100, percent);
    else Drivetrain.setDriveVelocity(50, percent);

    if (wingsActive);
    else ;


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
