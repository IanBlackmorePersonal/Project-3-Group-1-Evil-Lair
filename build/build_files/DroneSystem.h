#pragma once
#include "Drone.h"
#include <vector>
#include <iostream>
class DroneSystem {
public:
	std::vector <Drone*> drones;
public:
	DroneSystem();
	DroneSystem(int amount);
	~DroneSystem();
	void deployDrones();
	void recallDrones();
	bool readDataFromFile(char* filepath);
	void writeDataToFile(char* filepath);
};