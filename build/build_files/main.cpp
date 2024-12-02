/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

For a C++ project simply rename the file to .cpp and re-run the build script

-- Copyright (c) 2020-2024 Jeffery Myers
--
--This software is provided "as-is", without any express or implied warranty. In no event
--will the authors be held liable for any damages arising from the use of this software.

--Permission is granted to anyone to use this software for any purpose, including commercial
--applications, and to alter it and redistribute it freely, subject to the following restrictions:

--  1. The origin of this software must not be misrepresented; you must not claim that you
--  wrote the original software. If you use this software in a product, an acknowledgment
--  in the product documentation would be appreciated but is not required.
--
--  2. Altered source versions must be plainly marked as such, and must not be misrepresented
--  as being the original software.
--
--  3. This notice may not be removed or altered from any source distribution.

*/

#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include "DroneSystem.h"
#include "UndergroundGarden.h"
#include <iostream>
#include "HMIHandler.h"
#include "MonsterContainmentUnit.h"
#include "ForceField.h"


#define DRONE_SCREEN 1
#define UDG_SCREEN 2
#define AQUARIUM_SCREEN 3
#define FACILITY_SCREEN 4
#define LASER_SCREEN 5
#define MONSTER_SCREEN 6


#define DRONE_SYSTEM_FILEPATH "dronesystem.txt"
#define UDG_SYSTEM_FILEPATH "undergroundgarden.txt"

int main() {
	SearchAndSetResourceDir("Screens");
	DroneSystem d;
	d.readDataFromFile(DRONE_SYSTEM_FILEPATH);
	UndergroundGarden u;
	u.readDataFromFile(UDG_SYSTEM_FILEPATH);

	BigLaser laser;   // Creates an instance of BigLaser
	Radar radar;      // Creates an instance of Radar

	MonsterContainmentUnit m;
	
	
	/*
	m.monitorVitals();
	m.updateHungerOverTime();
	m.checkHungerLevel();
	m.feedMonster();
	m.updateAngerOverTime(200);
	m.sedateMonster();
	m.releaseMonster();
	*/

	ForceField f;

	/*
	f.isForceFieldActive();
	f.detectBreach();
	f.chargeForceField(20);
	
	*/




	// Tell the window to use vysnc and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context

	int screenWidth = 1600;
	int screenHeight = 1000;

	InitWindow(screenWidth, screenHeight, "LairHMI");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	

	// Load a texture from the Screens directory
	Texture mainbackground = LoadTexture("MainSelectScreenLairHMI.png");
	Texture background = mainbackground;
	Texture droneBackground = LoadTexture("droneSystemBackground.png");
	Texture UDGBackground = LoadTexture("UndergroundGardenBackground.png");
	// the rest are currently not created
	Texture facilityBackground = LoadTexture("FacilityBg.png");
	Texture monsterBackground = LoadTexture("MonsterContainmentUnitBackground.png");
	Texture laserBackground = LoadTexture("");
	Texture aquariumBackground = LoadTexture("AquariumHMIBg.png");
	//All the Facility icon Textures (there are many)
	Texture openIcon = LoadTexture("POE-Open");
	Texture closedIcon = LoadTexture("POE-Closed");
	Texture breachedIcon = LoadTexture("POE-Breached");


	HMIHandler hmiHandler;

	Vector2 mousePoint = { 0.0f, 0.0f };

	SetTargetFPS(60);

	// HMI loop
	int currentScreen = 0;
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{

		mousePoint = GetMousePosition();
		
		// drawing
		BeginDrawing();

		// Setup the backbuffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		// draw our texture to the screen
		DrawTexture(background, 0, 0, WHITE);
		// detects when a menu button is clicked
		if (currentScreen == 0) {
			currentScreen = hmiHandler.menuButtonClicked(mousePoint);

			switch (currentScreen) {
			case DRONE_SCREEN:
				background = droneBackground;
				break;
			case UDG_SCREEN:
				background = UDGBackground;
				break;
			case AQUARIUM_SCREEN:
				background = aquariumBackground;
				break;
			case FACILITY_SCREEN:
				background = facilityBackground;
				break;
			case LASER_SCREEN:
				background = laserBackground;
				break;
			case MONSTER_SCREEN:
				background = monsterBackground;
				break;
				//intentional. do not want it to do anything on default
			default:
				break;
			}
		}
		else {
			bool menuButtonPressed = hmiHandler.returnToMenuButtonClicked(mousePoint);
			if (menuButtonPressed) {
				background = mainbackground;
				currentScreen = 0;
			}
		}
		if (currentScreen == DRONE_SCREEN) {
			hmiHandler.inDroneMenu(mousePoint, d);
		}
		if (currentScreen == UDG_SCREEN) {
			hmiHandler.inUDGMenu(mousePoint, u);
		}
		if (currentScreen == LASER_SCREEN) {
			hmiHandler.inLaserAndRadarMenu(mousePoint, laser, radar);
		}
		if (currentScreen == MONSTER_SCREEN) {
			auto startTime = std::chrono::high_resolution_clock::now();
			hmiHandler.inMonsterContainmentUnitMenu(mousePoint, m);
		}
			
		
		

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();

	}
	// cleanup
	// unload our texture so it can be cleaned up
	UnloadTexture(mainbackground);
	UnloadTexture(UDGBackground);
	UnloadTexture(droneBackground);
	UnloadTexture(monsterBackground);
	UnloadTexture(laserBackground);
	UnloadTexture(aquariumBackground);
	UnloadTexture(facilityBackground);
	UnloadTexture(openIcon);
	UnloadTexture(closedIcon);
	UnloadTexture(breachedIcon);

	// destory the window and cleanup the OpenGL context
	CloseWindow();
	
	return 0;

}
