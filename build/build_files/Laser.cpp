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
    displayCharge();
}

void BigLaser::displayCharge() const {
    std::cout << "Current charge: " << chargePercentage << "%\n";
    //current charge % based, display bar based on number 
}

void BigLaser::setTarget(float latitude, float longitude) {
    targetLatitude = latitude;
    targetLongitude = longitude;
    //XY coords for firing 
}

void BigLaser::activate() {
    if (chargePercentage >= 100) {
        isActivated = true;
        //Laser is ready to fire --> turn light green 
    }
    else {
        //Laser isnt ready to fire --> turn light red
    }
}

void BigLaser::fireLaser() {
    if (!isActivated) {
        std::cout << "Laser is not activated. Cannot fire.\n";
        return;
    }
    if (chargePercentage < 100) {
        //not charged 
        return;
    }
    if (isCoolingDown) {
        //not charged 
        return;
    }

    chargePercentage = 0;
    displayCharge();
    isCoolingDown = true;

    // Start cooldown timer
    std::this_thread::sleep_for(std::chrono::seconds(5));
    isCoolingDown = false;
    std::cout << "Laser is ready to be charged again.\n";
}