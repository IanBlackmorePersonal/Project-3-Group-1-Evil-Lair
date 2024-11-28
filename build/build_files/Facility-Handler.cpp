#include "Facility-Handler.h"

Facility::Facility()
{
	//figure out your x and y stuff
	for (int i = 0; i < FACILITY_SENSOR_COUNT; i++) {
		sensors[i].CreateSensor(100, 100, 100, 100, i);
	}
}
