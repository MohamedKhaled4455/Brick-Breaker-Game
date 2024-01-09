#pragma once
#include "collidable.h"



// This class should contain all paddle-related featues like movement, shape, and collisions
class paddle : public collidable
{
private:
	bool isPause = false;

public:
	paddle(point uprleft, int w, int h, game* r_pGame);


	void draw();
	void collisionAction() override;
	void movement();
	point getuprlft() const;
	int getwidth() const;
	void paddlepause();
	bool getisPause(); const
	void paddlecontinue();


}; 
