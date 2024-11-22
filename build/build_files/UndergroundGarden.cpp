#include "UndergroundGarden.h"

UndergroundGarden::UndergroundGarden() {
	sprinklerStatus = false;
	soilPHLevel = 7.0F;
	humidityLevel = 80.0F;

}
UndergroundGarden::~UndergroundGarden() {
	sprinklerStatus = false;
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