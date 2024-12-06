#pragma once
#include "Facility-POE.h"
#include "Facility-Sensor.h"
#include <stdlib.h>
#include <array>
using namespace std;
//Feel free to lower those numbers btw
#define POE_COUNT 5
#define FACILITY_SENSOR_COUNT 7

/*
* THINGS TO DO (OR CUT):

* - HAVE INFO ON RIGHT SIDE OF SCREEN THAT SAYS A POE or SENSOR'S STATES (like open, damage, breached yadda yadda)

* - HAVE ICONS DISPLAY WHEN THINGS HIT DIFF STATES (Draw Icon at the X Y of the sensor or POE, change it based on the state)
*/


class Facility {
	FacilitySensor sensors[FACILITY_SENSOR_COUNT];
	POE pointsOfEntry[POE_COUNT];
	bool isLockdown;
	array<int, (FACILITY_SENSOR_COUNT + POE_COUNT)> listofX, listofY;

public:
	Facility();



	int engageLockdown();

	void disableLockdown();

	void checkSensors();

	void checkPOEs();

};