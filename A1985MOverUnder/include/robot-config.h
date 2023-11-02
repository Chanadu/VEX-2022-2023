using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LauncherMotor;
extern motor_group IntakeMotors;
extern drivetrain Drivetrain;
extern digital_out Solenoid;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );