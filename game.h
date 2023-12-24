#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include "grid.h"
#include "Bricks.h"
#include "paddle.h"
#include "ball.h"







//Main class that coordinates the game operation
class game
{

	enum MODE	//Game mode
	{
		MODE_DSIGN,	//Desing mode (startup mode)
		MODE_PLAY	//Playing mode
	};

	MODE gameMode;

	/// Add more members if needed
	
	normalBrick* n;
	paddle* ppaddle; // Pointer to paddle
	ball* pball;
	window* pWind;	//Pointer to the CMU graphics window
	toolbar* gameToolbar;
	grid* bricksGrid;

public:
	game();
	~game();

	void setScore(int s);

	clicktype getMouseClick(int& x, int& y) const;//Get coordinate where user clicks and returns click type (left/right)
	string getSrting() const;	 //Returns a string entered by the user


	window* CreateWind(int, int, int, int) const; //creates the game window


	void clearStatusBar() const;	//Clears the status bar


	void printMessage(string msg) const;	//Print a message on Status bar

	void go() const;

	void play() ; // to switch from design to play mode

	window* getWind() const;		//returns a pointer to the graphics window


	grid* getGrid() const;
};

