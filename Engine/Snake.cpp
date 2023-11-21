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
	assert(move_x <= 1 && move_x >= -1);
	assert(move_y <= 1 && move_y >= -1);
	
	head.loc_x += move_x; 
	head.loc_y += move_y; 
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
