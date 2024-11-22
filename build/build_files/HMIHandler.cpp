#include "HMIHandler.h"
#include <iostream>
#include "raylib.h"
#define BUTTON_WIDTH 500
#define BUTTON_HEIGHT 100
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
	if (mousePoint.x > DRONE_SYSTEM_BUTTON_X && mousePoint.x < DRONE_SYSTEM_BUTTON_X + BUTTON_WIDTH) {
		if (mousePoint.y > DRONE_SYSTEM_BUTTON_Y && mousePoint.y < DRONE_SYSTEM_BUTTON_Y + BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				std::cout << "clicked drone system button" << std::endl;				
				return 1;
			}
		}
	}
	if (mousePoint.x > GARDEN_BUTTON_X && mousePoint.x < GARDEN_BUTTON_X + BUTTON_WIDTH) {
		if (mousePoint.y > GARDEN_BUTTON_Y && mousePoint.y < GARDEN_BUTTON_Y + BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				std::cout << "clicked garden system button" << std::endl;
				return 2;
			}
		}
	}
	if (mousePoint.x > AQUARIUM_BUTTON_X && mousePoint.x < AQUARIUM_BUTTON_X + BUTTON_WIDTH) {
		if (mousePoint.y > AQUARIUM_BUTTON_Y && mousePoint.y < AQUARIUM_BUTTON_Y + BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				std::cout << "clicked aquarium system button" << std::endl;
				return 3;
			}
		}
	}
	if (mousePoint.x > FACILITY_BUTTON_X && mousePoint.x < FACILITY_BUTTON_X + BUTTON_WIDTH) {
		if (mousePoint.y > FACILITY_BUTTON_Y && mousePoint.y < FACILITY_BUTTON_Y + BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				std::cout << "clicked facility system button" << std::endl;
				return 4;
			}
		}
	}
	if (mousePoint.x > LASER_BUTTON_X && mousePoint.x < LASER_BUTTON_X + BUTTON_WIDTH) {
		if (mousePoint.y > LASER_BUTTON_Y && mousePoint.y < LASER_BUTTON_Y + BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				std::cout << "clicked laser system button" << std::endl;
				return 5;
			}
		}
	}
	if (mousePoint.x > MONSTER_BUTTON_X && mousePoint.x < MONSTER_BUTTON_X + BUTTON_WIDTH) {
		if (mousePoint.y > MONSTER_BUTTON_Y && mousePoint.y < MONSTER_BUTTON_Y + BUTTON_HEIGHT) {
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
#define REPAIR_BUTTON_2_X 459
#define REPAIR_BUTTON_3_X 1084
#define REPAIR_BUTTON_Y 458
#define DRONE_SMALL_BUTTON_WIDTH 200
#define DRONE_SMALL_BUTTON_HEIGHT 120

#define CHARGE_BUTTON_1_X 335
#define CHARGE_BUTTON_2_X 834
#define CHARGE_BUTTON_3_X 1348
#define CHARGE_BUTTON_Y 458

void HMIHandler::drawDrones(DroneSystem &d) {
	DrawText(TextFormat("Battery: %.1f%%", d.drones[0]->getBatteryLevel()), 80, 210, 40, BLACK);
	DrawText(TextFormat("Battery: %.1f%%", d.drones[1]->getBatteryLevel()), 575, 210, 40, BLACK);
	DrawText(TextFormat("Battery: %.1f%%", d.drones[2]->getBatteryLevel()), 1085, 210, 40, BLACK);

	DrawText(TextFormat("Status: %s", d.drones[2]->getStatus()), 80, 330, 40, BLACK);
	DrawText(TextFormat("Status: %s", d.drones[2]->getStatus()), 575, 330, 40, BLACK);
	DrawText(TextFormat("Status: %s", d.drones[2]->getStatus()), 1085, 330, 40, BLACK);

	DrawText(TextFormat("Damage: %s", d.drones[2]->getDamage()), 80, 400, 40, BLACK);
	DrawText(TextFormat("Damage: %s", d.drones[2]->getDamage()), 575, 400, 40, BLACK);
	DrawText(TextFormat("Damage: %s", d.drones[2]->getDamage()), 1085, 400, 40, BLACK);
}

void HMIHandler::inDroneMenu(Vector2 mousePoint, DroneSystem &d) {
	
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


void HMIHandler::inUDGMenu(Vector2 mousePoint, UndergroundGarden &u) {

	drawUDG(u);
	std::cout << "mouse x = " << mousePoint.x << std::endl;
	std::cout << "mouse y = " << mousePoint.y << std::endl;
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