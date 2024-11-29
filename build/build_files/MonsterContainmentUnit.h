#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>
#include <fstream>
#include <string>

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
    void sedateMonster();
    void releaseMonster();
    void checkAngerLevel();
    void checkHungerLevel();
    void updateHungerOverTime();
    void updateAngerOverTime();


    float getHungerLevel();
    float getAngerLevel();
    bool getContainmentStatus();
    void setHungerLevel(float hungerAmount);
    void setAngerLevel(float angerLevel);
    void setContainmentStatus(bool containmentStatus);

    void MCUwriteToFile(const string& filename);
    void MCUreadFromFile(const string& filename);
};