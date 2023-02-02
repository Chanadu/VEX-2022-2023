/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Chanadu                                                   */
/*    Created:      Sun Jan 15, 2023                                          */
/*    Description:  Team 1965M's Code for their Robot                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Intake               motor         11              
// Shooter              motor_group   9, 10           
// Controller1          controller                    
// LeftMotors           motor_group   2, 5            
// RightMotors          motor_group   8, 13           
// StringLauncher       motor         6               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

enum move 
{
  stopMovement,
  stopIntake,
  stopShooter,
  forward,
  reverse,
  left,
  right,
  intake,
  shoot,
  stringLauncher
};

//Speeds
double movingSpeed = 80.0;
double turningSpeed = 50.0;
double intakeSpeed = 100.0;
double shooterSpeed = 100.0;
double stringLauncherSpeed = 60.0;

std::map<move, double> speeds = 
{
 {move::stopMovement, 0.0},
 {move::stopIntake, 0.0},
 {move::stopShooter, 0.0},
 {move::forward, movingSpeed}, 
 {move::reverse, movingSpeed},
 {move::left, movingSpeed},
 {move::right, movingSpeed},
 {move::intake, intakeSpeed},
 {move::shoot, shooterSpeed},
 {move::stringLauncher, stringLauncherSpeed}
};

//States
enum states {
  stopped,
  moving,
  turning
};

states currentState = states::stopped;

// A global instance of competition
competition Competition;


void moveMotors(move movingDirection, double speedChange = 100.0) {
  double motorVelocity = speeds[movingDirection] * (speedChange / 100.0);
  LeftMotors.setVelocity(motorVelocity, percent);
  RightMotors.setVelocity(motorVelocity, percent);
  
  switch (movingDirection) {
    case move::stopMovement:
      LeftMotors.stop(vex::coast);
      RightMotors.stop(vex::coast);
      break;

    case move::stopIntake:
      Intake.stop(vex::coast);
      break;

    case move::stopShooter:
      Shooter.stop(vex::coast);
      break;
    case move::forward:
      LeftMotors.spin(vex::forward);
      RightMotors.spin(vex::forward);
      break;

    case move::reverse:
      LeftMotors.spin(vex::reverse);
      RightMotors.spin(vex::reverse);
      break;

    case move::left:
      LeftMotors.spin(vex::reverse);
      RightMotors.spin(vex::forward);
      break;

    case move::right:
      LeftMotors.spin(vex::forward);
      RightMotors.spin(vex::reverse);
      break;

    case move::intake:
      Intake.spin(vex::forward);
      break;

    case move::shoot:
      Shooter.spin(vex::forward);
      break;
    case move::stringLauncher:
      StringLauncher.spin(vex::forward);
      break;
  }
}


void movementAxis() {
    int axisPosition = std::abs(Controller1.Axis3.value() * (speeds[move::forward] / 127.0)); 
    currentState = states::moving;
    if (axisPosition > 1) {
      moveMotors(move::forward, axisPosition);
    } else if (axisPosition < -1) {
      moveMotors(move::reverse, axisPosition * -1);
    } else {
      moveMotors(move::stopMovement);
      currentState = states::stopped;
    }
}


void turnAxis() {
    int axisPosition = std::abs(Controller1.Axis1.value() * (speeds[move::left] / 127.0)); 
    currentState = states::turning;
    if (axisPosition > 1) {
      moveMotors(move::right, axisPosition);
    } else if (axisPosition < -1) {
      moveMotors(move::left, axisPosition * -1);
    } else {
      moveMotors(move::stopMovement);
      currentState = states::stopped;
    }
}


void intakeButtonPressed() {
  moveMotors(move::intake);
}


void intakeButtonReleased() {
  moveMotors(move::stopIntake);
}


void shooterButtonPressed() {
  moveMotors(move::shoot);
}


void shooterButtonReleased() {
  moveMotors(move::stopShooter);
}


void forwardButtonPressed() {
  moveMotors(move::forward);
  currentState = states::moving;
}


void forwardButtonReleased() {
  moveMotors(move::stopMovement);
  currentState = states::stopped;
}


void reversedButtonPressed() {
  moveMotors(move::reverse);
  currentState = states::moving;
}


void reverseButtonReleased() {
  moveMotors(move::stopMovement);
  currentState = states::stopped;
}


void stringLauncherButtonPressed() {
  moveMotors(move::stringLauncher);
}


void stringLauncherPressed() {
  StringLauncher.spin(vex::reverse);
}


void stringLauncherStopButtonPressed() {
  StringLauncher.stop(vex::coast);
}


// Runs once when connected to the
void pre_auton(void) {
  vexcodeInit();

  RightMotors.setVelocity(speeds[move::forward], percent);
  LeftMotors.setVelocity(speeds[move::forward], percent);
  Intake.setVelocity(speeds[move::intake], percent);
  Shooter.setVelocity(speeds[move::shoot], percent);
  StringLauncher.setVelocity(speeds[move::stringLauncher], percent);
  return;
}


// Runs when Competition starts Autonomous Code
void autonomous(void) {
  // Roll roller to right color & Push disks into low goal
  Intake.spinTo(90, vex::degrees, true);
  LeftMotors.spinFor(vex::forward, 360, vex::deg);
  RightMotors.spinFor(vex::forward, 360, vex::deg);

  waitUntil(!LeftMotors.isSpinning());
  waitUntil(!RightMotors.isSpinning());
  LeftMotors.spinFor(vex::reverse, 180, vex::deg);
  RightMotors.spinFor(vex::forward, 180, vex::deg);

  

}



//Evan's Controls
void usercontrol(void) {
  while (true) {
    //Controller1.Axis1.changed(turnAxis);

    // if (currentState != states::turning) {
    //   Controller1.Axis3.changed(movementAxis);
      
    //   Controller1.ButtonR1.pressed(intakeButtonPressed);
    //   Controller1.ButtonR1.released(intakeButtonReleased);
    //   Controller1.ButtonL1.pressed(shooterButtonPressed);
    //   Controller1.ButtonL1.released(shooterButtonReleased);
      
    // }

    Controller1.ButtonR1.pressed(intakeButtonPressed);
    Controller1.ButtonR1.released(intakeButtonReleased);
    Controller1.ButtonL1.pressed(shooterButtonPressed);
    Controller1.ButtonL1.released(shooterButtonReleased);
    Controller1.ButtonL1.pressed(shooterButtonPressed);
    Controller1.ButtonB.pressed(stringLauncherButtonPressed);
    Controller1.ButtonX.pressed(stringLauncherStopButtonPressed);
    // Reverse
    Controller1.ButtonY.pressed(stringLauncherPressed);

    double axis3 = Controller1.Axis3.value() * (speeds[move::forward] / 127.0);
    double axis1 = Controller1.Axis1.value() * (speeds[move::forward] / 127.0);
    
    LeftMotors.spin(vex::forward, axis3 + axis1, percent);
    RightMotors.spin(vex::forward, axis3 - axis1, percent);

    // Controller1.ButtonR2.pressed(intakeButtonPressed);
    // Controller1.ButtonR2.released(intakeButtonReleased);
    // Controller1.ButtonL2.pressed(shooterButtonPressed);
    // Controller1.ButtonL2.released(shooterButtonReleased);
    

    wait(10, msec);
  }
}


// Don't Touch
int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}