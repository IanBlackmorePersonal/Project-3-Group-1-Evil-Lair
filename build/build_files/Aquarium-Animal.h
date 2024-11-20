#pragma once

#define ANIMALCHARLEN 25

class Animal {
	bool sick;
	char species [ANIMALCHARLEN];

public:
	void setSick(bool sick);
	bool getSick();
	void setSpecies(char* species);
	char* getSpecies();
	Animal createAnimal(bool sick, char* species);
};