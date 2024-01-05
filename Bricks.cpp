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
	    pGame->getGrid()->hide_brick_Matrix(uprLft);
		
	}


}


////////////////////////////////////////////////////  class hardBrick  /////////////////////////////////
hardBrick::hardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	strength = 3;
	imageName = "images\\bricks\\hardbrick.png";

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
			pGame->getGrid()->hide_brick_Matrix(uprLft);

		}
	}
}

////////////////////////////////////////////////////  class bombBrick  /////////////////////////////////
bombBrick::bombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\bombbrick.png";
}

void bombBrick::collisionAction()
{

	bool checkcollision = true;// just for represnetation
	//TODO: Add collision action logic
	if (checkcollision == true) { // bool checkcollision is a reponse from checkcollision()
		// hide bomb brick
	    pGame->getGrid()->hide_brick_Matrix(uprLft);
		// hide upper, lower, right, and left bricks
		pGame->getGrid()->hide_bricks_of_bombbrick(uprLft);
		//update score by +4
		pGame->setScore(4);
	}
}
////////////////////////////////////////////////////  class rockBrick  /////////////////////////////////

rockBrick::rockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame):
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\rockbrick.png";

}

void rockBrick::collisionAction()
{
	bool checkcollision = true;// just for represnetation

	//TODO: Add collision action logic
	if (checkcollision == true) { 
	// nothing will happen, just normal reflection
	}
}
