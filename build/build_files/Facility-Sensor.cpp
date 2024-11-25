#include "Facility-Sensor.h"

FacilitySensor::FacilitySensor()
{
	setSensorID(0);
	setPowerState(true);
	setTripped(false);
	setPosition(0, 0, 0, 0);
}

void FacilitySensor::setPosition(int X1, int Y1, int X2, int Y2)
{
	this->sensorX1 = X1;
	this->sensorX2 = X2;
	this->sensorY1 = Y1;
	this->sensorY2 = Y2;
}

int FacilitySensor::getX1()
{
	return sensorX1;
}

int FacilitySensor::getX2()
{
	return sensorX2;
}

int FacilitySensor::getY1()
{
	return sensorY1;
}

int FacilitySensor::getY2()
{
	return sensorY2;
}

int FacilitySensor::getSensorID()
{
	return sensorID;
}

void FacilitySensor::setSensorID(int sensorID)
{
	this->sensorID = sensorID;
}

bool FacilitySensor::getPowerState()
{
	return powerStatus;
}

void FacilitySensor::setPowerState(bool powerState)
{
	this->powerStatus = powerState;
}

bool FacilitySensor::getTripped()
{
	return tripped;
}

void FacilitySensor::setTripped(bool tripped)
{
	this->tripped = tripped;
}
