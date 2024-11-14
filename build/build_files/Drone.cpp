#include "Drone.h"

Drone::~Drone()	{

}

Drone::Drone() {
	droneBattery = 100;
	droneDamage = UNDAMAGED;
	droneStatus = UNDEPLOYED;
}
void Drone::chargeDrone() {
	droneBattery = 100;
}
void Drone::repairDrone() {
	droneDamage = UNDAMAGED;
}
DamageState Drone::getDamage() {
	return droneDamage;
}
DroneStatus Drone::getStatus() {
	return droneStatus;
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