#pragma once

#include "Graphics.h"
#include "Board.h"
#include "Location.h"
#include "Snake.h"

class Food 
{
public:
	Food() {};
	Food(Location in_loc, Color in_color);
public:
	bool IsBeingEaten(const Snake& snek) const;
	void Draw(Board& brd) const;
	void ChangeLocation(const Location& newLoc);
private:
	Location loc;
	Color color;
	bool isEaten = false;
};