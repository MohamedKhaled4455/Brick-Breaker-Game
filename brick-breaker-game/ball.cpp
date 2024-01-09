#include "ball.h"
#include "game.h"
#include <math.h>
#include "CMUgraphicsLib\auxil.h"	// where Pause is found

ball::ball(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	collidable(r_uprleft, r_width, r_height, r_pGame)
{ 
	xreset = uprLft.x;
	yreset = uprLft.y;

}



void ball::ballMovement()
{

	window* win = pGame->getWind();

	emptyball();
	uprLft.y += vecy;
	uprLft.x += vecx;
	balldraw();
	win->UpdateBuffer();



}

void ball::ballMovementVertically()
{

	window* win = pGame->getWind();

	emptyball();
	uprLft.y -= vecy;
	balldraw();
	win->UpdateBuffer();
}

void ball::collisionAction()
{

}

void ball::setcollisionpoint(point c)
{
	collision = c;

}

//void ball::BallPaddleReflection()
//{
//	paddle* p = pGame->getpaddle();
//	double midpointx = (p->getuprlft().x + p->getwidth()) / 2;
//	// coding equation theta = kL as stated in the derivation in notion
//	double scaleRation = 45 / (p->getwidth() / 2);
//	double lengthFromMidpoint = abs(collision.x) - midpointx;
//	double theta = scaleRation * lengthFromMidpoint;
//	// tan(theta) = m/y as stated in the derivation
//	double newX = abs(vecy) * tan(theta);
//
//	if (collision.x == midpointx) {// make sure that collison x is not the x from the whole grid
//		vecy = -vecy; // reflection on the y-axix
//	}
//	else if (collision.x < midpointx) {
//		vecy = -vecy; // reflection on the y-axix
//		vecx = newX; // reflection by certain theta with the control of new x value
//	}
//	else
//	{
//		vecy = -vecy; // reflection on the y-axix
//		vecx = -newX; // reflection by certain theta with the control of new x value
//	}
//
//
//}

//void ball::BallBrickReflection(int i, int j)
//{
//	brick*** brickMatrix = pGame->getGrid()->getbrickmatrix();
//	//brickMatrix[i][j]
//	double midpointx = (brickMatrix[i][j]->getuprlft().x + p->getwidth()) / 2;
//	// coding equation theta = kL as stated in the derivation in notion
//	double scaleRation = 45 / (p->getwidth() / 2);
//	double lengthFromMidpoint = abs(collision.x) - midpointx;
//	double theta = scaleRation * lengthFromMidpoint;
//	// tan(theta) = m/y as stated in the derivation
//	double newX = abs(vecy) * tan(theta);
//
//	if (collision.x == midpointx) {// make sure that collison x is not the x from the whole grid
//		vecy = -vecy; // reflection on the y-axix
//	}
//	else if (collision.x < midpointx) {
//		vecy = -vecy; // reflection on the y-axix
//		vecx = newX; // reflection by certain theta with the control of new x value
//	}
//	else
//	{
//		vecy = -vecy; // reflection on the y-axix
//		vecx = -newX; // reflection by certain theta with the control of new x value
//	}
//
//}


void ball::BallWallReflection()
{
	// Check collision with left and right boundaries and perform reflection
	if (collision.x <= 0 + ballRadius || collision.x >= pGame->getWind()->GetWidth() - ballRadius) {
		vecx = -vecx; // Reflect horizontally on left or right collision
	}

	// Check collision with top boundary and perform reflection
	if (collision.y <= 0 + ballRadius) {
		vecy = -vecy;
	}
}
void ball::balldraw()
{

	window* win = pGame->getWind();
	win->SetPen(BLACK);
	win->SetBrush(LIGHTGOLDENRODYELLOW);
	win->DrawCircle(uprLft.x, uprLft.y, ballRadius, FILLED);
}

void ball::emptyball()
{
	window* win = pGame->getWind();
	win->SetPen(LAVENDER);
	win->SetBrush(LAVENDER);
	win->DrawCircle(uprLft.x, uprLft.y, ballRadius, FILLED);
}

int ball::getYPosition()
{
	return uprLft.y-ballRadius;
}

int ball::getXPosition()
{
	return uprLft.x - ballRadius;
}
// resets ball position after colliding with the bottom
int ball::setresetposition()
{
	uprLft.x = xreset;
	uprLft.y = yreset;
}

int ball::getraduis()
{
	return ballRadius;
}