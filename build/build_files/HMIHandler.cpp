#include "HMIHandler.h"
#include <iostream>
#include "raylib.h"
#define MAIN_BUTTON_WIDTH 500
#define MAIN_BUTTON_HEIGHT 100
#define DRONE_SYSTEM_BUTTON_X 900
#define DRONE_SYSTEM_BUTTON_Y 685

#define GARDEN_BUTTON_X 200
#define GARDEN_BUTTON_Y 685

#define FACILITY_BUTTON_X 200
#define FACILITY_BUTTON_Y 85

#define MONSTER_BUTTON_X 200
#define MONSTER_BUTTON_Y 385

#define AQUARIUM_BUTTON_X 900
#define AQUARIUM_BUTTON_Y 85

#define LASER_BUTTON_X 900
#define LASER_BUTTON_Y 385

#define MENU_BUTTON_X 1450
#define MENU_BUTTON_Y 850

int HMIHandler::menuButtonClicked(Vector2 mousePoint) {
	// these ifs all determine if the mouse is within a button's boundaries and if the mouse is clicked
	if (mousePoint.x > DRONE_SYSTEM_BUTTON_X && mousePoint.x < DRONE_SYSTEM_BUTTON_X + MAIN_BUTTON_WIDTH) {
		if (mousePoint.y > DRONE_SYSTEM_BUTTON_Y && mousePoint.y < DRONE_SYSTEM_BUTTON_Y + MAIN_BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				std::cout << "clicked drone system button" << std::endl;
				return 1;
			}
		}
	}
	if (mousePoint.x > GARDEN_BUTTON_X && mousePoint.x < GARDEN_BUTTON_X + MAIN_BUTTON_WIDTH) {
		if (mousePoint.y > GARDEN_BUTTON_Y && mousePoint.y < GARDEN_BUTTON_Y + MAIN_BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				std::cout << "clicked garden system button" << std::endl;
				return 2;
			}
		}
	}
	if (mousePoint.x > AQUARIUM_BUTTON_X && mousePoint.x < AQUARIUM_BUTTON_X + MAIN_BUTTON_WIDTH) {
		if (mousePoint.y > AQUARIUM_BUTTON_Y && mousePoint.y < AQUARIUM_BUTTON_Y + MAIN_BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				std::cout << "clicked aquarium system button" << std::endl;
				return 3;
			}
		}
	}
	if (mousePoint.x > FACILITY_BUTTON_X && mousePoint.x < FACILITY_BUTTON_X + MAIN_BUTTON_WIDTH) {
		if (mousePoint.y > FACILITY_BUTTON_Y && mousePoint.y < FACILITY_BUTTON_Y + MAIN_BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				std::cout << "clicked facility system button" << std::endl;
				return 4;
			}
		}
	}
	if (mousePoint.x > LASER_BUTTON_X && mousePoint.x < LASER_BUTTON_X + MAIN_BUTTON_WIDTH) {
		if (mousePoint.y > LASER_BUTTON_Y && mousePoint.y < LASER_BUTTON_Y + MAIN_BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				std::cout << "clicked laser system button" << std::endl;
				return 5;
			}
		}
	}
	if (mousePoint.x > MONSTER_BUTTON_X && mousePoint.x < MONSTER_BUTTON_X + MAIN_BUTTON_WIDTH) {
		if (mousePoint.y > MONSTER_BUTTON_Y && mousePoint.y < MONSTER_BUTTON_Y + MAIN_BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				std::cout << "clicked monster system button" << std::endl;
				return 6;
			}
		}
	}


	return 0;
}

bool HMIHandler::returnToMenuButtonClicked(Vector2 mousePoint) {
	if (mousePoint.x > MENU_BUTTON_X && mousePoint.x < MENU_BUTTON_X + 100) {
		if (mousePoint.y > MENU_BUTTON_Y && mousePoint.y < MENU_BUTTON_Y + 100) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				std::cout << "clicked menu button" << std::endl;
				return true;
			}
		}
	}
	return false;
}


