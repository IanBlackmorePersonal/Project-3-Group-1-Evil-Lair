#pragma once
#include "raylib.h"
#include "DroneSystem.h"
#include "UndergroundGarden.h"
class HMIHandler {
public:
	int menuButtonClicked(Vector2 mousePoint);
	bool returnToMenuButtonClicked(Vector2 mousePoint);
	void inDroneMenu(Vector2 mousePoint, DroneSystem &d);
	void drawUDG(UndergroundGarden& u);
	void inUDGMenu(Vector2 mousePoint, UndergroundGarden &u);
	void drawDrones(DroneSystem& d);
};