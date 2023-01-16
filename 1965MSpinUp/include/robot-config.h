using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor_group RightMotors;
extern motor_group LeftMotors;
extern motor Intake;
extern motor_group Shooter;
extern motor ShooterWheel;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );