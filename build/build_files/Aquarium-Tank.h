#pragma once
#include "Aquarium-Animal.h"


class Tank {
	int population;
	Animal tankAnimal;
	double waterQuality, pH, oxygenation, temperature;


public:
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
};