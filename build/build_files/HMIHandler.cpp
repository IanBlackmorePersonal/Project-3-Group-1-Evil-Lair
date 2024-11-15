#include "HMIHandler.h"
#include <iostream>
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

bool HMIHandler::menuButtonClicked(Vector2 mousePoint) {
	// these ifs all determine if the mouse is within a button's boundaries and if the mouse is clicked
	if (mousePoint.x > DRONE_SYSTEM_BUTTON_X && mousePoint.x < DRONE_SYSTEM_BUTTON_X + BUTTON_WIDTH) {
		if (mousePoint.y > DRONE_SYSTEM_BUTTON_Y && mousePoint.y < DRONE_SYSTEM_BUTTON_Y + BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				std::cout << "clicked drone system button" << std::endl;
				return true;
			}
		}
	}
	if (mousePoint.x > GARDEN_BUTTON_X && mousePoint.x < GARDEN_BUTTON_X + BUTTON_WIDTH) {
		if (mousePoint.y > GARDEN_BUTTON_Y && mousePoint.y < GARDEN_BUTTON_Y + BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				std::cout << "clicked garden system button" << std::endl;
				return true;
			}
		}
	}
	if (mousePoint.x > AQUARIUM_BUTTON_X && mousePoint.x < AQUARIUM_BUTTON_X + BUTTON_WIDTH) {
		if (mousePoint.y > AQUARIUM_BUTTON_Y && mousePoint.y < AQUARIUM_BUTTON_Y + BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				std::cout << "clicked aquarium system button" << std::endl;
				return true;
			}
		}
	}
	if (mousePoint.x > FACILITY_BUTTON_X && mousePoint.x < FACILITY_BUTTON_X + BUTTON_WIDTH) {
		if (mousePoint.y > FACILITY_BUTTON_Y && mousePoint.y < FACILITY_BUTTON_Y + BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				std::cout << "clicked facility system button" << std::endl;
				return true;
			}
		}
	}
	if (mousePoint.x > LASER_BUTTON_X && mousePoint.x < LASER_BUTTON_X + BUTTON_WIDTH) {
		if (mousePoint.y > LASER_BUTTON_Y && mousePoint.y < LASER_BUTTON_Y + BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				std::cout << "clicked laser system button" << std::endl;
				return true;
			}
		}
	}
	if (mousePoint.x > MONSTER_BUTTON_X && mousePoint.x < MONSTER_BUTTON_X + BUTTON_WIDTH) {
		if (mousePoint.y > MONSTER_BUTTON_Y && mousePoint.y < MONSTER_BUTTON_Y + BUTTON_HEIGHT) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
				std::cout << "clicked monster system button" << std::endl;
				return true;
			}
		}
	}
	return false;
}
