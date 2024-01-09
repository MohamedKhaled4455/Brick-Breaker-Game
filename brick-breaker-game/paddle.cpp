#include "paddle.h"
#include "CMUgraphicsLib\auxil.h"
#include "game.h"

paddle::paddle(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	collidable(r_uprleft, r_width, r_height, r_pGame) {
	speed = 15;
}


void paddle::draw()
{
	window* pWind = pGame->getWind();
	pWind->SetBrush(CORNFLOWERBLUE);
	pWind->SetPen(BLACK);
	pWind->DrawRectangle(uprLft.x, uprLft.y, (uprLft.x + width), (uprLft.y + height), FILLED);
}

void paddle::collisionAction()
{
}

void paddle::movement()
{// paddle movement function that responsible for both the draw and the movement of the paddle
	window* pWind = pGame->getWind();
	//paddle::draw();
	do {
		char Key;
		keytype ktype;
		paddle::draw();
		ktype = pWind->WaitKeyPress(Key);
		if (Key == 4 && uprLft.x != 0)
		{
			uprLft.x += -1*speed;
		}
		if (Key == 6 && uprLft.x < (pWind->GetWidth()- width))
		{
			uprLft.x += speed;
		}

		pWind->SetBrush(LAVENDER);
		pWind->SetPen(LAVENDER);
		pWind->DrawRectangle(0, uprLft.y, (1200), (uprLft.y + height), FILLED);
		pWind->UpdateBuffer();
	} while (1);
	
}

void paddle::setspeed(int newspeed)
{
	speed = newspeed;
}

int paddle::getspeed()
{
	return speed;
}

void paddle::setX(int x)
{
	uprLft.x = x;
}

int paddle::getX()
{
	return uprLft.x;
}

void paddle::setWidth(int w)
{
	width = w;
}

int paddle::getWidth()
{
	return width;
}
