#include "Radar.h"
#include <iostream>
#include <cstdlib> // For random entity generation
#include <ctime>   // For time seeding

Radar::Radar() : detectionRange(100.0), detectedEntities(0) {
    srand(time(0)); // Seed random number generator
}

void Radar::scanForEntities() {
    // Randomly generate number of entities for simulation
    detectedEntities = rand() % 10; // Up to 10 entities within range
    displayEntities();
}

void Radar::displayEntities() const {
    std::cout << "Detected entities within range: " << detectedEntities << "\n";
    //Will display number of entities based off of number
}