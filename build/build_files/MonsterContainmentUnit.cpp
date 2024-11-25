#include "MonsterContainmentUnit.h"


auto startTime = std::chrono::high_resolution_clock::now();

MonsterContainmentUnit::MonsterContainmentUnit()
    : angerLevel(10.0), hungerLevel(80.0), containmentStatus(true), timeElapsed(0.1) {
    cout << "Monster containment unit initialized." << endl;
}



MonsterContainmentUnit::~MonsterContainmentUnit() {
    if (!containmentStatus) {
        cout << "Securing monster back in containment and resetting vitals." << endl;
        containmentStatus = true;
        angerLevel = 10.0;
        hungerLevel = 80.0;
        
    }
    timeElapsed = 0.0;
}

void MonsterContainmentUnit::feedMonster() {
    hungerLevel = max(0.0f, min(hungerLevel + 30, 100.0f));
    angerLevel = max(0.0f, min(angerLevel - 5, 100.0f));
}

void MonsterContainmentUnit::monitorVitals() {
    cout << "Monitoring vitals - Hunger: " << hungerLevel << "%, Anger: "
        << angerLevel << endl;
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
        angerLevel = max(0.0f, min(angerLevel + 50, 100.0f));
   }

}

void MonsterContainmentUnit::checkAngerLevel() {
    if (angerLevel > 90) { 
        releaseMonster();
    }
}

void MonsterContainmentUnit::updateHungerOverTime() {
    hungerLevel = max(0.0f, min(hungerLevel - (timeElapsed * 0.0005f), 100.0f));
   
    if (hungerLevel < 50) {
        checkHungerLevel();
    }
}

void MonsterContainmentUnit::updateAngerOverTime() {
    angerLevel = max(0.0f, min(angerLevel + (timeElapsed, 0.0005f), 100.0f));
    checkAngerLevel();
    
}

float MonsterContainmentUnit::getHungerLevel() {
    return hungerLevel;
}
float MonsterContainmentUnit::getAngerLevel() {
    return angerLevel;
}

float MonsterContainmentUnit::getTimeElapsed() {
    return timeElapsed;
}
bool MonsterContainmentUnit::isContained() {
    return containmentStatus;
}





void MonsterContainmentUnit::updateTimeElapsed() {

    auto currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsed = currentTime - startTime;
    timeElapsed = elapsed.count();

}