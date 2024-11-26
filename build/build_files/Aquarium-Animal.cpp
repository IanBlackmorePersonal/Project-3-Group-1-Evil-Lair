#include "Aquarium-Animal.h"

void Animal::setSpecies(char* species)
{
	strncpy(this->species, species, ANIMALCHARLEN);
}

char* Animal::getSpecies()
{
	return this->species;
}

Animal Animal::createAnimal(char* species)
{
	Animal a;
	a.setSpecies(species);
	return a;
}
