#pragma once


class Tank {
	enum animal;
	int waterQuality, population;
	double pH, oxygenation, temperature;

public:
	void setPopulation();
	int getPopulation();
	void setWaterQuality();
	int getWaterQuality();
	void setPH();
	double getPH();
	void setOxy();
	double getOxy();
	void setTemp();
	double getTemp();
	void setAnimal();
	animal getAnimal();
};
