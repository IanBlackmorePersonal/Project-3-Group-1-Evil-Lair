#include "Aquarium-Tank.h"
#include <math.h>

void Tank::setPopulation(int pop)
{
	this->population = pop;
}

int Tank::getPopulation()
{
	return population;
}

void Tank::setAnimal(Animal animal)
{
	this->tankAnimal = animal;
}

Animal Tank::getAnimal()
{
	return tankAnimal;
}

void Tank::setWaterQuality(double waterQ)
{
	this->waterQuality = waterQ;
}

double Tank::getWaterQuality()
{
	return waterQuality;
}

void Tank::setpH(double pH)
{
	this->pH = pH;
}

double Tank::getpH()
{
	return pH;
}

void Tank::setOxygenation(double oxygenation) {
	this->oxygenation = oxygenation;
}

double Tank::getOxygenation() {
	return oxygenation;
}

void Tank::setTemperature(double temperature) {
	this->temperature = temperature;
}

double Tank::getTemperature() {
	return temperature;
}

void Tank::alterPop(int alteration) {
	this->population += alteration;
}

void Tank::alterPH(double alteration) {
	this->pH += alteration;
}

void Tank::alterOxygenation(double alteration) {
	this->oxygenation += alteration;
}

void Tank::alterTemperature(double alteration) {
	this->temperature += alteration;
}

void Tank::calculateWaterQuality() {
	//this is wrong 100%
	double calculatedVal = 0.0;
	calculatedVal += abs(pH - 7)*50;
	calculatedVal += abs(oxygenation - 90) * 50;
	waterQuality = calculatedVal;
}

int Tank::checkValues() {
	if (abs(pH - 7) >= 1) {
		printf("pH Alert! Out of Acceptable Range!!!\n");
		return 1;
	}
	else if (abs(temperature - 25.8) >= 0.7) {
		printf("Temperature Alert! Temperature out of acceptable range!\n");
		return 2;
	}
	else if (abs(oxygenation - 90) >= 10) {
		printf("Oxygenation Alert! Oxygentation out of acceptable range!\n");
		return 3;
	}
	else if (waterQuality <= 70) {
		printf("Warning: Water Quality Dipping below acceptable levels!\n");
		return 4;
	}
	else
		return 0;
}

void Tank::emptyTank() {
	this->setPopulation(0);
}