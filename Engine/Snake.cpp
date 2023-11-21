#include "Snake.h"
#include <assert.h>

Snake::Snake(int loc_x, int loc_y, Color c)
{
	head.loc_x = loc_x;
	head.loc_y = loc_y; 
	head.color = c;
}

void Snake::Move(const int move_x, const int move_y)
{
	assert(move_x <= 1 && move_x >= 0);
	assert(move_y <= 1 && move_y >= 0);

	
}

int Snake::GetSegmentX() const
{
	return head.loc_x;
}

int Snake::GetSegmentY() const
{
	return head.loc_y;
}

Color Snake::GetColor() const
{
	return head.color;
}
