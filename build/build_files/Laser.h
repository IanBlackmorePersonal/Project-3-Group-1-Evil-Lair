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
    float firingCooldown;
    bool isCoolingDown;

public:
    BigLaser();
    void charge(int amount);
    void displayCharge() const;
    void setTarget(float latitude, float longitude);
    void activate();
    void fireLaser();
    int getCharge() const;
};