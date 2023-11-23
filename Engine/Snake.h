#pragma once

#include "Board.h"
#include "Graphics.h"
#include "Location.h"

class Snake
{
public:
	Snake(Location in_loc, Color in_headColor, 
		Color in_bodyColor, Graphics& in_gfx);
	~Snake();
public:
	void ChangeMoveDirection(const Location in_newDeltaLoc);
	void Move();
	void Grow();
	void Draw(Board& brd) const;
	Location GetNextLocation() const;
	bool WillCollideWithItself() const;
	bool HasLocation(const Location& in_loc) const;
private:
	class Segment {
	public:
		Segment(){}
		Segment(Location in_loc, Color in_c) 
			: color(in_c)
		{
			loc = in_loc;
		}
	public:
		void FollowNextSeg(Segment& next_seg)
		{
			loc = next_seg.loc;
		}
	public:
		Location loc;
		Color color;
	};
	Segment head;
	int GrowthAmount = 1;
	static constexpr int segTotalSize = 100;
	int segCurrentSize = 0;
	Segment* body[segTotalSize];
	Color bodyColor;

	Location newDeltaLoc = { 1, 0 };
	Location deltaLoc = { 1, 0 };

	Graphics& gfx;
};