#define RECALL_BUTTON_X 380
#define RECALL_BUTTON_Y 623
#define DEPLOY_BUTTON_X 380
#define DEPLOY_BUTTON_Y 777
#define LARGE_BUTTON_WIDTH 840
#define LARGE_BUTTON_HEIGHT 100

#define REPAIR_BUTTON_1_X 72
#define REPAIR_BUTTON_2_X 559
#define REPAIR_BUTTON_3_X 1084
#define REPAIR_BUTTON_Y 458
#define DRONE_SMALL_BUTTON_WIDTH 200
#define DRONE_SMALL_BUTTON_HEIGHT 120

#define CHARGE_BUTTON_1_X 335
#define CHARGE_BUTTON_2_X 834
#define CHARGE_BUTTON_3_X 1348
#define CHARGE_BUTTON_Y 458

void HMIHandler::drawDrones(DroneSystem& d) {
	DrawText(TextFormat("Battery: %.1f%%", d.drones[0]->getBatteryLevel()), 80, 210, 40, BLACK);
	DrawText(TextFormat("Battery: %.1f%%", d.drones[1]->getBatteryLevel()), 575, 210, 40, BLACK);
	DrawText(TextFormat("Battery: %.1f%%", d.drones[2]->getBatteryLevel()), 1085, 210, 40, BLACK);

	DrawText(TextFormat("Status: %s", d.drones[0]->getStatus()), 80, 330, 40, BLACK);
	DrawText(TextFormat("Status: %s", d.drones[1]->getStatus()), 575, 330, 40, BLACK);
	DrawText(TextFormat("Status: %s", d.drones[2]->getStatus()), 1085, 330, 40, BLACK);

	DrawText(TextFormat("Damage: %s", d.drones[0]->getDamage()), 80, 400, 40, BLACK);
	DrawText(TextFormat("Damage: %s", d.drones[1]->getDamage()), 575, 400, 40, BLACK);
	DrawText(TextFormat("Damage: %s", d.drones[2]->getDamage()), 1085, 400, 40, BLACK);
}

void HMIHandler::inDroneMenu(Vector2 mousePoint, DroneSystem& d) {
	
	drawDrones(d);

	if (mousePoint.x > RECALL_BUTTON_X && mousePoint.x < RECALL_BUTTON_X + LARGE_BUTTON_WIDTH) {
		if (mousePoint.y > RECALL_BUTTON_Y && mousePoint.y < RECALL_BUTTON_Y + LARGE_BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				d.recallDrones();
			}
		}
	}
	if (mousePoint.x > DEPLOY_BUTTON_X && mousePoint.x < DEPLOY_BUTTON_X + LARGE_BUTTON_WIDTH) {
		if (mousePoint.y > DEPLOY_BUTTON_Y && mousePoint.y < DEPLOY_BUTTON_Y + LARGE_BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				d.deployDrones();
			}
		}
	}
	if (mousePoint.x > REPAIR_BUTTON_1_X && mousePoint.x < REPAIR_BUTTON_1_X + DRONE_SMALL_BUTTON_WIDTH) {
		if (mousePoint.y > REPAIR_BUTTON_Y && mousePoint.y < REPAIR_BUTTON_Y + DRONE_SMALL_BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				d.drones[0]->repairDrone();
			}
		}
	}
	if (mousePoint.x > REPAIR_BUTTON_2_X && mousePoint.x < REPAIR_BUTTON_2_X + DRONE_SMALL_BUTTON_WIDTH) {
		if (mousePoint.y > REPAIR_BUTTON_Y && mousePoint.y < REPAIR_BUTTON_Y + DRONE_SMALL_BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				d.drones[1]->repairDrone();
			}
		}
	}
	if (mousePoint.x > REPAIR_BUTTON_3_X && mousePoint.x < REPAIR_BUTTON_3_X + DRONE_SMALL_BUTTON_WIDTH) {
		if (mousePoint.y > REPAIR_BUTTON_Y && mousePoint.y < REPAIR_BUTTON_Y + DRONE_SMALL_BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				d.drones[2]->repairDrone();
			}
		}
	}
	if (mousePoint.x > CHARGE_BUTTON_1_X && mousePoint.x < CHARGE_BUTTON_1_X + DRONE_SMALL_BUTTON_WIDTH) {
		if (mousePoint.y > CHARGE_BUTTON_Y && mousePoint.y < CHARGE_BUTTON_Y + DRONE_SMALL_BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				d.drones[0]->chargeDrone();
			}
		}
	}
	if (mousePoint.x > CHARGE_BUTTON_2_X && mousePoint.x < CHARGE_BUTTON_2_X + DRONE_SMALL_BUTTON_WIDTH) {
		if (mousePoint.y > CHARGE_BUTTON_Y && mousePoint.y < CHARGE_BUTTON_Y + DRONE_SMALL_BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				d.drones[1]->chargeDrone();
			}
		}
	}
	if (mousePoint.x > CHARGE_BUTTON_3_X && mousePoint.x < CHARGE_BUTTON_3_X + DRONE_SMALL_BUTTON_WIDTH) {
		if (mousePoint.y > CHARGE_BUTTON_Y && mousePoint.y < CHARGE_BUTTON_Y + DRONE_SMALL_BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				d.drones[2]->chargeDrone();
			}
		}
	}
}

