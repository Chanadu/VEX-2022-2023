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
// Motor2               motor         2               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

competition Competition;

void pre_auton(void) {
  vexcodeInit();
  return;
}

void autonomous(void) {
  // Wow this is crazy
}

void intakeButtonPressed() {
  Motor2.spin(forward);
}

void intakeButtonReleased() {
  Motor2.stop();
}

void usercontrol(void) {
  while (true) {
    Controller1.ButtonR1.pressed(intakeButtonPressed);
    Controller1.ButtonR1.released(intakeButtonReleased);
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
