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
// Pickup               motor         9               
// Launcher             motor_group   10, 11          
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

bool isTurning = false;
double motorTurningPercentage = 75;
double motorMovementPercentage = 100;

void turnLeft(int vel) {
  LeftGroup.setVelocity(vel, percent);
  RightGroup.setVelocity(vel, percent);
  LeftGroup.spin(reverse);
  RightGroup.spin(forward);
}

void turnRight(int vel) {
  LeftGroup.setVelocity(vel, percent);
  RightGroup.setVelocity(vel, percent);
  LeftGroup.spin(forward);
  RightGroup.spin(reverse);
}

void stopMovement() {
  LeftGroup.stop();
  RightGroup.stop();
}

void release() {
  stopMovement();
}

void moving() {
  int aPosition =
      (int)(Controller1.Axis3.value() * (motorMovementPercentage / 127));
  LeftGroup.setVelocity(abs(aPosition), percent);
  RightGroup.setVelocity(abs(aPosition), percent);
  if (aPosition > 1) {
    LeftGroup.spin(forward);
    RightGroup.spin(forward);
  } else if (aPosition < -1){
    LeftGroup.spin(reverse);
    RightGroup.spin(reverse);
  } else {
    release();
  }
}

void turning() {
  int aPosition =
      (int)(Controller1.Axis1.value() * (motorTurningPercentage / 127));
  isTurning = true;

  LeftGroup.setVelocity(abs(aPosition), percent);
  RightGroup.setVelocity(abs(aPosition), percent);

  if (aPosition < -1) {
    turnLeft(aPosition);
  } else if (aPosition > 1) {
    turnRight(aPosition);
  } else {
    isTurning = false;
  }
}

// L2
void pickupPressed() {
  // Brain.Screen.print("Pickup");
  // Brain.Screen.newLine();

  Pickup.spin(forward);
}

// L2
void pickupReleased() { Pickup.stop(); }

// R2
void launcherPressed() {
  // Brain.Screen.print("Launcher");
  // Brain.Screen.newLine();

  Launcher.spin(forward);
}

// R2
void launcherReleased() { Launcher.stop(); }

// Left Arrow
void smallTurnLeftPressed() { turnLeft(20); }

// Right Arrow
void smallTurnRightPressed() { turnRight(20); }

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  while (true) {

    // Forward Backward Movement
    Controller1.Axis3.changed(moving);
    // Turning
    Controller1.Axis1.changed(turning);

    // Slow Turning
    Controller1.ButtonLeft.pressed(smallTurnLeftPressed);
    Controller1.ButtonLeft.released(release);
    Controller1.ButtonRight.pressed(smallTurnRightPressed);
    Controller1.ButtonRight.released(release);

    // Launcher
    Controller1.ButtonR2.pressed(launcherPressed);
    Controller1.ButtonR2.released(launcherReleased);

    // Pickup and Release
    Controller1.ButtonL2.pressed(pickupPressed);
    Controller1.ButtonL2.released(pickupReleased);
  }
}
