#include "MonsterContainmentUnit.h"


MonsterContainmentUnit::MonsterContainmentUnit()
    : angerLevel(10.0), hungerLevel(80.0), containmentStatus(true){
    cout << "Monster containment unit initialized." << endl;
}



MonsterContainmentUnit::~MonsterContainmentUnit() {
    if (!containmentStatus) {
        cout << "Securing monster back in containment and resetting vitals." << endl;
        containmentStatus = true;
        angerLevel = 10.0;
        hungerLevel = 80.0;
        
    }
}

void MonsterContainmentUnit::feedMonster() {
    hungerLevel = max(0.0f, min(hungerLevel + 30, 100.0f));
    angerLevel = max(0.0f, min(angerLevel - 5, 100.0f));
}

void MonsterContainmentUnit::sedateMonster() {
    angerLevel = max(0.0f, min(angerLevel - 30, 100.0f));
}

void MonsterContainmentUnit::releaseMonster() {
    if (containmentStatus == true) {
        containmentStatus = false;
    }
}

void MonsterContainmentUnit::checkHungerLevel() {
   if (hungerLevel <= 25) {
        angerLevel = max(0.0f, min(angerLevel + 0.008f, 100.0f));
   }

}

void MonsterContainmentUnit::checkAngerLevel() {
    if (angerLevel > 90) { 
        releaseMonster();
    }
}

void MonsterContainmentUnit::updateHungerOverTime() {
    hungerLevel = max(0.0f, min(hungerLevel - (0.005f), 100.0f));
   
    if (hungerLevel < 50) {
        checkHungerLevel();
    }
}

void MonsterContainmentUnit::updateAngerOverTime() {
    angerLevel = max(0.0f, min(angerLevel + (0.003f), 100.0f));
    checkAngerLevel();
    
}

float MonsterContainmentUnit::getHungerLevel() {
    return hungerLevel;
}
float MonsterContainmentUnit::getAngerLevel() {
    return angerLevel;
}

bool MonsterContainmentUnit::getContainmentStatus() {
    return containmentStatus;
}


void MonsterContainmentUnit::setHungerLevel(float HungerLevel) {
    hungerLevel = HungerLevel;
}
void MonsterContainmentUnit::setAngerLevel(float AngerLevel) {
    angerLevel = AngerLevel;
}

void MonsterContainmentUnit::setContainmentStatus(bool ContainmentStatus) {
    ContainmentStatus = containmentStatus;
}

void MonsterContainmentUnit::MCUwriteToFile(const string& filename) {
    ofstream outFile(filename, ios::out);
    if (outFile.is_open()) {
        outFile << hungerLevel << endl;
        outFile << angerLevel << endl;
        outFile << containmentStatus << endl;
        cout << "Monster containment unit state saved to " << filename << endl;
        outFile.close();
    }
    else {
        cerr << "Error: Unable to open file for writing: " << filename << endl;
    }
}

void MonsterContainmentUnit::MCUreadFromFile(const string& filename) {
    ifstream inFile(filename, ios::in);
    if (inFile.is_open()) {
        inFile >> hungerLevel;
        inFile >> angerLevel;
        inFile >> containmentStatus;
        cout << "Monster containment unit state loaded from " << filename << endl;
        inFile.close();
    }
    else {
        cerr << "Error: Unable to open file for reading: " << filename << endl;
    }
}

