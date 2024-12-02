#include "Facility-Handler.h"

using namespace std;

Facility::Facility()
{
	//POEs THEN                                 |sensors        
	array<int, 12>TEMPlistofX = {200, 434, 920, 1165, 860, 110, 690, 620, 945, 1075, 1100, 675};
	array<int, 12>TEMPlistofY = {375, 530, 530, 450, 375, 500, 530, 375, 530, 530, 375, 145};
	listofX.swap(TEMPlistofX);
	listofY.swap(TEMPlistofY);
	//figure out your x and y stuff
	for (int i = 4; i < FACILITY_SENSOR_COUNT+4; i++) {
		sensors[i-4].CreateSensor(listofX[i], listofX[i]+75, listofY[i], listofY[i]+75, i);
	}
	for (int j = 0; j < POE_COUNT; j++) {
		pointsOfEntry[j].makePOE(listofX[j], listofX[j]+75, listofY[j], listofY[j]+75, j);
	}
	isLockdown = false;
}

int Facility::engageLockdown()
{
	for (int i = 0; i < FACILITY_SENSOR_COUNT; i++) {
		sensors[i].setPowerState(true);
		printf("Sensor %d active\n", i);
	}
	for (int j = 0; j < POE_COUNT; j++) {
		if (pointsOfEntry[j].getIsBreached() == false) {
			pointsOfEntry[j].setIsOpen(false);
			printf("POE %d is Closed\n", j);
		}
			
	}
	return 0;
}

void Facility::disableLockdown()
{
	for (int i = 0; i < FACILITY_SENSOR_COUNT; i++) {
		sensors[i].setPowerState(false);
	}
	for (int j = 0; j < POE_COUNT; j++) {
		if (pointsOfEntry[j].getIsBreached() == false)
			pointsOfEntry[j].setIsOpen(true);
	}
	printf("Lockdown Disabled");
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
		else if (pointsOfEntry[i].getDamageLevel() >= 100) {
			pointsOfEntry[i].setIsBreached(true);
		}
	}
}


