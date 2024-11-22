#pragma once

#include "Aquarium-Animal.h"
#include <math.h>
#include <stdio.h>

#define TANKNAMELEN 20

class Tank {
	char TankName[TANKNAMELEN];
	int population;
	Animal tankAnimal;
	double waterQuality, pH, oxygenation, temperature;


public:
	Tank();
	void setTankName(char* name);
	char* getTankName();
	void setPopulation(int pop);
	int getPopulation();
	void setAnimal(Animal animal);
	Animal getAnimal();
	void setWaterQuality(double waterQ);
	double getWaterQuality();
	void setpH(double pH);
	double getpH();
	void setOxygenation(double oxygenation);
	double getOxygenation();
	void setTemperature(double temperature);
	double getTemperature();

	void alterPop(int alteration);
	void alterPH(double alteration);
	void alterOxygenation(double alteration);
	void alterTemperature(double alteration);

	void calculateWaterQuality();

	int checkValues();

	void emptyTank();
};
