#include "Aquarium-Tank.h"
#include <stdlib.h>
#include <string>
#include <math.h>

Tank::Tank()
{
	pH = 7;
	temperature = 25.8;
	oxygenation = 90;
	waterQuality = 100;
	population = 5;
	strcpy(TankName, "TankDefault\n");
}

void Tank::setTankName(char* name)
{
	strncpy(this->TankName, name, TANKNAMELEN);
}

char* Tank::getTankName()
{
	return TankName;
}

void Tank::setPopulation(int pop)
{
	this->population = pop;
}

int Tank::getPopulation()
{
	return population;
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

Tank Tank::newTank(int population, char* tankName)
{
	Tank t;
	pH = 7;
	temperature = 25.8;
	oxygenation = 90;
	waterQuality = 100;
	this->population = population;
	strcpy(TankName, tankName);
	return t;
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
	calculatedVal += (50 - (fabs(pH - 7)*50));
	calculatedVal += 50 - (abs(oxygenation - 90) % 50);
	waterQuality = calculatedVal;
}

int Tank::checkValues() {
	if (fabs(pH - 7) >= 1) {
		printf("pH Alert! Out of Acceptable Range!!!\n");
		return 1;
	}
	else if (fabs(temperature - 25.8) >= 0.7) {
		printf("Temperature Alert! Temperature out of acceptable range!\n");
		return 2;
	}
	else if (fabs(oxygenation - 90) >= 10) {
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
