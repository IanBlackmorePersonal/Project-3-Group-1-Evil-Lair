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

#define HUNGER_BAR_X 130
#define HUNGER_BAR_Y 291
#define VITAL_BAR_WIDTH 703
#define VITAL_BAR_HEIGHT 103
#define ANGER_BAR_X 134
#define ANGER_BAR_Y 523
#define FEED_BTN_X 136
#define FEED_BTN_Y 700
#define SEDATE_BTN_X 575
#define ROUND_BTN_WIDTH 250
#define RELEASE_BTN_X 1037
#define RELEASE_BTN_Y 270
#define RELEASE_BTN_WIDTH 389



void HMIHandler::drawMonsterContainmentStats(MonsterContainmentUnit& m) {
	DrawRectangle(HUNGER_BAR_X, HUNGER_BAR_Y, (m.getHungerLevel() * 10 * 0.703), VITAL_BAR_HEIGHT, ORANGE);
	DrawText(TextFormat("%.1f%%", m.getHungerLevel()), 410, 330, 40, BLACK);
	
	DrawRectangle(ANGER_BAR_X, ANGER_BAR_Y, (m.getAngerLevel() * 10 * 0.703), VITAL_BAR_HEIGHT, RED);
	DrawText(TextFormat("%.1f%%", m.getAngerLevel()), 410, 560, 40, BLACK);
	
	if (m.getContainmentStatus() == true) {
		DrawText(TextFormat("Monster Containment status:"), 870, 130, 35, BLACK);
		DrawText(TextFormat("Contained"), 1390, 130, 35, GREEN);
	}
	if (m.getContainmentStatus() == false) {
		DrawText(TextFormat("Monster Containment status:"), 870, 130, 35, BLACK);
		DrawText(TextFormat("Breached"), 1390, 130, 35, RED);
		DrawText(TextFormat("'WARNING'"), 1090, 730, 60, RED);
		DrawText(TextFormat("Monster Is Out Of Containment!"), 950, 820, 35, BLACK);
		
	}
	
}

// Facility Button X Y s
#define FORCEFIELD_BUT_X 610
#define FORCEFIELD_BUT_Y 800
#define FORCEFIELDBUT_WID 598
#define FORCEFIELDBUT_HEI 142
#define FULL_LOCKDOWN_BUT_X 42
#define FULL_LOCKDOWN_BUT_Y 756
#define FULL_LOCKDOWN_BUT_WH 226 //square.

void HMIHandler::drawFacilityMap(Facility& f)
{
	//coords. ugh.
}

int HMIHandler::inFacilityMenu(Vector2 mousePoint, Facility& facility, bool& inLockdown)
{
	facility.checkSensors();
	facility.checkPOEs();

	if (mousePoint.x > FULL_LOCKDOWN_BUT_X && mousePoint.x < (FULL_LOCKDOWN_BUT_X + FULL_LOCKDOWN_BUT_WH)) {
		if (mousePoint.y > FULL_LOCKDOWN_BUT_Y && mousePoint.y < (FULL_LOCKDOWN_BUT_Y + FULL_LOCKDOWN_BUT_WH)) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && inLockdown == false) {
				facility.engageLockdown();
				printf("engaging lockdown\n");
				inLockdown = true;
			}
			else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && inLockdown == true) {
				facility.disableLockdown();
				printf("disabling lockdown\n");
				inLockdown = false;
			}
		
		}
	}
	if (mousePoint.x > FORCEFIELD_BUT_X && mousePoint.x < (FORCEFIELDBUT_WID + FORCEFIELD_BUT_X)) {
		if (mousePoint.y > FORCEFIELD_BUT_Y && mousePoint.y < (FORCEFIELD_BUT_Y + FORCEFIELDBUT_HEI)) {
			if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
				return 1;
		}
	}
	return 0;
}



void HMIHandler::inMonsterContainmentUnitMenu(Vector2 mousePoint, MonsterContainmentUnit& m) {
	

	drawMonsterContainmentStats(m);
	
	
	if (m.getContainmentStatus() == true) {
		m.updateAngerOverTime();
		m.updateHungerOverTime();
	}

	if (mousePoint.x > FEED_BTN_X && mousePoint.x < FEED_BTN_X + ROUND_BTN_WIDTH) {
		if (mousePoint.y > FEED_BTN_Y && mousePoint.y < FEED_BTN_Y + ROUND_BTN_WIDTH) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				m.feedMonster();
			}
		}
	}

	if (mousePoint.x > SEDATE_BTN_X && mousePoint.x < SEDATE_BTN_X + ROUND_BTN_WIDTH) {
		if (mousePoint.y > FEED_BTN_Y && mousePoint.y < FEED_BTN_Y + ROUND_BTN_WIDTH) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				m.sedateMonster();
			}
		}
	}

	if (mousePoint.x > RELEASE_BTN_X && mousePoint.x < RELEASE_BTN_X + RELEASE_BTN_WIDTH) {
		if (mousePoint.y > RELEASE_BTN_Y && mousePoint.y < RELEASE_BTN_Y + RELEASE_BTN_WIDTH) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				m.releaseMonster();
			}
		}
	}



}

#define FF_BAR_X 1095
#define FF_BAR_Y 122
#define FF_BAR_WIDTH 293
#define FF_BAR_HEIGHT 725


int timer = 1;

void HMIHandler::drawForceFieldStats(ForceField& f) {
	DrawRectangle(
		FF_BAR_X,
		FF_BAR_Y + FF_BAR_HEIGHT - (f.getChargeLevel() / 100.0f * FF_BAR_HEIGHT),
		FF_BAR_WIDTH,
		f.getChargeLevel() / 100.0f * FF_BAR_HEIGHT,
		SKYBLUE
	);
	DrawText(TextFormat("%.1f%%", f.getChargeLevel()), 1185, 450, 40, BLACK);

	DrawText(TextFormat("Force Field status:"), 150, 163, 35, BLACK);
	if (f.isForceFieldActive() == true) {
		DrawText(TextFormat("Active"), 500, 163, 35, SKYBLUE);
	}
	if (f.isForceFieldActive() == false) {
		DrawText(TextFormat("Compromised"), 500, 163, 35, RED);
	}

	DrawText(TextFormat("Time Until Fully Charged:", f.timeToFullCharge()), 150, 250, 35, BLACK);
	DrawText(TextFormat("%.1f%", f.timeToFullCharge()), 600, 250, 35, SKYBLUE);
	DrawText(TextFormat("seconds"), 700, 250, 35, BLACK);

	if (f.isForceFieldActive() == false) {
		DrawText(TextFormat("'WARNING'"), 320, 400, 100, RED);
		DrawText(TextFormat("Force Field Has Been"), 255, 600, 60, BLACK);
		DrawText(TextFormat("BREACHED"), 310, 750, 100, RED);
	}

	
}
	

void HMIHandler::inForceFieldMenu(Vector2 mousePoint, ForceField& f) {

	f.chargeForceField();
	if (f.isForceFieldActive() == false) {
		timer = timer + 1;
		if (timer == 3600) {
			f.setForceFieldChargingStatus(true);
			f.setForceFieldStatus(true);
		}
	}
	drawForceFieldStats(f);
	
	

}


