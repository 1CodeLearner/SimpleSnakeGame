#pragma once

#include "Colors.h"

class Snake
{
public:
	Snake(int loc_x, int loc_y, Color c);
public:
	void Move(const int move_x, const int move_y);
public:
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

	Segment head;
};