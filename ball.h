#pragma once
#include "collidable.h"


class ball : public collidable
{
public:
	ball(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void ballMovement(window* win);
	void collisionAction() override;
	void balldraw(window* win);
};