#include "ball.h"
#include "game.h"
#include "CMUgraphicsLib\auxil.h"	// where Pause is found

ball::ball(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	collidable(r_uprleft, r_width, r_height, r_pGame) {}



void ball::ballMovement()
{

	window* win = pGame->getWind();

	//ball::balldraw(win);
	emptyball();
	uprLft.y += vecy;
	uprLft.x += vecx;
	balldraw();
	win->UpdateBuffer();



}

void ball::collisionAction()
{

}

void ball::balldraw()
{
	int ballRadius = 10;
	window* win = pGame->getWind();
	win->SetPen(BLACK);
	win->SetBrush(LIGHTGOLDENRODYELLOW);
	win->DrawCircle(uprLft.x, uprLft.y, ballRadius, FILLED);
}

void ball::emptyball()
{
	int ballRadius = 10;
	window* win = pGame->getWind();
	win->SetPen(LAVENDER);
	win->SetBrush(LAVENDER);
	win->DrawCircle(uprLft.x, uprLft.y, ballRadius, FILLED);
}
