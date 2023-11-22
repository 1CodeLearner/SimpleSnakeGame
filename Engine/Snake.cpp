#include "Snake.h"
#include "Graphics.h"
#include <assert.h>

Snake::Snake(Location in_loc, Color in_headColor,
	Color in_bodyColor, Graphics& in_gfx)
	: gfx(in_gfx)
{
	head.loc = in_loc;
	head.color = in_headColor;
	bodyColor = in_bodyColor;
}

Snake::~Snake()
{
	//delete[] body;
}

void Snake::ChangeMoveDirection(Location in_newDeltaLoc)
{
	assert(in_newDeltaLoc.x <= 1 && in_newDeltaLoc.x >= -1);
	assert(in_newDeltaLoc.y <= 1 && in_newDeltaLoc.y >= -1);

	newDeltaLoc = in_newDeltaLoc;

}

void Snake::Move()
{
	if (segCurrentSize != 0)
	{
		for (int i = segCurrentSize - 1; i > 0; i--)
		{
			body[i]->FollowNextSeg(*body[i - 1]);
		}

		body[0]->FollowNextSeg(head);
	}
	
	if ( -newDeltaLoc.x != deltaLoc.x || -newDeltaLoc.y != deltaLoc.y)
	{
		deltaLoc = newDeltaLoc;
	}
	head.loc += deltaLoc;
}

void Snake::Grow()
{
	if (segCurrentSize == segTotalSize)
	{
		//Victory screen maybe, some event here.
	}
	else
	{
		Segment* temp_seg = new Segment(head.loc, bodyColor);
		body[segCurrentSize] = temp_seg;

		segCurrentSize++;
	}
}

void Snake::Draw(Board& brd) const
{
	if (segCurrentSize != 0)
	{
		for (int i = 0; i < segCurrentSize; i++)
		{
			brd.DrawEntity(body[i]->loc, body[i]->color);
		}
	}
	brd.DrawEntity(head.loc, head.color);

}

Location Snake::GetLocation() const
{
	return head.loc;
}
