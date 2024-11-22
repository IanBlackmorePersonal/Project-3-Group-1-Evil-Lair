#pragma once
#include <stdio.h>

class FacilitySensor {
	int sensorID, sensorX1, sensorX2, sensorY1, sensorY2;
	bool powerStatus, tripped;

public:
	FacilitySensor();

	void setPosition(int X1, int Y1, int X2, int Y2);
	int getX1();
	int getX2();
	int getY1();
	int getY2();

	int getSensorID();
	void setSensorID(int sensorID);

	bool getPowerState();
	void setPowerState(bool powerState);
	bool getTripped();
	void setTripped(bool tripped);
};