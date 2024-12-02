#include "Laser.h"
#include <iostream>
#include <thread>
#include <chrono>

BigLaser::BigLaser() : chargePercentage(0), isActivated(false), firingCooldown(5.0), isCoolingDown(false) {}

void BigLaser::charge(int amount) {
    if (isCoolingDown) {
        std::cout << "Laser is cooling down. Please wait.\n";
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
    std::cout << "Target set to Latitude: " << targetLatitude << ", Longitude: " << targetLongitude << "\n";
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

    // Fire the laser
    std::cout << "BOOM! Laser fired at target (" << targetLatitude << ", " << targetLongitude << ")!\n";
    chargePercentage = 0; // Reset charge after firing
    isCoolingDown = true; // Enter cooldown state

    // Cooldown simulation (non-blocking with a separate thread)
    std::thread([this]() {
        std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(firingCooldown)));
        isCoolingDown = false; // Exit cooldown state
        std::cout << "Laser is ready to be charged again.\n";
        }).detach();
}

bool BigLaser::isCooling() const {
    return isCoolingDown;
}

int BigLaser::getCharge() const {
    return chargePercentage;
}