#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>

using namespace std;

class MonsterContainmentUnit {
private:
    float angerLevel;
    float hungerLevel;
    bool containmentStatus;
    float timeElapsed;


public:
    MonsterContainmentUnit();
    ~MonsterContainmentUnit();
    void feedMonster();
    void monitorVitals();
    void sedateMonster();
    void releaseMonster();
    void checkAngerLevel();
    void checkHungerLevel();
    void updateHungerOverTime();
    void updateAngerOverTime();

    float getHungerLevel();
    float getAngerLevel();
    float getTimeElapsed();
    bool isContained();
    void updateTimeElapsed();

 
};
