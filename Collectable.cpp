#include "Collectable.h"
#include "paddle.h"

Collectable::Collectable(point uprleft, int w, int h, game* r_pGame) :
	collidable(uprleft, width, height, pGame) {}

void Collectable::collisionAction()
{
	move_collectable();
}

void Collectable::move_collectable()
{
}


void Collectable::applyEffect()
{

}