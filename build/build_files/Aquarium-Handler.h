#pragma once
#include "Aquarium-Tank.h"
#include <string>
#include <stdio.h>
#include <fstream>

#define LINELENGTH 60

/*
TO DO:
Get this to do anything, really. Major functions to build (or cut) are as follows:
- DISPLAY A SCREEN
- SWAP TANKS
- READ FILE
- UPDATE BASED ON FILE
- QUARANTINE AN ANIMAL (reduce population by 1 in main tank, make quarantine unavailable until you hit empty the quarantine tank)
- EMPTY ALL TANKS
- HAVE ALERTS (check tank values, if one of 'em's really bad, make alert)
- BUTTONS THAT INCREASE OR DECREASE VALUES (call alterValue, give it like, 0.2 for pH, 5 for oxygenation, 0.2 for temp, etc.)
- BACK BUTTON (go to main menu)

*/

class Aquarium
{
	Tank tanks[4];
	bool alertStatus;
	char* filename;


public:
	Aquarium();

	int readFile();

	void updateTank(int TankNo, double pHUpdate, double tempUpdate, double oxygenationUpdate);
	
	int transferToQuarantine(int TankNo);
};
