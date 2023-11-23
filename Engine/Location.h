#pragma once

struct Location
{
	Location(){}
	Location(int in_x, int in_y)
	{
		x = in_x; 
		y = in_y;
	}

	Location& operator+= (const Location& otherLoc) 
	{
		x += otherLoc.x;
		y += otherLoc.y;
		
		return *this;
	}

	Location operator+ (const Location& otherLoc) const
	{
		return Location(x + otherLoc.x, y + otherLoc.y);
	}

	bool operator== (const Location& otherLoc) const
	{
		return x == otherLoc.x && y == otherLoc.y;
	}

	int x = 0; 
	int y = 0;
};