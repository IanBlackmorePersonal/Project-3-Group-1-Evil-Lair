#include "Aquarium-Handler.h"
#include <stdlib.h>

using namespace std;

Aquarium::Aquarium()
{

	tanks[0].newTank(3, "Eels");
	tanks[1].newTank(6, "Sharks");
	tanks[2].newTank(4, "Mantis Shrimp");
	tanks[3].newTank(0, "Quarantine");
	alertStatus = false;
	filename = "AquariumUpdates.txt";
}

int Aquarium::readFile()
{
	FILE* file = fopen(filename, "r");
	string line;
	char buffer[LINELENGTH];
	fread(buffer, sizeof(char), LINELENGTH, file);

	line = buffer;
	//AAAAAAAAAAAAAAA
	double pHupdate = stof(line.substr(0, 2));
	double tempUpdate = stof(line.substr(4, 7));
	double oxygenUpdate = stof(line.substr(8, 10));
	updateTank(0, pHupdate, tempUpdate, oxygenUpdate);

	return 0;
}

void Aquarium::updateTank(int TankNo, double pHUpdate, double tempUpdate, double oxygenationUpdate)
{
	tanks[TankNo].alterOxygenation(oxygenationUpdate);
	tanks[TankNo].alterPH(pHUpdate);
	tanks[TankNo].alterTemperature(tempUpdate);
	tanks[TankNo].calculateWaterQuality();
}

int Aquarium::transferToQuarantine(int TankNo)
{
	if (tanks[3].getPopulation() == 0) {
		tanks[TankNo].alterPop(-1);
		tanks[3].alterPop(1);
		return 0;
	}
	else
		printf("Quarantine Tank Already In Use");
	
	return 1;
}
