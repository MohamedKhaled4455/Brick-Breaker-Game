#pragma once
#include "collidable.h"



class ball : public collidable
{
private:
	int ballRadius = 10;
	int vecx=2, vecy=2; 
public:
	ball(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void ballMovement();
	void collisionAction() override;
	void balldraw();
	void emptyball();

};