void HMIHandler::drawUDG(UndergroundGarden& u) {
	DrawText(TextFormat("Humidity: %.1f%%", u.getHumidity()), 170, 250, 100, BLACK);

	DrawText(TextFormat("Soil pH: %.1f", u.getSoilPH()), 170, 525, 100, BLACK);

	if (u.getSprinklerStatus() == true) {
		DrawText("Sprinklers: On", 170, 800, 100, BLACK);
	}
	else {
		DrawText("Sprinklers: Off", 170, 800, 100, BLACK);
	}

}

#define UDG_UP_ARROWS_X 1000
#define UDG_DOWN_ARROWS_X 1160
#define UDG_HUMIDITY_ARROWS_Y 230
#define UDG_PH_ARROWS_Y 490
#define UDG_ARROW_WIDTH 100
#define UDG_ARROW_HEIGHT 170
#define UDG_CIRCLE_BUTTON_X 1000
#define UDG_CIRCLE_BUTTON_Y 755
#define UDG_CIRCLE_BUTTON_DIAMETER 240


void HMIHandler::inUDGMenu(Vector2 mousePoint, UndergroundGarden& u) {

	drawUDG(u);
	if (mousePoint.x > UDG_UP_ARROWS_X && mousePoint.x < UDG_UP_ARROWS_X + UDG_ARROW_WIDTH) {
		if (mousePoint.y > UDG_HUMIDITY_ARROWS_Y && mousePoint.y < UDG_HUMIDITY_ARROWS_Y + UDG_ARROW_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				u.setHumidity(u.getHumidity() + 1.0f);
			}
		}
	}
	if (mousePoint.x > UDG_DOWN_ARROWS_X && mousePoint.x < UDG_DOWN_ARROWS_X + UDG_ARROW_WIDTH) {
		if (mousePoint.y > UDG_HUMIDITY_ARROWS_Y && mousePoint.y < UDG_HUMIDITY_ARROWS_Y + UDG_ARROW_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				u.setHumidity(u.getHumidity() - 1.0f);
			}
		}
	}
	if (mousePoint.x > UDG_UP_ARROWS_X && mousePoint.x < UDG_UP_ARROWS_X + UDG_ARROW_WIDTH) {
		if (mousePoint.y > UDG_PH_ARROWS_Y && mousePoint.y < UDG_PH_ARROWS_Y + UDG_ARROW_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				u.setSoilPH(u.getSoilPH() + 0.1f);
			}
		}
	}
	if (mousePoint.x > UDG_DOWN_ARROWS_X && mousePoint.x < UDG_DOWN_ARROWS_X + UDG_ARROW_WIDTH) {
		if (mousePoint.y > UDG_PH_ARROWS_Y && mousePoint.y < UDG_PH_ARROWS_Y + UDG_ARROW_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				u.setSoilPH(u.getSoilPH() - 0.1f);
			}
		}
	}
	if (mousePoint.x > UDG_CIRCLE_BUTTON_X && mousePoint.x < UDG_CIRCLE_BUTTON_X + UDG_CIRCLE_BUTTON_DIAMETER) {
		if (mousePoint.y > UDG_CIRCLE_BUTTON_Y && mousePoint.y < UDG_CIRCLE_BUTTON_Y + UDG_CIRCLE_BUTTON_DIAMETER) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				u.setSprinklerStatus(!u.getSprinklerStatus());
			}
		}
	}


}

