#include "Food.h"


Food::Food(int in_x, int in_y, Color in_color)
	: loc_x(in_x), loc_y(in_y), color(in_color)
{}

void Food::CheckIfEaten(Snake& snek)
{
}

void Food::SetEaten()
{
	isEaten = true;
}

void Food::Draw(Board& brd)
{
	if (!isEaten)
	{
		brd.DrawEntity(loc_x, loc_y, color);
	}
}
