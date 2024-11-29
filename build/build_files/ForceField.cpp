#include "ForceField.h"

ForceField::ForceField() : forceFieldStatus(true), chargingLevel(100.0), chargingStatus(false), alertMessage("") {
    cout << "Force field activated." << endl;
}


void ForceField::detectBreach() {
    if (!forceFieldStatus) {
        alertMessage = "Warning: Force field breached!";
        cout << alertMessage << endl;
    }
}

void ForceField::chargeForceField() {
    if (forceFieldStatus == true) {
        if (chargingStatus == true) {
            chargingLevel = max(0.0f, min(chargingLevel + (0.005f), 100.0f));
        }
        if (chargingLevel >= 100) {
            chargingStatus = false;
            forceFieldStatus = true;
        }
    }
   
}

void ForceField::forceFieldAttack(float damage) {
    chargingLevel = chargingLevel - damage;
}

bool ForceField::isForceFieldActive() {
    return forceFieldStatus;
}
float ForceField::getChargeLevel() {
    return chargingLevel;
}


void ForceField::setForceFieldStatus(bool status) {
    forceFieldStatus = status;
}

void ForceField::setForceFieldCharge(float chargeLevel) {
    chargingLevel = chargeLevel;
}

void ForceField::setForceFieldChargingStatus(bool ChargingStatus) {
    chargingStatus = ChargingStatus;
}

float ForceField::timeToFullCharge() {
    if (chargingLevel >= 100.0f || !chargingStatus) {
        return 0.0f; // Already fully charged or not charging
    }

    float chargeRate = 0.005f; // The rate of charge per call
    float remainingCharge = 100.0f - chargingLevel;

    // Calculate the number of calls needed and convert to seconds
    float callsNeeded = remainingCharge / chargeRate;
    float timeInSeconds = callsNeeded * (1.0f / 60.0f); // 60 FPS interval
    return timeInSeconds;
}


void ForceField::FFwriteToFile(const string& filename) {
    ofstream outFile(filename, ios::out);
    if (outFile.is_open()) {
        outFile << forceFieldStatus << endl;
        outFile << chargingLevel << endl;
        outFile << chargingStatus << endl;
        outFile << alertMessage << endl;
        cout << "Force field state saved to " << filename << endl;
        outFile.close();
    }
    else {
        cerr << "Error: Unable to open file for writing: " << filename << endl;
    }
}

void ForceField::FFreadFromFile(const string& filename) {
    ifstream inFile(filename, ios::in);
    if (inFile.is_open()) {
        inFile >> forceFieldStatus;
        inFile >> chargingLevel;
        inFile >> chargingStatus;
        inFile.ignore(); // Ignore the newline before reading the string
        getline(inFile, alertMessage);
        cout << "Force field state loaded from " << filename << endl;
        inFile.close();
    }
    else {
        cerr << "Error: Unable to open file for reading: " << filename << endl;
    }
}