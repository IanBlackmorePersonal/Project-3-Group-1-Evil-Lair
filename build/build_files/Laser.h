#pragma once
#include <iostream>
#include <thread>
#include <chrono>

class BigLaser {
private:
    int chargePercentage;
    float targetLatitude;
    float targetLongitude;
    bool isActivated;
    float firingCooldown; // Cooldown duration in seconds
    bool isCoolingDown;   // Laser cooling state

public:
    BigLaser();
    void charge(int amount);       // Charges the laser
    void fireLaser();              // Fires the laser
    void displayCharge() const;    // Displays the current charge
    void setTarget(float latitude, float longitude); // Sets the target coordinates
    void activate();               // Activates the laser
    bool isCooling() const;        // Returns whether the laser is cooling
    int getCharge() const;         // Returns the current charge level
};