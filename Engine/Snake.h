#pragma once

#include "Colors.h"
#include "Board.h"
#include "Graphics.h"

class Snake
{
public:
	Snake(int loc_x, int loc_y, Color in_headColor, 
		Color in_bodyColor, Graphics& in_gfx);
public:
	void ChangeMoveDirection(const int move_x, const int move_y);
	void Move();
	void Grow();
	void Draw(Board& brd);
private:
	class Segment {
	public:
		Segment(){}
		Segment(int in_x, int in_y, Color in_c) 
			: loc_x(in_x), loc_y(in_y), color(in_c)
		{}
	public:
		void FollowNextSeg(Segment& next_seg)
		{
			loc_x = next_seg.loc_x;
			loc_y = next_seg.loc_y;
		}
	public:
		int loc_x = 0;
		int loc_y = 0;
		Color color;
	};
	Segment head;
	Color bodyColor;
	int GrowthAmount = 1;
	static constexpr int segTotalSize = 100;
	int segCurrentSize = 0;
	Segment* body[segTotalSize];

	int newMoveDirX = 1;
	int newMoveDirY = 0;
	int moveDirX = 1;
	int moveDirY = 0;

	Graphics& gfx;
};