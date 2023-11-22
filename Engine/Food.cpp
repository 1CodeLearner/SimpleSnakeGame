#include "Food.h"


Food::Food(Location in_loc, Color in_color)
	: loc(in_loc), color(in_color)
{}

bool Food::IsBeingEaten(const Snake& snek)
{
	if (loc == snek.GetLocation() && !isEaten) 
	{
		isEaten = true;
		return isEaten;
	}
	return false;
}

void Food::Draw(Board& brd) const
{
	if (!isEaten)
	{
		brd.DrawEntity(loc, color);
	}
}
