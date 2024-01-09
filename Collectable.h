#pragma once
#include "collidable.h"

class Collectable : public collidable
{

public:
	Collectable(point uprleft, int w, int h, game* r_pGame);
	void collisionAction() override;
	void move_collectable();
	void applyEffect();
};







