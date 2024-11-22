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
#include "HMIHandler.
#include "MonsterContainmentUnit.h"
#include "ForceField.h"

=======
#define DRONE_SCREEN 1
#define UDG_SCREEN 2
#define AQUARIUM_SCREEN 3
#define FACILITY_SCREEN 4
#define LASER_SCREEN 5
#define MONSTER_SCREEN 6



int main() {
	DroneSystem d(3);
	std::cout << "Drones amount = " << d.drones.size() << std::endl;
	std::cout << "Drones status base = " << d.drones[0]->getStatus() << std::endl;
	d.deployDrones();
	std::cout << "Drones status deployed = " << d.drones[0]->getStatus() << std::endl;
	d.drones[2]->setBatteryLevel(70.2f);

	UndergroundGarden u;
	std::cout << "Humidity = " << u.getHumidity() << std::endl;
	u.setHumidity(70);
	std::cout << "Humidity after set = " << u.getHumidity() << std::endl;

	MonsterContainmentUnit m;
	m.monitorVitals();
	m.updateHungerOverTime(18.2);
	m.checkHungerLevel();
	m.feedMonster();
	m.updateAngerOverTime(200);
	m.sedateMonster();
	m.releaseMonster();

	ForceField f;
	f.isForceFieldActive();
	f.detectBreach();
	f.chargeForceField(20);
	





	// Tell the window to use vysnc and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context

	int screenWidth = 1600;
	int screenHeight = 1000;

	InitWindow(screenWidth, screenHeight, "LairHMI");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("Screens");

	// Load a texture from the Screens directory
	Texture mainbackground = LoadTexture("MainSelectScreenLairHMI.png");
	Texture background = mainbackground;
	Texture droneBackground = LoadTexture("droneSystemBackground.png");
	Texture UDGBackground = LoadTexture("UndergroundGardenBackground.png");
	// the rest are currently not created
	Texture facilityBackground = LoadTexture("UndergroundGardenBackground.png");
	Texture monsterBackground = LoadTexture("UndergroundGardenBackground.png");
	Texture laserBackground = LoadTexture("UndergroundGardenBackground.png");
	Texture aquariumBackground = LoadTexture("UndergroundGardenBackground.png");

	HMIHandler hmiHandler;

	Vector2 mousePoint = { 0.0f, 0.0f };

	SetTargetFPS(60);


	// drawing
	BeginDrawing();

	// Setup the backbuffer for drawing (clear color and depth buffers)
	ClearBackground(BLACK);

	// draw our texture to the screen
	DrawTexture(background, 0, 0, WHITE);

	// end the frame and get ready for the next one  (display frame, poll input, etc...)
	EndDrawing();
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

	// destory the window and cleanup the OpenGL context
	CloseWindow();
	return 0;

}