#include "DroneSystem.h"

#define DEFAULT_DRONE_AMOUNT 4
DroneSystem::DroneSystem() {
	for (int i = 0; i < DEFAULT_DRONE_AMOUNT; i++) {
		Drone* ptr = new Drone;
		drones.push_back(ptr);
	}
}
DroneSystem::~DroneSystem() {
	for (int i = 0; i < drones.size(); i++) {
		delete drones[i];
	}

	drones.clear();
}

void DroneSystem::deployDrones() {
	for (int i = 0; i < drones.size(); i++) {
		drones[i]->deployDrone();
	}
}

void DroneSystem::recallDrones() {
	for (int i = 0; i < drones.size(); i++) {
		drones[i]->recallDrone();
	}
}