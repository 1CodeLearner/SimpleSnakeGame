#include "Food.h"


Food::Food(Location in_loc, Color in_color)
	: loc(in_loc), color(in_color)
{}

bool Food::IsBeingEaten(const Snake& snek) const 
{
	return loc == snek.GetNextLocation() && !isEaten;
}

void Food::Draw(Board& brd) const
{
	if (!isEaten)
	{
		brd.DrawEntity(loc, color);
	}
}

void Food::ChangeLocation(const Location& newLoc)
{
	loc = newLoc;
}
