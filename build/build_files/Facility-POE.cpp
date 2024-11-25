#include "Facility-POE.h"

POE::POE()
{
	setPOEID(0);
	setDamageLevel(0);
	setIsBreached(false);
	setIsDamaged(false);
	setIsOpen(true);
	setPosition(0, 0, 0, 0);
}

void POE::setPosition(int X1, int Y1, int X2, int Y2)
{
	this->POEX1 = X1;
	this->POEX2 = X2;
	this->POEY1 = Y1;
	this->POEY2 = Y2;
}

int POE::getX1()
{
	return POEX1;
}
int POE::getX2()
{
	return POEX2;
}
int POE::getY1()
{
	return POEY1;
}
int POE::getY2()
{
	return POEY2;
}

int POE::getPOEID()
{
	return POEID;
}

void POE::setPOEID(int POEID)
{
	this->POEID = POEID;
}

int POE::getDamageLevel()
{
	return damageLvl;
}

void POE::setDamageLevel(int damageLvl)
{
	this->damageLvl = damageLvl;
}

bool POE::getIsBreached()
{
	return isBreached;
}

void POE::setIsBreached(bool isBreached)
{
	this->isBreached = isBreached;
}
bool POE::getIsDamaged()
{
	return isDamaged;
}

void POE::setIsDamaged(bool isDamaged)
{
	this->isDamaged = isDamaged;
}
bool POE::getIsOpen()
{
	return isOpen;
}

void POE::setIsOpen(bool isOpen)
{
	this->isOpen = isOpen;
}
