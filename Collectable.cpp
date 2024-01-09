#include "collectable.h"
#include "paddle.h"

collectable::collectable(point uprleft, int w, int h, game* r_pGame) :
	collidable(uprleft, width, height, pGame) {}

void collectable::collisionAction()
{
	applyEffect();
}

collectable* collectable::getCollectable()
{
	return this;
}

void collectable::applyEffect()
{

}



//default constructor for collictable objects

