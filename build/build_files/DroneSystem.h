#pragma once
#include "Drone.h"
#include <vector>
class DroneSystem {
	std::vector <Drone*> drones;
public:
	DroneSystem();
	~DroneSystem();
	void deployDrones();
	void recallDrones();
};