// Define constants for button and input field positions
#define BUTTON_WIDTH 300
#define BUTTON_HEIGHT 60

// Laser Section Positions
#define LASER_CHARGE_BUTTON_X 100
#define LASER_CHARGE_BUTTON_Y 200
#define LASER_FIRE_BUTTON_X 100
#define LASER_FIRE_BUTTON_Y 300

// Target Input Box Positions
#define TARGET_LAT_BOX_X 100
#define TARGET_LAT_BOX_Y 400
#define TARGET_LON_BOX_X 400
#define TARGET_LON_BOX_Y 400
#define TARGET_BOX_WIDTH 200
#define TARGET_BOX_HEIGHT 50

// Radar Section Positions
#define RADAR_SCAN_BUTTON_X 800
#define RADAR_SCAN_BUTTON_Y 200

void HMIHandler::drawLaserAndRadar(BigLaser& laser, Radar& radar) {
	// Drawing the Laser Section
	DrawText("Laser System", 100, 50, 40, WHITE);  // Title for Laser System
	DrawText(TextFormat("Charge: %d%%", laser.getCharge()), 100, 120, 30, WHITE);  // Display current charge

	// Laser Buttons (Charge and Fire)
	DrawRectangle(LASER_CHARGE_BUTTON_X, LASER_CHARGE_BUTTON_Y, BUTTON_WIDTH, BUTTON_HEIGHT, DARKGRAY);
	DrawText("Charge Laser", LASER_CHARGE_BUTTON_X + 20, LASER_CHARGE_BUTTON_Y + 30, 30, WHITE);

	DrawRectangle(LASER_FIRE_BUTTON_X, LASER_FIRE_BUTTON_Y, BUTTON_WIDTH, BUTTON_HEIGHT, DARKGRAY);
	DrawText("Fire Laser", LASER_FIRE_BUTTON_X + 20, LASER_FIRE_BUTTON_Y + 30, 30, WHITE);

	// Latitude and Longitude Input Fields
	DrawText("Target Latitude:", TARGET_LAT_BOX_X, TARGET_LAT_BOX_Y - 40, 20, WHITE);
	DrawText("Target Longitude:", TARGET_LON_BOX_X, TARGET_LON_BOX_Y - 40, 20, WHITE);

	// Latitude and Longitude Textboxes
	Rectangle latBox = { TARGET_LAT_BOX_X, TARGET_LAT_BOX_Y, TARGET_BOX_WIDTH, TARGET_BOX_HEIGHT };
	Rectangle lonBox = { TARGET_LON_BOX_X, TARGET_LON_BOX_Y, TARGET_BOX_WIDTH, TARGET_BOX_HEIGHT };

	DrawRectangleRec(latBox, isLatBoxActive ? LIGHTGRAY : DARKGRAY);
	DrawRectangleRec(lonBox, isLonBoxActive ? LIGHTGRAY : DARKGRAY);

	// Display text input
	DrawText(latitudeInput, TARGET_LAT_BOX_X + 10, TARGET_LAT_BOX_Y + 10, 20, BLACK);
	DrawText(longitudeInput, TARGET_LON_BOX_X + 10, TARGET_LON_BOX_Y + 10, 20, BLACK);

	// Drawing the Radar Section (below the laser)
	DrawText("Radar System", 800, 50, 40, WHITE);  // Title for Radar System
	DrawText(TextFormat("Entities Detected: %d", radar.getDetectedEntities()), 800, 120, 30, WHITE);  // Display detected entities count

	// Radar Button (Scan)
	DrawRectangle(RADAR_SCAN_BUTTON_X, RADAR_SCAN_BUTTON_Y, BUTTON_WIDTH, BUTTON_HEIGHT, DARKGRAY);
	DrawText("Scan Radar", RADAR_SCAN_BUTTON_X + 20, RADAR_SCAN_BUTTON_Y + 30, 30, WHITE);
}

