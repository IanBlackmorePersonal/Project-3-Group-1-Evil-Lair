#pragma once
#include "Drone.h"
#include <vector>
class DroneSystem {
public:
	std::vector <Drone*> drones;
public:
	DroneSystem();
	DroneSystem(int amount);
	~DroneSystem();
	void deployDrones();
	void recallDrones();
};