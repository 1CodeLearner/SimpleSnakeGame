#pragma once

#include "Colors.h"
#include "Board.h"
#include "Graphics.h"

class Snake
{
public:
	Snake(int loc_x, int loc_y, Color c, Graphics& in_gfx);
public:
	void Move(const int move_x, const int move_y);
	void Draw(Board& brd);
private:
	int GetSegmentX() const;
	int GetSegmentY() const;
	Color GetColor() const;
private:
	class Segment {
	public:
		int loc_x;
		int loc_y;
		Color color;
	};
	static constexpr int segTotalSize = 100;
	int segCurrentSize = 0;
	Segment body[segTotalSize];
	Segment head;
	Graphics& gfx;
};