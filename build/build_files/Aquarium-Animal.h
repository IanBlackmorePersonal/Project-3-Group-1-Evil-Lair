#pragma once

#define ANIMALCHARLEN 25
#include <string.h>

class Animal {

	char species[ANIMALCHARLEN];

public:
	void setSpecies(char* species);
	char* getSpecies();
	Animal createAnimal(char* species);
};