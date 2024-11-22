#include "Laser.h"
#include <iostream>
#include <thread>
#include <chrono>

BigLaser::BigLaser() : chargePercentage(0), isActivated(false), firingCooldown(5.0), isCoolingDown(false) {}

void BigLaser::charge(int amount) {
    if (isCoolingDown) {
        std::cout << "Laser is in cooldown. Please wait.\n";
        return;
    }

    chargePercentage += amount;
    if (chargePercentage > 100) chargePercentage = 100;

    if (chargePercentage == 100) {
        activate(); // Automatically activate when fully charged
        std::cout << "Laser is fully charged and activated!\n";
    }

    displayCharge();
}

void BigLaser::displayCharge() const {
    std::cout << "Current charge: " << chargePercentage << "%\n";
}

void BigLaser::setTarget(float latitude, float longitude) {
    targetLatitude = latitude;
    targetLongitude = longitude;
}

void BigLaser::activate() {
    if (chargePercentage >= 100 && !isCoolingDown) {
        isActivated = true;
        std::cout << "Laser is activated and ready to fire.\n";
    }
    else {
        std::cout << "Laser cannot be activated. Ensure it is fully charged and not cooling down.\n";
    }
}

void BigLaser::fireLaser() {
    if (isCoolingDown) {
        std::cout << "Laser is cooling down. Cannot fire.\n";
        return;
    }

    if (chargePercentage < 100) {
        std::cout << "Laser is not fully charged. Charge to 100% to fire.\n";
        return;
    }

    std::cout << "Firing laser at target (" << targetLatitude << ", " << targetLongitude << ")!\n";
    chargePercentage = 0; // Reset charge after firing
    displayCharge();
    isCoolingDown = true;

    // Start cooldown timer (simulated with sleep)
    std::this_thread::sleep_for(std::chrono::seconds(5));
    isCoolingDown = false;
    std::cout << "Laser is ready to be charged again.\n";
}

int BigLaser::getCharge() const {
    return chargePercentage;
}