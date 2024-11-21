#pragma once
#include <iostream>

using namespace std;

class MonsterContainmentUnit {
private:
    float angerLevel;
    float hungerLevel;
    bool containmentStatus;


public:
    MonsterContainmentUnit();
    ~MonsterContainmentUnit();
    void feedMonster();
    void monitorVitals();
    void sedateMonster();
    void releaseMonster();
    void checkAngerLevel();
    void checkHungerLevel();
    void updateHungerOverTime(float timeElapsed);
    void updateAngerOverTime(float timeElapsed);

    int getHungerLevel();
    float getAngerLevel();
    bool isContained();

};
