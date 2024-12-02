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



// Define positions and sizes based on the 1600x1000 application window
#define RED_BUTTON_X 140
#define RED_BUTTON_Y 756
#define RED_BUTTON_RADIUS 150

#define CHARGE_BUTTON_X 450
#define CHARGE_BUTTON_Y 850
#define CHARGE_BUTTON_WIDTH 120
#define CHARGE_BUTTON_HEIGHT 40

#define SCAN_BUTTON_X 1138
#define SCAN_BUTTON_Y 680
#define SCAN_BUTTON_WIDTH 150
#define SCAN_BUTTON_HEIGHT 40

#define SQUARE_INDICATOR_X 284
#define SQUARE_INDICATOR_Y 737
#define SQUARE_INDICATOR_SIZE 40

#define STATUS_RECT_X 50
#define STATUS_RECT_Y 45
#define STATUS_RECT_WIDTH 800
#define STATUS_RECT_HEIGHT 180

#define ENTITIES_RECT_X 84
#define ENTITIES_RECT_Y 360
#define ENTITIES_RECT_WIDTH 720
#define ENTITIES_RECT_HEIGHT 170

#define RADAR_X 1214
#define RADAR_Y 360
#define RADAR_RADIUS 335

// X Input Box (upper black box)
#define INPUT_BOX_X_X 960
#define INPUT_BOX_X_Y 750
#define INPUT_BOX_X_WIDTH 517
#define INPUT_BOX_X_HEIGHT 80

// Y Input Box (lower black box)
#define INPUT_BOX_Y_X 960
#define INPUT_BOX_Y_Y 855
#define INPUT_BOX_Y_WIDTH 517
#define INPUT_BOX_Y_HEIGHT 80

#define WHITE_BAR_X 683
#define WHITE_BAR_Y 630
#define WHITE_BAR_WIDTH 100
#define WHITE_BAR_HEIGHT 341

static bool showBoom = false; // Flag to determine if "BOOM" should be displayed
static int boomTimer = 0;     // Timer for how long "BOOM" is displayed (in frames)

void HMIHandler::drawLaserAndRadar(BigLaser& laser, Radar& radar) {
	// Fire button: detect if clicked
	if (CheckCollisionPointCircle(GetMousePosition(), { RED_BUTTON_X + RED_BUTTON_RADIUS, RED_BUTTON_Y + RED_BUTTON_RADIUS }, RED_BUTTON_RADIUS)) {
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
			laser.fireLaser();
			radar.resetEntities();  // Set entities to 0
			showBoom = true;        // Show "BOOM" message
			boomTimer = 120;        // Display "BOOM" for 2 seconds (assuming 60 FPS)
		}
	}

	// Charge button: detect if clicked
	if (CheckCollisionPointRec(GetMousePosition(), { CHARGE_BUTTON_X, CHARGE_BUTTON_Y, CHARGE_BUTTON_WIDTH, CHARGE_BUTTON_HEIGHT })) {
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
			laser.charge(20); // Increment charge by 20%
		}
	}

	// Scan button: detect if clicked
	if (CheckCollisionPointRec(GetMousePosition(), { SCAN_BUTTON_X, SCAN_BUTTON_Y, SCAN_BUTTON_WIDTH, SCAN_BUTTON_HEIGHT })) {
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
			radar.scanForEntities(); // Perform a radar scan
		}
	}

	// Draw charge button
	DrawRectangle(CHARGE_BUTTON_X, CHARGE_BUTTON_Y, CHARGE_BUTTON_WIDTH, CHARGE_BUTTON_HEIGHT, GRAY);
	DrawText("CHARGE", CHARGE_BUTTON_X + 20, CHARGE_BUTTON_Y + 10, 20, BLACK);

	// Draw scan button
	DrawRectangle(SCAN_BUTTON_X, SCAN_BUTTON_Y, SCAN_BUTTON_WIDTH, SCAN_BUTTON_HEIGHT, GRAY);
	DrawText("SCAN", SCAN_BUTTON_X + 40, SCAN_BUTTON_Y + 10, 20, BLACK);

	// Square indicator (red/green based on laser charge)
	Color squareColor = laser.getCharge() == 100 ? GREEN : RED;
	DrawRectangle(SQUARE_INDICATOR_X, SQUARE_INDICATOR_Y, SQUARE_INDICATOR_SIZE, SQUARE_INDICATOR_SIZE, squareColor);

	// Top green rectangle: laser status
	if (laser.isCooling()) {
		DrawText("LASER IS IN COOLDOWN", STATUS_RECT_X + 50, STATUS_RECT_Y + 70, 40, WHITE);
	}
	else if (laser.getCharge() == 100) {
		DrawText("READY TO FIRE", STATUS_RECT_X + 180, STATUS_RECT_Y + 70, 40, WHITE);
	}
	else {
		DrawText(TextFormat("LASER CHARGED: %d%%", laser.getCharge()), STATUS_RECT_X + 180, STATUS_RECT_Y + 70, 40, WHITE);
	}

	// Middle green rectangle: entities detected
	DrawText(TextFormat("ENTITIES DETECTED: %d", radar.getDetectedEntities()), ENTITIES_RECT_X + 120, ENTITIES_RECT_Y + 60, 40, WHITE);

	// Radar: draw dots for detected entities
	for (int i = 0; i < radar.getDetectedEntities(); i++) {
		float angle = (i * 360.0f) / radar.getDetectedEntities();
		float radian = DEG2RAD * angle;
		float x = RADAR_X + cos(radian) * (RADAR_RADIUS - 20);
		float y = RADAR_Y + sin(radian) * (RADAR_RADIUS - 20);
		DrawCircle(x, y, 5, RED); // Dots for entities
	}

	// Input boxes: X and Y coordinates (no colored background)
	DrawText(latitudeInput, INPUT_BOX_X_X + 10, INPUT_BOX_X_Y + 25, 40, WHITE); // X coordinate
	DrawText(longitudeInput, INPUT_BOX_Y_X + 10, INPUT_BOX_Y_Y + 25, 40, WHITE); // Y coordinate

	// White bar: laser charge level
	float filledHeight = WHITE_BAR_HEIGHT * (laser.getCharge() / 100.0f);
	DrawRectangle(WHITE_BAR_X, WHITE_BAR_Y + WHITE_BAR_HEIGHT - filledHeight, WHITE_BAR_WIDTH, filledHeight, GREEN);
	DrawRectangleLines(WHITE_BAR_X, WHITE_BAR_Y, WHITE_BAR_WIDTH, WHITE_BAR_HEIGHT, BLACK); // Outline

	// Display "BOOM" message if the red button was clicked
	if (showBoom) {
		DrawText("BOOM!", 600, 400, 120, RED); // "BOOM" centered on screen
		boomTimer--; // Decrease the timer
		if (boomTimer <= 0) {
			showBoom = false; // Stop showing "BOOM" after timer ends
		}
	}
}

