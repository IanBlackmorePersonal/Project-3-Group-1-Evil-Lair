#pragma once

#include <math.h>
#include <stdio.h>

#define TANKNAMELEN 20

/*
TO DO:
This one's pretty ok, but here are the outstanding issues
- UNTESTED
- WATER QUALITY CALCULATION IS PROBABLY SHIT (based on oxygenation and pH, the pH bit I think is ok, oxygenation probs broke)
- ALERTS (checkValues should return an int (0 for pH, 1 for oxygen, 2 for temperature) if something's out of range)

*/

class Tank {
	char TankName[TANKNAMELEN];
	int population;
	double waterQuality, pH, oxygenation, temperature;


public:
	Tank();
	void setTankName(char* name);
	char* getTankName();
	void setPopulation(int pop);
	int getPopulation();
	void setWaterQuality(double waterQ);
	double getWaterQuality();
	void setpH(double pH);
	double getpH();
	void setOxygenation(double oxygenation);
	double getOxygenation();
	void setTemperature(double temperature);
	double getTemperature();

	Tank newTank(int population, char* tankName);

	void alterPop(int alteration);
	void alterPH(double alteration);
	void alterOxygenation(double alteration);
	void alterTemperature(double alteration);

	void calculateWaterQuality();

	int checkValues();

	void emptyTank();
};
