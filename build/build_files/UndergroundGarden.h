#pragma once

class UndergroundGarden {
	bool sprinklerStatus;
	float humidityLevel;
	float soilPHLevel;
public:
	UndergroundGarden();
	~UndergroundGarden();
	void setSprinklerStatus(bool input);
	void setHumidity(float input);
	void setSoilPH(float input);
	bool getSprinklerStatus();
	float getHumidity();
	float getSoilPH();
	bool readDataFromFile(char* filepath);
	void writeDataToFile(char* filepath);
};