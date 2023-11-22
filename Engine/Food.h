#pragma once

#include "Graphics.h"
#include "Board.h"
#include "Location.h"

class Food 
{
public:
	Food() {};
	Food(Location in_loc, Color in_color);
public:
	void SetEaten();
	void Draw(Board& brd);
private:
	Location loc;
	Color color;
	bool isEaten = false;
};