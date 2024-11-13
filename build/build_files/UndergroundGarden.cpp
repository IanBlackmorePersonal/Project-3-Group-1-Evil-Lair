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
}
void UndergroundGarden::setSoilPH(float input) {
	soilPHLevel = input;
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