#pragma once

class Radar {
private:
    float detectionRange;
    int detectedEntities;

public:
    Radar();
    void scanForEntities();       // Scans for entities
    void resetEntities();         // Resets the detected entities to 0
    void displayEntities() const; // Displays entities in the console
    int getDetectedEntities() const; // Returns the number of detected entities
};