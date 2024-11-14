#include "MonsterContainmentUnit.h"

MonsterContainmentUnit::MonsterContainmentUnit()
    : angerLevel(10.0), hungerLevel(100), containmentStatus(true) {
    cout << "Monster containment unit initialized." << endl;
}

MonsterContainmentUnit::~MonsterContainmentUnit() {
    if (!containmentStatus) {
        cout << "Securing monster back in containment and resetting vitals." << endl;
        containmentStatus = true;
        angerLevel = 10.0;
        hungerLevel = 100;
    }
}

void MonsterContainmentUnit::feedMonster() {
    hungerLevel = max(0.0f, min(hungerLevel + 30, 100.0f));
    cout << "Feeding monster. Hunger level: " << hungerLevel << "%" << endl;
}

void MonsterContainmentUnit::monitorVitals() {
    cout << "Monitoring vitals - Hunger: " << hungerLevel << "%, Anger: "
        << angerLevel << endl;
}

void MonsterContainmentUnit::sedateMonster() {
    angerLevel = max(0.0f, min(angerLevel - 30, 100.0f));
    cout << "Sedating monster. Anger Level is now: " << angerLevel << "%" << endl;
}

void MonsterContainmentUnit::releaseMonster() {
    if (containmentStatus == true) {
        containmentStatus = false;
        cout << "Monster has been released!" << endl;
    }
}

void MonsterContainmentUnit::checkHungerLevel() {
    if (hungerLevel < 50) {
        cout << "Warning: Monster is hungry" << endl;
        angerLevel = max(0.0f, min(angerLevel + 30, 100.0f));
    }
    else if (hungerLevel <= 25) {
        cout << "Warning: Monster is starving!" << endl;
        angerLevel = max(0.0f, min(angerLevel + 50, 100.0f));
    }

}

void MonsterContainmentUnit::checkAngerLevel() {
    if (angerLevel > 80) {
        cout << "Warning: Monster anger level is high!" << endl;
    }
    if (angerLevel > 90) {
        cout << "Warning: Monsters anger level has surpassed threshold!" << endl;
        releaseMonster();
    }
}

void MonsterContainmentUnit::updateHungerOverTime(float timeElapsed) {
    hungerLevel = max(0.0f, min(hungerLevel - (timeElapsed * 0.5f), 100.0f));
    if (hungerLevel < 50) {
        checkHungerLevel();
    }
    cout << "Updated hunger level based on time: " << hungerLevel << "%" << endl;
}

void MonsterContainmentUnit::updateAngerOverTime(float timeElapsed) {
    angerLevel = max(0.0f, min(angerLevel + (timeElapsed * 0.2f), 100.0f));
    checkAngerLevel();
    cout << "Updated anger level based on time: " << angerLevel << "%" << endl;
}

int MonsterContainmentUnit::getHungerLevel() {
    return hungerLevel;
}
float MonsterContainmentUnit::getAngerLevel() {
    return angerLevel;
}
bool MonsterContainmentUnit::isContained() {
    return containmentStatus;
}