void HMIHandler::handleLaserTargetInput(BigLaser& laser) {
	// Detect if the user clicks on the X or Y input boxes
	if (CheckCollisionPointRec(GetMousePosition(), { INPUT_BOX_X_X, INPUT_BOX_X_Y, INPUT_BOX_X_WIDTH, INPUT_BOX_X_HEIGHT })) {
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			isLatBoxActive = true;
			isLonBoxActive = false;
		}
	}
	else if (CheckCollisionPointRec(GetMousePosition(), { INPUT_BOX_Y_X, INPUT_BOX_Y_Y, INPUT_BOX_Y_WIDTH, INPUT_BOX_Y_HEIGHT })) {
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			isLatBoxActive = false;
			isLonBoxActive = true;
		}
	}

	// Handle input for X coordinate
	if (isLatBoxActive) {
		int key = GetCharPressed();
		while (key > 0) {
			if (key >= 32 && key <= 125 && strlen(latitudeInput) < sizeof(latitudeInput) - 1) {
				latitudeInput[strlen(latitudeInput)] = key;
			}
			key = GetCharPressed();
		}
		if (IsKeyPressed(KEY_BACKSPACE) && strlen(latitudeInput) > 0) {
			latitudeInput[strlen(latitudeInput) - 1] = '\0';
		}
	}

	// Handle input for Y coordinate
	if (isLonBoxActive) {
		int key = GetCharPressed();
		while (key > 0) {
			if (key >= 32 && key <= 125 && strlen(longitudeInput) < sizeof(longitudeInput) - 1) {
				longitudeInput[strlen(longitudeInput)] = key;
			}
			key = GetCharPressed();
		}
		if (IsKeyPressed(KEY_BACKSPACE) && strlen(longitudeInput) > 0) {
			longitudeInput[strlen(longitudeInput) - 1] = '\0';
		}
	}

	// Apply the coordinates to the laser when Enter is pressed
	if (IsKeyPressed(KEY_ENTER)) {
		float latitude = atof(latitudeInput);
		float longitude = atof(longitudeInput);
		laser.setTarget(latitude, longitude);
		std::cout << "Target set to Latitude: " << latitude << ", Longitude: " << longitude << "\n";
	}
}

void HMIHandler::inLaserAndRadarMenu(Vector2 mousePoint, BigLaser& laser, Radar& radar) {
	drawLaserAndRadar(laser, radar);
	handleLaserTargetInput(laser);
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


