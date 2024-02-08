#include "vex.h"

using namespace vex;

competition Competition;

void setPistons(bool status);
void setPistons(bool status, int waitTime);

bool getPistons(void);

void flipPistons(int waitTime);
void flipPistons(void);