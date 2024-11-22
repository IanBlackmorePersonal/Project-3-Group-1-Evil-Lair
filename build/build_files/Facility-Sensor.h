#pragma once


class FacilitySensor {
	int sensorID, sensorX1, sensorX2, sensorY1, sensorY2;
	bool powerStatus, tripped;

public:
	FacilitySensor();
	bool getPowerState();
	void setPowerState(bool powerState);
	bool getTripped();
	void setTripped(bool tripped);
};