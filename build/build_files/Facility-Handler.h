#pragma once
#include "Facility-POE.h"
#include "Facility-Sensor.h"

#define POE_COUNT 5
#define FACILITY_SENSOR_COUNT 7

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