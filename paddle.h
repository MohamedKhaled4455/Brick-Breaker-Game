#pragma once
#include "collidable.h"



// This class should contain all paddle-related featues like movement, shape, and collisions
class paddle : public collidable
{
private:

public:
	paddle(point uprleft, int w, int h, game* r_pGame);


	void draw(window* win);
	void collisionAction() override;
	void movement(window* win);
	point getuprlft() const;
	int getwidth() const;


}; 