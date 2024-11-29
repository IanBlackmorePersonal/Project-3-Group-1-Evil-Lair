#include "Facility-Handler.h"

Facility::Facility()
{
	//figure out your x and y stuff
	for (int i = 0; i < FACILITY_SENSOR_COUNT; i++) {
		sensors[i].CreateSensor(100, 100, 100, 100, i);
	}
	for (int j = 0; j < POE_COUNT; j++) {
		pointsOfEntry[j].makePOE(100, 100, 100, 100, j);
	}
	isLockdown = false;
}

int Facility::engageLockdown()
{
	for (int i = 0; i < FACILITY_SENSOR_COUNT; i++) {
		sensors[i].setPowerState(true);
	}
	for (int j = 0; j < POE_COUNT; j++) {
		if (pointsOfEntry[j].getIsBreached() == false)
			pointsOfEntry[j].setIsOpen(false);
	}
	return 0;
}

void Facility::checkSensors()
{
	for (int i = 0; i < FACILITY_SENSOR_COUNT; i++) {
		if (sensors[i].getTripped() == true) {
			//something something update icon
		}
	}
}

void Facility::checkPOEs()
{
	for (int i = 0; i < FACILITY_SENSOR_COUNT; i++) {
		if (pointsOfEntry[i].getIsBreached() == true) {
			//something something update icon
		}
	}
}


