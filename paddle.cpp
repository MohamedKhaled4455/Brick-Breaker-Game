#include "paddle.h"
#include "game.h"
#include "CMUgraphicsLib\auxil.h"	// where Pause is found
paddle::paddle(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	collidable(r_uprleft, r_width, r_height, r_pGame) {}

// getters functions

//point paddle::getpaddleP()
//{
//	return uprLft ;
//}
//
//int paddle::getpaddlehight()
//{
//	return height;
//}
//int paddle::getpaddlewidth()
//{
//	return width;
//}
//
//void paddle::setpaddleP(int xp, int yp)
//{
//	uprLft.x = xp;
//	uprLft.y = yp;
//}
//
//// setters functions
//void paddle::setpaddlehight(int h)
//{
//	height = h;
//}
//void paddle::setpaddlewidth(int w)
//{
//	width = w;
//}

void paddle::draw()
{
	window* win = pGame->getWind();
		win->SetBrush(CORNFLOWERBLUE);
	win->SetPen(BLACK);
	win->DrawRectangle(uprLft.x, uprLft.y, (uprLft.x + width), (uprLft.y + height), FILLED);
}

void paddle::collisionAction()
{
}

void paddle::movement()
{// paddle movement function that responsible for both the draw and the movement of the paddle
	window* win = pGame->getWind();

	
		paddle::draw();
		char Key;
		keytype ktype;
		ktype = win->WaitKeyPress(Key);

		if (Key == 4 && uprLft.x != 0)
		{
			uprLft.x -= 15;
		}
		if (Key == 6 && uprLft.x < 1200 - width) {
			uprLft.x += 15;
		}
		win->SetBrush(LAVENDER);
		win->SetPen(LAVENDER);
		win->DrawRectangle(0, uprLft.y, (1200), (uprLft.y + height), FILLED);
		win->UpdateBuffer();
	
}

point paddle::getuprlft() const
{
	return uprLft;
}

int paddle::getwidth() const
{
	return width;
}
