#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ForceField {
private:
    bool forceFieldStatus;
    float chargingLevel;
    bool chargingStatus;
    string alertMessage;

public:
    ForceField();
 
    void detectBreach();
    void chargeForceField();
    bool isForceFieldActive();
    float getChargeLevel();
    void setForceFieldStatus(bool status);
    void setForceFieldCharge(float charge);
    void setForceFieldChargingStatus(bool chargingStatus);
    void forceFieldAttack(float damage);
    float timeToFullCharge();
    void FFwriteToFile(const string& filename);
    void FFreadFromFile(const string& filename);


};