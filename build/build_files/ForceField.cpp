#include "ForceField.h"

ForceField::ForceField() : forceFieldStatus(true), chargingLevel(100.0), chargingStatus(false), alertMessage("") {
    cout << "Force field activated." << endl;
}

ForceField::~ForceField() {
    cout << "Cleaning up force field resources." << endl;
}

void ForceField::detectBreach() {
    if (!forceFieldStatus) {
        alertMessage = "Warning: Force field breached!";
        cout << alertMessage << endl;
    }
}

void ForceField::chargeForceField(float timeElapsed) {
    chargingStatus = true;
    chargingLevel = max(0.0f, min(chargingLevel - (timeElapsed * 0.5f), 100.0f));
    cout << "Charging force field. Charge level: " << chargingLevel << "%" << endl;
    if (chargingLevel >= 100) {
        chargingStatus = false;
        forceFieldStatus = true;
        alertMessage = "Force field fully charged and active.";
        cout << alertMessage << endl;
    }
}

bool ForceField::isForceFieldActive() {
    return forceFieldStatus;
}
float ForceField::getChargeLevel() {
    return chargingLevel;
}
string ForceField::getAlertMessage() {
    return alertMessage;
}

void ForceField::setForceFieldStatus(bool status) {
    forceFieldStatus = status;
}