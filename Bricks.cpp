#include "Bricks.h"
#include "game.h"




////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
brick::brick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	collidable(r_uprleft, r_width, r_height, r_pGame)
{
}

////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
normalBrick::normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\NormalBrick.jpg";


}

void normalBrick::collisionAction()
{
	bool checkcollision = true;// just for represnetation
	//TODO: Add collision action logic
	if (checkcollision == true) { // bool checkcollision is a reponse from checkcollision()
		// update score

		pGame->setScore(1);

		//hide the normal brick() 
	    pGame->getGrid()->hide_brick_Matrix();
		// fitst question is: is brickMatrix resposible
		// for the grid it self with i and j coordinates 
		// or it is resp. for the brick

		// if brickMatrix is resp. for the grid it self,
		// how can I remove the pointer pWind found in draw() constructor in 
		// drawable.cpp, so I remove the pointer reposible to draw the brick
		// or is it a function in window class to reomve rather than draw?
		delete pGame->getWind();

	}


}


////////////////////////////////////////////////////  class hardBrick  /////////////////////////////////
hardBrick::hardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	strength = 3;
	imageName = "images\\bricks\\hardbricks.jpg";

}

void hardBrick::collisionAction()
{

	bool checkcollision = true;// just for represnetation
	//TODO: Add collision action logic
	if (checkcollision == true) { // bool checkcollision is a reponse from checkcollision()


		strength--; // reduce strength by - 1 
		if (strength > 0) {
			// update score
			pGame->setScore(1);


		}
		else {
			// update score
			pGame->setScore(1);


			// hide brick 
		}
	}
}

////////////////////////////////////////////////////  class bombBrick  /////////////////////////////////
bombBrick::bombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\NormalBrick.jpg";
}

void bombBrick::collisionAction()
{

	bool checkcollision = true;// just for represnetation
	//TODO: Add collision action logic
	if (checkcollision == true) { // bool checkcollision is a reponse from checkcollision()
		//update score by +4
		pGame->setScore(4);
		// hide bomb brick
	}
}
