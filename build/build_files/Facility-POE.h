#pragma once

#include <stdio.h>
//POE short for point of entry
class POE {
	bool isBreached, isDamaged, isOpen;
	int damageLvl, POEID, POEX1, POEX2, POEY1, POEY2;

public:
	POE();
	void setPosition(int X1, int Y1, int X2, int Y2);
	int getX1();
	int getX2();
	int getY1();
	int getY2();

	int getDamageLevel();
	void setDamageLevel(int damageLvl);

	bool getIsBreached();
	void setIsBreached(bool isBreached);

	bool getIsDamaged();
	void setIsDamaged(bool isDamaged);

	bool getIsOpen();
	void setIsOpen(bool isOpen);


};