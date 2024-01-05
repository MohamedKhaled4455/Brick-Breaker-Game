#include "ball.h"
#include "CMUgraphicsLib\auxil.h"	// where Pause is found

ball::ball(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	collidable(r_uprleft, r_width, r_height, r_pGame) {}



void ball::ballMovement_vertically(window* win)
{
	int ballRadius = 10;
	
	do {
		//ball::balldraw(win);
		uprLft.y -= 2;
		win->SetPen(BLACK);
		win->SetBrush(LIGHTGOLDENRODYELLOW);
		//win->DrawRectangle(0, uprLft.y, (1200), (uprLft.y + height), FILLED);
		win->DrawCircle(0, uprLft.y, ballRadius, FILLED);
		win->UpdateBuffer();
		Pause(10);
	} while (true);
	
}

void ball::collisionAction()
{
}

void ball::balldraw(window* win)
{
int ballRadius = 10;
	win->SetPen(BLACK);
	win->SetBrush(LIGHTGOLDENRODYELLOW);
	win->DrawCircle(uprLft.x, uprLft.y, ballRadius, FILLED);
}