void HMIHandler::handleLaserTargetInput(BigLaser& laser) {
	// Define the rectangles for the text input boxes
	Rectangle latBox = { TARGET_LAT_BOX_X, TARGET_LAT_BOX_Y, TARGET_BOX_WIDTH, TARGET_BOX_HEIGHT };
	Rectangle lonBox = { TARGET_LON_BOX_X, TARGET_LON_BOX_Y, TARGET_BOX_WIDTH, TARGET_BOX_HEIGHT };

	// Detect mouse click to activate text box for latitude and longitude
	if (CheckCollisionPointRec(GetMousePosition(), latBox)) {
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			isLatBoxActive = true;
			isLonBoxActive = false;
		}
	}
	if (CheckCollisionPointRec(GetMousePosition(), lonBox)) {
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			isLonBoxActive = true;
			isLatBoxActive = false;
		}
	}

	// Handle text input for latitude and longitude
	if (isLatBoxActive) {
		int key = GetCharPressed();
		while (key > 0) {
			if (key >= 32 && key <= 125 && strlen(latitudeInput) < sizeof(latitudeInput) - 1) {
				int len = strlen(latitudeInput);
				latitudeInput[len] = (char)key;
				latitudeInput[len + 1] = '\0';
			}
			key = GetCharPressed();
		}

		if (IsKeyPressed(KEY_BACKSPACE) && strlen(latitudeInput) > 0) {
			latitudeInput[strlen(latitudeInput) - 1] = '\0';
		}
	}

	if (isLonBoxActive) {
		int key = GetCharPressed();
		while (key > 0) {
			if (key >= 32 && key <= 125 && strlen(longitudeInput) < sizeof(longitudeInput) - 1) {
				int len = strlen(longitudeInput);
				longitudeInput[len] = (char)key;
				longitudeInput[len + 1] = '\0';
			}
			key = GetCharPressed();
		}

		if (IsKeyPressed(KEY_BACKSPACE) && strlen(longitudeInput) > 0) {
			longitudeInput[strlen(longitudeInput) - 1] = '\0';
		}
	}

	// Update laser target when Enter is pressed
	if (IsKeyPressed(KEY_ENTER)) {
		float latitude = atof(latitudeInput);
		float longitude = atof(longitudeInput);
		laser.setTarget(latitude, longitude);
		std::cout << "Target set to Latitude: " << latitude << ", Longitude: " << longitude << "\n";
	}
}

void HMIHandler::inLaserAndRadarMenu(Vector2 mousePoint, BigLaser& laser, Radar& radar) {
	drawLaserAndRadar(laser, radar);

	// Handle laser target input
	handleLaserTargetInput(laser);

	// Laser control buttons (Charge and Fire)
	if (mousePoint.x > LASER_CHARGE_BUTTON_X && mousePoint.x < LASER_CHARGE_BUTTON_X + BUTTON_WIDTH &&
		mousePoint.y > LASER_CHARGE_BUTTON_Y && mousePoint.y < LASER_CHARGE_BUTTON_Y + BUTTON_HEIGHT) {
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
			laser.charge(20);  // Charge in increments of 20%
		}
	}

	if (mousePoint.x > LASER_FIRE_BUTTON_X && mousePoint.x < LASER_FIRE_BUTTON_X + BUTTON_WIDTH &&
		mousePoint.y > LASER_FIRE_BUTTON_Y && mousePoint.y < LASER_FIRE_BUTTON_Y + BUTTON_HEIGHT) {
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
			laser.fireLaser();
		}
	}

	// Radar control button (Scan)
	if (mousePoint.x > RADAR_SCAN_BUTTON_X && mousePoint.x < RADAR_SCAN_BUTTON_X + BUTTON_WIDTH &&
		mousePoint.y > RADAR_SCAN_BUTTON_Y && mousePoint.y < RADAR_SCAN_BUTTON_Y + BUTTON_HEIGHT) {
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
			radar.scanForEntities();
		}
	}
}