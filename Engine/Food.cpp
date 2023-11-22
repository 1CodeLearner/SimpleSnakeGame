#include "Food.h"


Food::Food(Location in_loc, Color in_color)
	: loc(in_loc), color(in_color)
{}

void Food::SetEaten()
{
	isEaten = true;
}

void Food::Draw(Board& brd)
{
	if (!isEaten)
	{
		brd.DrawEntity(loc, color);
	}
}
