#pragma once
#include "collectable.h"
#include "game.h"




class power : public collectable
{
public:
	power(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void power_move();
	void WindGlid();
	void ReverseDirection();
	void QuickSand();
	void WidePaddle();
	void NarrowPaddle();
};



//class WindGlide : public power
//{
//	WindGlide(point r_uprleft, int r_width, int r_height, game* r_pGame);
//	void collisionAction();
//	void power_move()override;
//};
//
//class ReverseDirection : public power
//{
//	ReverseDirection(point r_uprleft, int r_width, int r_height, game* r_pGame);
//	void collisionAction();
//	void power_move()override;
//};


