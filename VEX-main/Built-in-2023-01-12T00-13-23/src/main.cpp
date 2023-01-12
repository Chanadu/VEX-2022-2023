/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\cpedda26                                         */
/*    Created:      Wed Jan 11 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    2, 5, 8, 13     
// Pickup               motor         15              
// Launcher             motor_group   9, 10           
// LauncherWheel        motor         11              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void launcherPressed() {
  Launcher.spin(forward);
  LauncherWheel.spin(forward);
}

void launcherReleased() {
  Launcher.stop();
  LauncherWheel.stop();
}

void pickupPressed() {
  Pickup.spin(reverse);
}

void pickupReleased() {
  Pickup.stop();
}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while (true) {
    Drivetrain.setDriveVelocity(100, percent);
    Drivetrain.setTurnVelocity(50, percent);
    // Launcher
    Launcher.setVelocity(100, percent);
    LauncherWheel.setVelocity(100, percent);
    Controller1.ButtonR2.pressed(launcherPressed);
    Controller1.ButtonR2.released(launcherReleased);
    
    // Pickup and Release
    Controller1.ButtonL2.pressed(pickupPressed);
    Controller1.ButtonL2.released(pickupReleased);
  }
}
