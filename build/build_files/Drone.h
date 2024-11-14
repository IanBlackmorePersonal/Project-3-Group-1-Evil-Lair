#pragma once

enum DroneStatus {
	CHARGING,
	DEPLOYED,
	REPAIRING,
	UNDEPLOYED
};

enum DamageState {
	BROKEN,
	DAMAGED,
	UNDAMAGED
};

class Drone {
	DroneStatus droneStatus;
	DamageState droneDamage;
	float droneBattery;
public:
	Drone();
	~Drone();
	void repairDrone();
	DamageState getDamage();
	DroneStatus getStatus();
	void deployDrone();
	void recallDrone();
	float getBatteryLevel();
	void chargeDrone();

};