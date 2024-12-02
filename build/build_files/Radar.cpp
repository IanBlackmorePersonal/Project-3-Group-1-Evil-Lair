#include "Radar.h"
#include <iostream>
#include <cstdlib> // For random entity generation
#include <ctime>   // For time seeding

Radar::Radar() : detectionRange(100.0), detectedEntities(0) {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
}

void Radar::scanForEntities() {
    // Randomly generate the number of entities for simulation
    detectedEntities = rand() % 10; // Up to 10 entities within range
    displayEntities();
}

void Radar::resetEntities() {
    detectedEntities = 0; // Reset the count to 0
    std::cout << "Entities have been reset to 0.\n";
}

void Radar::displayEntities() const {
    std::cout << "Detected entities within range: " << detectedEntities << "\n";
}

int Radar::getDetectedEntities() const {
    return detectedEntities;
}