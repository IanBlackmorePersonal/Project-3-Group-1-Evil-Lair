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
	char* getDamage();
	char* getStatus();
	void deployDrone();
	void recallDrone();
	float getBatteryLevel();
	void setBatteryLevel(float f);
	void setStatus(DroneStatus d);
	void setDamage(DamageState d);
	void chargeDrone();

};