#include "Bricks.h"
#include "grid.h"


////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
brick::brick(point r_uprleft, int r_width, int r_height, game* r_pGame):
	collidable(r_uprleft, r_width, r_height, r_pGame)
{
}

////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
normalBrick::normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame):
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\NormalBrick.jpg";
	
}

void normalBrick::collisionAction()
{
	//TODO: Add collision action logic
	 // update score
	//hide the normal brick() >> in phase 2
     

     
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
	//TODO: Add collision action logic
	
	strength--; // reduce strength by - 1 
	if (strength > 0) {
		// update score
	}
	else {
		// update score
		// hide brick
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
	//TODO: Add collision action logic
}
