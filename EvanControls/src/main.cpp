/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\cpedda26                                         */
/*    Created:      Thu Dec 01 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LeftGroup            motor_group   2, 5            
// RightGroup           motor_group   8, 13           
// Pickup               motor         14              
// Launcher             motor_group   9, 10           
// LauncherWheel        motor         19              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;

bool isTurning = false;
double motorTurningPercentage = 50;
double motorMovementPercentage = 100;

void Turn (int vel) {
  vel *= -1;
  LeftGroup.setVelocity(vel, percent);
  RightGroup.setVelocity(vel, percent);
  LeftGroup.spin(forward);
  RightGroup.spin(reverse);
}

void stopMovement() {
  LeftGroup.stop();
  RightGroup.stop();
}

// R1
void forwardPressed() {
  //   Brain.Screen.print("Forward");
  //   Brain.Screen.newLine();

  LeftGroup.setVelocity(motorMovementPercentage, percent);
  RightGroup.setVelocity(motorMovementPercentage, percent);
  LeftGroup.spin(forward);
  RightGroup.spin(forward);
}

// L1
void reversePressed() {
  //   Brain.Screen.print("Reverse");
  //   Brain.Screen.newLine();

  LeftGroup.setVelocity(motorMovementPercentage, percent);
  RightGroup.setVelocity(motorMovementPercentage, percent);
  LeftGroup.spin(reverse);
  RightGroup.spin(reverse);
}

// L2
void pickupPressed() {
  // Brain.Screen.print("Pickup");
  // Brain.Screen.newLine();
  Pickup.setVelocity(100, percent);
  Pickup.spin(forward);
}

// L2
void pickupReleased() { Pickup.stop(); }

// R2
void launcherPressed() {
  // Brain.Screen.print("Launcher");
  // Brain.Screen.newLine();
  LauncherWheel.spin(forward);
  Launcher.spin(forward);
}

// R2
void launcherReleased() {
  Launcher.stop(); 
  LauncherWheel.stop();
}

// Left Arrow
void smallTurnLeftPressed() { Turn(-20); }

// Right Arrow
void smallTurnRightPressed() { Turn(20); }

// Turning
void axis4() {
  int aPosition =
      (int)(Controller1.Axis4.value() * (motorTurningPercentage / 127));
  isTurning = true;
  if (aPosition < -1) {
    Turn(aPosition);
  } else if (aPosition > 1) {
    Turn(aPosition);
  } else {
    isTurning = false;
    stopMovement();
  }
}

void release() {
  Brain.Screen.print("Released");
  Brain.Screen.newLine();

  stopMovement();
}

int main() {
  vexcodeInit();
  
  while (true) {
    LauncherWheel.setVelocity(100, percent);
    Launcher.setVelocity(100, percent);
    // Forward Backward Movement
    if (!isTurning) {
      Controller1.ButtonR1.pressed(forwardPressed);
      Controller1.ButtonR1.released(release);
      Controller1.ButtonL1.pressed(reversePressed);
      Controller1.ButtonL1.released(release);
    }

    // Turning
    Controller1.Axis4.changed(axis4);

    // Slow Turning
    Controller1.ButtonLeft.pressed(smallTurnLeftPressed);
    Controller1.ButtonLeft.released(release);
    Controller1.ButtonRight.pressed(smallTurnRightPressed);
    Controller1.ButtonRight.released(release);

    // Launcher
    Controller1.ButtonL2.pressed(launcherPressed);
    Controller1.ButtonL2.released(launcherReleased);

    // Pickup and Release
    Controller1.ButtonR2.pressed(pickupPressed);
    Controller1.ButtonR2.released(pickupReleased);

    // Sleep
    task::sleep(5);
  }
}