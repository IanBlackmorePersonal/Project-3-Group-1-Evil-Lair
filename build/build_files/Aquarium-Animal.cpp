#include "Aquarium-Animal.h"

void Animal::setSpecies(char* species)
{
	strncpy(this->species, species, ANIMALCHARLEN);
}

char* Animal::getSpecies()
{
	return this->species;
}
