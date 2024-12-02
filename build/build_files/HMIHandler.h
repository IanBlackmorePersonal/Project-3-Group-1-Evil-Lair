#pragma once
#include "raylib.h"
#include "DroneSystem.h"
#include "UndergroundGarden.h"
#include "Laser.h"
#include "Radar.h"
#include "MonsterContainmentUnit.h"
#include "Aquarium-Handler.h"
#include "Facility-Handler.h"
class HMIHandler {
public:
    int menuButtonClicked(Vector2 mousePoint);
    bool returnToMenuButtonClicked(Vector2 mousePoint);
    void inDroneMenu(Vector2 mousePoint, DroneSystem& d);
    void drawUDG(UndergroundGarden& u);
    void inUDGMenu(Vector2 mousePoint, UndergroundGarden& u);
    void drawDrones(DroneSystem& d);
    void drawLaserAndRadar(BigLaser& laser, Radar& radar);
    void inLaserAndRadarMenu(Vector2 mousePoint, BigLaser& laser, Radar& radar);
    void handleLaserTargetInput(BigLaser& laser);
    void drawMonsterContainmentStats(MonsterContainmentUnit& m);

    void drawFacilityMap(Facility& f);
    void inFacilityMenu(Vector2 mousePoint, Facility& facility, bool& inLockdown);


    void inMonsterContainmentUnitMenu(Vector2 mousePoint, MonsterContainmentUnit& m);
private:
    char latitudeInput[10] = "0.0";
    char longitudeInput[10] = "0.0";
    bool isLatBoxActive = false;
    bool isLonBoxActive = false;
};