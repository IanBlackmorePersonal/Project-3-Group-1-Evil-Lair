#include "UndergroundGarden.h"
#include <stdio.h>
#include <iostream>
#include <string>
#define MAX_CHAR_SIZE 20
#define UDG_SYSTEM_FILEPATH "undergroundgarden.txt"

UndergroundGarden::UndergroundGarden() {
	// default values
	sprinklerStatus = false;
	soilPHLevel = 7.0F;
	humidityLevel = 80.0F;

}
UndergroundGarden::~UndergroundGarden() {
	writeDataToFile(UDG_SYSTEM_FILEPATH);
}

void UndergroundGarden::setSprinklerStatus(bool input) {
	sprinklerStatus = input;
}
void UndergroundGarden::setHumidity(float input) {
	humidityLevel = input;
	if (humidityLevel < 0) {
		humidityLevel = 0.0f;
		
	} 
	if (humidityLevel > 100) {
		humidityLevel = 100.0f;
	}

}
void UndergroundGarden::setSoilPH(float input) {
	soilPHLevel = input;
	if (soilPHLevel < 0) {
		soilPHLevel = 0.0f;

	}
	if (soilPHLevel > 14) {
		soilPHLevel = 14.0f;
	}
}
bool UndergroundGarden::getSprinklerStatus() {
	return sprinklerStatus;
}
float UndergroundGarden::getHumidity() {
	return humidityLevel;
}
float UndergroundGarden::getSoilPH() {
	return soilPHLevel;
}

bool UndergroundGarden::readDataFromFile(char* filepath) {
	FILE* fp = fopen(filepath, "r");
	char buffer[MAX_CHAR_SIZE];
	if (!fp) {
		std::cout << "Could not open file: " << filepath << std::endl;
		return false;
	}
	std::cout << "Successfully opened file: " << filepath << std::endl;
	fgets(buffer, sizeof(buffer), fp);
	setSprinklerStatus((bool)std::stoi(buffer));
	fgets(buffer, sizeof(buffer), fp);
	setHumidity(std::stof(buffer));
	fgets(buffer, sizeof(buffer), fp);
	setSoilPH(std::stof(buffer));
	fclose(fp);
	return true;
}

void UndergroundGarden::writeDataToFile(char* filepath) {
	FILE* fp = fopen(filepath, "w");
	if (!fp) {
		std::cout << "Could not create file: " << filepath << std::endl;
		return;
	}


	char buffer[MAX_CHAR_SIZE];
	sprintf(buffer, "%d", (int)getSprinklerStatus());
	fputs(buffer, fp);
	fputc('\n', fp);
	sprintf(buffer, "%.1f", getHumidity());
	fputs(buffer, fp);
	fputc('\n', fp);
	// converts float to char*
	sprintf(buffer, "%.1f", getSoilPH());
	fputs(buffer, fp);
	fputc('\n', fp);

	fclose(fp);
}