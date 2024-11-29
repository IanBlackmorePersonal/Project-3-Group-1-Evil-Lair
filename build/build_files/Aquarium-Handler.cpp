#include "Aquarium-Handler.h"

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
	char line[LINELENGTH];
	fread(line, sizeof(char), LINELENGTH, file);
	//AAAAAAAAAAAAAAA
	return 0;
}

void Aquarium::updateTank(int TankNo, double pHUpdate, double tempUpdate, double oxygenationUpdate)
{
}

int Aquarium::transferToQuarantine(int TankNo)
{
	return 0;
}
