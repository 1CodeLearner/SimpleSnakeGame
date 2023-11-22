#include "Snake.h"
#include "Graphics.h"
#include <assert.h>

Snake::Snake(int loc_x, int loc_y, Color in_headColor, 
	Color in_bodyColor, Graphics& in_gfx)
	: gfx(in_gfx)
{
	head.loc_x = loc_x;
	head.loc_y = loc_y;
	head.color = in_headColor;
	bodyColor = in_bodyColor;
}

void Snake::Move(const int move_x, const int move_y)
{
	assert(move_x <= 1 && move_x >= -1);
	assert(move_y <= 1 && move_y >= -1);
	
	if(segCurrentSize != 0)
	{
		for (int i = segCurrentSize - 1; i > 0; i--)
		{
			body[i]->FollowNextSeg(*body[i - 1]);
		}

		body[0]->FollowNextSeg(head);
	}
	head.loc_x += move_x; 
	head.loc_y += move_y; 
}

void Snake::Grow()
{
	if(segCurrentSize == segTotalSize)
	{
		//Victory screen maybe, some event here.
	}
	else 
	{
		/*if (segCurrentSize == 0)
		{
			Segment* temp_seg = new Segment(head.loc_x, head.loc_y, bodyColor);
			body[segCurrentSize] = temp_seg;
		}
		else
		{
			Segment* temp_seg = new Segment(body[segCurrentSize-1]->loc_x,
				body[segCurrentSize - 1]->loc_y, bodyColor);
			body[segCurrentSize] = temp_seg;
		}*/
		Segment* temp_seg = new Segment(head.loc_x, head.loc_y, bodyColor);
		body[segCurrentSize] = temp_seg;

		segCurrentSize++;
	}
}

void Snake::Draw(Board& brd)
{
	if (segCurrentSize != 0)
	{
		for (int i = 0; i < segCurrentSize; i++)
		{
			brd.DrawEntity(body[i]->loc_x, body[i]->loc_y, body[i]->color);
		}
	}
	brd.DrawEntity(head.loc_x, head.loc_y, head.color);

}