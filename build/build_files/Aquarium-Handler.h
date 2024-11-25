#pragma once
#include "Aquarium-Tank.h"
#include <string.h>
#include <stdio.h>

class Aquarium
{
	Tank tanks[4];
	bool alertStatus;
	char* filename;


public:
	Aquarium();

	int readFile();

	void updateTank(int TankNo, double pHUpdate, double tempUpdate, double oxygenationUpdate);
	
	int transferToQuarantine(int TankNo);
};
