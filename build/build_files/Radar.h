#pragma once
class Radar {
private:
    float detectionRange;
    int detectedEntities;

public:
    Radar();
    void scanForEntities();
    void displayEntities() const;
};