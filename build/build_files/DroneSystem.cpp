#include "DroneSystem.h"
#include <fstream>
#include <string>
#include <stdio.h>
#define DEFAULT_DRONE_AMOUNT 3
#define MAX_CHAR_SIZE 20
#define DRONE_SYSTEM_FILEPATH "dronesystem.txt"
DroneSystem::DroneSystem() {
	for (int i = 0; i < DEFAULT_DRONE_AMOUNT; i++) {
		Drone* ptr = new Drone;
		drones.push_back(ptr);
	}
	readDataFromFile(DRONE_SYSTEM_FILEPATH);

}
DroneSystem::DroneSystem(int amount) {
	for (int i = 0; i < amount; i++) {
		Drone* ptr = new Drone;
		drones.push_back(ptr);
	}
}
DroneSystem::~DroneSystem() {
	writeDataToFile(DRONE_SYSTEM_FILEPATH);
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

bool DroneSystem::readDataFromFile(char* filepath) {
	FILE* fp = fopen(filepath, "r");
	char buffer [MAX_CHAR_SIZE];
	if (!fp) {
		std::cout << "Could not open file: " << filepath << std::endl;
		return false;
	}
	std::cout << "Successfully opened file: " << filepath << std::endl;
	for (int i = 0; i < 3; i++) {
		fgets(buffer, sizeof(buffer), fp);
		if (strcmp(buffer, "Undeployed\n") == 0) {
			drones[i]->setStatus(UNDEPLOYED);
		}
		if (strcmp(buffer, "Charging\n") == 0) {
			drones[i]->setStatus(CHARGING);
		}
		if (strcmp(buffer, "Repairing\n") == 0) {
			drones[i]->setStatus(REPAIRING);
		}
		if (strcmp(buffer, "Deployed\n") == 0) {
			drones[i]->setStatus(DEPLOYED);
		}
		fgets(buffer, sizeof(buffer), fp);
		
		if (strcmp(buffer, "Damaged\n") == 0) {
			drones[i]->setDamage(DAMAGED);
		}
		if (strcmp(buffer, "Undamaged\n") == 0) {
			drones[i]->setDamage(UNDAMAGED);
		}
		if (strcmp(buffer, "Broken\n") == 0) {
			drones[i]->setDamage(BROKEN);
		}
		fgets(buffer, sizeof(buffer), fp);
		drones[i]->setBatteryLevel(std::stof(buffer));
	}
	fclose(fp);
	return true;
}

void DroneSystem::writeDataToFile(char* filepath) {
	FILE* fp = fopen(filepath, "w");
	if (!fp) {
		std::cout << "Could not create file: " << filepath << std::endl;
		return;
	}

	for (int i = 0; i < 3; i++) {
		fputs(drones[i]->getStatus(), fp);
		fputc('\n', fp);
		fputs(drones[i]->getDamage(), fp);
		fputc('\n', fp);
		// converts float to char*
		char buffer[MAX_CHAR_SIZE];
		sprintf(buffer, "%.1f", drones[i]->getBatteryLevel());
		fputs(buffer, fp);
		fputc('\n', fp);
	}
	fclose(fp);
}