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

void Snake::ChangeMoveDirection(const Location in_newDeltaLoc)
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

	if (IsValidMove())
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
		Segment* temp_seg = nullptr;
		if (segCurrentSize == 0)
		{
			temp_seg = new Segment(head.loc, bodyColor);
			body[segCurrentSize] = temp_seg;
		}
		else
		{
			temp_seg = new Segment(body[segCurrentSize - 1]->loc, bodyColor);
			body[segCurrentSize] = temp_seg;
		}


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

Location Snake::GetNextLocation() const
{

	return head.loc + newDeltaLoc;
}

bool Snake::WillCollideWithItself() const
{
	if (IsValidMove())
	{
		bool isCollidingWithBody = false;
		for (int i = 0; i < segCurrentSize; i++)
		{
			if (GetNextLocation() == body[i]->loc)
			{
				return true;
			}
		}
		return isCollidingWithBody;
	}
	return false;
}

bool Snake::HasLocation(const Location& in_loc) const
{
	if (head.loc == in_loc || GetNextLocation() == in_loc) {
		return true;
	}

	for (int i = 0; i < segCurrentSize; i++)
	{
		if (body[i]->loc == in_loc)
		{
			return true;
		}
	}

	return false;
}

bool Snake::IsValidMove() const
{
	return -newDeltaLoc.x != deltaLoc.x || -newDeltaLoc.y != deltaLoc.y;
}
