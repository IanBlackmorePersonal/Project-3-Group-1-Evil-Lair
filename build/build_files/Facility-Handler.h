#pragma once
#include "Facility-POE.h"
#include "Facility-Sensor.h"
#include <stdlib.h>
//Feel free to lower those numbers btw
#define POE_COUNT 5
#define FACILITY_SENSOR_COUNT 7

/*
* SHIT TO DO (OR CUT):
* - MAKE IT DISPLAY A SCREEN
* - LINK FORCEFIELD
* - HAVE INFO ON RIGHT SIDE OF SCREEN THAT SAYS A POE or SENSOR'S STATES (like open, damage, breached yadda yadda)
* - LINK FACILITY LOCKDOWN BUTTON TO ENGAGE LOCKDOWN
* - MAKE DISENGAGE LOCKDOWN. I FORGOR
* - MAKE ICONS FOR THE POEs AND SENSORS (I can do this, is just tedious ish)
* - HAVE ICONS DISPLAY WHEN THINGS HIT DIFF STATES (Draw Icon at the X Y of the sensor or POE, change it based on the state)
* - BACK BUTTON (go to main menu)
* - ... (CAN't THINK)
*/


class Facility {
	FacilitySensor sensors[FACILITY_SENSOR_COUNT];
	POE pointsOfEntry[POE_COUNT];
	bool isLockdown;

public:
	Facility();



	int engageLockdown();

	void checkSensors();

	void checkPOEs();

};