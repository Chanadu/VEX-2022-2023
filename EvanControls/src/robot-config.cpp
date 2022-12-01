#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LeftGroupMotorA = motor(PORT2, ratio18_1, false);
motor LeftGroupMotorB = motor(PORT5, ratio18_1, false);
motor_group LeftGroup = motor_group(LeftGroupMotorA, LeftGroupMotorB);
motor RightGroupMotorA = motor(PORT8, ratio18_1, false);
motor RightGroupMotorB = motor(PORT13, ratio18_1, false);
motor_group RightGroup = motor_group(RightGroupMotorA, RightGroupMotorB);
motor Pickup = motor(PORT15, ratio6_1, false);
motor LauncherMotorA = motor(PORT9, ratio18_1, false);
motor LauncherMotorB = motor(PORT10, ratio18_1, false);
motor_group Launcher = motor_group(LauncherMotorA, LauncherMotorB);

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