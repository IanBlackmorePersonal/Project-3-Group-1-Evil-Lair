#pragma once
#include <iostream>
using namespace std;

class ForceField {
private:
    bool forceFieldStatus;
    float chargingLevel;
    bool chargingStatus;
    string alertMessage;

public:
    ForceField();
    ~ForceField();
    void detectBreach();
    void chargeForceField(float timeElapsed);
    bool isForceFieldActive();
    float getChargeLevel();
    string getAlertMessage();
    void setForceFieldStatus(bool status);
};