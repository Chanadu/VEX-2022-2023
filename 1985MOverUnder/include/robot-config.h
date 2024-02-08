using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LauncherMotor;
extern drivetrain Drivetrain;
extern digital_out Solenoid1;
extern digital_out Solenoid2;
extern motor UpMotor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);