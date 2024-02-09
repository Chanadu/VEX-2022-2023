#include "usercontrol.h"
#include "main.h"

bool solenoidJustPressed = false;

void solenoidButtonPressed()
{
	if (solenoidJustPressed)
		return;

	flipPistons();

	solenoidJustPressed = true;
}

void solenoidButtonReleased() { solenoidJustPressed = false; }

void launcherForwardButtonPressed() { LauncherMotor.spin(forward); }

void launcherReverseButtonPressed() { LauncherMotor.spin(reverse); }

void launcherButtonReleased() { LauncherMotor.stop(); }

void upMotorButtonForwardPressed() { UpMotor.spin(forward); }

void upMotorButtonReversePressed() { UpMotor.spin(reverse); }

void upMotorButtonReleased() { UpMotor.stop(); }

void usercontrol(void)
{
	Brain.Screen.print("Usercontrol start");
	Brain.Screen.newLine();

	while (true)
	{
		Controller1.ButtonB.pressed(solenoidButtonPressed);
		Controller1.ButtonB.released(solenoidButtonReleased);

		Controller1.ButtonDown.pressed(upMotorButtonForwardPressed);
		Controller1.ButtonDown.released(upMotorButtonReleased);
		Controller1.ButtonUp.pressed(upMotorButtonReversePressed);
		Controller1.ButtonUp.released(upMotorButtonReleased);

		Controller1.ButtonR2.pressed(launcherForwardButtonPressed);
		Controller1.ButtonR2.released(launcherButtonReleased);
		Controller1.ButtonR1.pressed(launcherReverseButtonPressed);
		Controller1.ButtonR1.released(launcherButtonReleased);

		wait(5, msec);
	}
}