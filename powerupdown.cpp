#include "powerupdown.h"
#include "paddle.h"

power::power(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	collectable(r_uprleft, r_width, r_height, r_pGame)
{
}
void power::power_move()
{
}
//powerups

void power::WindGlid()
{
	paddle* pad = pGame->getpaddle();
	int oldspeed = pad->getspeed();
	pad->setspeed(25);
	// apply duration
	pad->setspeed(oldspeed);
}
// powerdowns
void power::ReverseDirection()
{
	paddle* pad = pGame->getpaddle();
	pad->setspeed(-1 * pad->getspeed());
	int oldspeed = pad->getspeed();
	// apply duration
	pad->setspeed(oldspeed);
}

void power::QuickSand()
{
	paddle* pad = pGame->getpaddle();
	int oldspeed = pad->getspeed();
	pad->setspeed(10);
	// apply duration
	pad->setspeed(oldspeed);
}

void power::WidePaddle()
{
	paddle* pad = pGame->getpaddle();
	int oldX = pad->getX();
	int oldW = pad->getWidth();
	int incValue = 15;
	pad->setWidth(oldW + incValue);
	pad->setX(oldX + incValue);
}

void power::NarrowPaddle()
{
	paddle* pad = pGame->getpaddle();
	int oldX = pad->getX();
	int oldW = pad->getWidth();
	int decValue = 15;
	pad->setWidth(oldW - decValue);
	pad->setX(oldX - decValue);
}

