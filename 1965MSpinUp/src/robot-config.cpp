#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor RightMotorsMotorA = motor(PORT2, ratio18_1, false);
motor RightMotorsMotorB = motor(PORT5, ratio18_1, false);
motor_group RightMotors = motor_group(RightMotorsMotorA, RightMotorsMotorB);
motor LeftMotorsMotorA = motor(PORT8, ratio18_1, false);
motor LeftMotorsMotorB = motor(PORT13, ratio18_1, false);
motor_group LeftMotors = motor_group(LeftMotorsMotorA, LeftMotorsMotorB);
motor Intake = motor(PORT14, ratio18_1, false);
motor ShooterMotorA = motor(PORT9, ratio18_1, false);
motor ShooterMotorB = motor(PORT10, ratio18_1, true);
motor_group Shooter = motor_group(ShooterMotorA, ShooterMotorB);
motor ShooterWheel = motor(PORT11, ratio18_1, false);
controller Controller1 = controller(primary);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}