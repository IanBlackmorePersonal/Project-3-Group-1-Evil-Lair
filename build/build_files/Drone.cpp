#include "Drone.h"
#include <iostream>
Drone::~Drone()	{

}

Drone::Drone() {
	droneBattery = 100;
	droneDamage = UNDAMAGED;
	droneStatus = UNDEPLOYED;
}
void Drone::chargeDrone() {
	droneBattery = (float)100;
	setStatus(CHARGING);
}
void Drone::repairDrone() {
	setStatus(REPAIRING);
	droneDamage = UNDAMAGED;
}
char* Drone::getDamage() {
	switch (droneDamage) {
	case UNDAMAGED:
		return "Undamaged";
		break;
	case DAMAGED:
		return "Damaged";
		break;
	case BROKEN:
		return "Broken";
		break;
	}
	return "";
}
char* Drone::getStatus() {
	switch (droneStatus) {
	case CHARGING:
		return "Charging";
		break;
	case DEPLOYED:
		return "Deployed";
		break;
	case REPAIRING:
		return "Repairing";
		break;
	case UNDEPLOYED:
		return "Undeployed";
		break;
	default:
		return "";
		break;
	}
	return "";
}
void Drone::deployDrone() {
	droneStatus = DEPLOYED;
}
void Drone::recallDrone() {
	droneStatus = UNDEPLOYED;
}
float Drone::getBatteryLevel() {
	return droneBattery;
}

void Drone::setBatteryLevel(float f) {
	droneBattery = f;
}

void Drone::setStatus(DroneStatus d) {
	droneStatus = d;
}

void Drone::setDamage(DamageState d) {
	droneDamage = d;
}
