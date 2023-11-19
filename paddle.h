#pragma once
#include "collidable.h"

class paddle : public collidable
{
public:
	paddle(point r_uprleft, int r_width, int r_height, game* r_pGame);
};

