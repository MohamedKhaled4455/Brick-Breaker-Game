#pragma once
#include "collidable.h"



class ball : public collidable
{
private:
	point collision;// point of collision between an object and ball
	int ballRadius = 10;
	int vecx = 2, vecy = 2;
	int xreset; int yreset;
public:
	ball(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void ballMovement();
	void ballMovementVertically();
	void collisionAction() override;
	void setcollisionpoint(point c);
	//void BallPaddleReflection();
	//void BallBrickReflection(int i, int j);
	void BallWallReflection();
	void balldraw();
	void emptyball();
	// getters & setters 
	int getYPosition();
	int getXPosition();
	int setresetposition();
	int getraduis();
};

