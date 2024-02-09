#include "vex.h"

using namespace vex; 

void autonomous(void);

void drive(directionType dir, double distance, bool waitForCompletion, int waitTime);
void drive(directionType dir, double distance, int wait);
void drive(directionType dir, double distance, bool waitForCompletion);
void drive(directionType dir, double distance);
 
void turn(turnType dir, double angle, bool waitForCompletion, int waitTime);
void turn(turnType dir, double angle, int waitTime);
void turn(turnType dir, double angle, bool waitForCompletion);
void turn(turnType dir, double angle);