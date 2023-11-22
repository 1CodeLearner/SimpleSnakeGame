#pragma once

struct Location
{
	Location(){}
	Location(int in_x, int in_y)
	{
		x = in_x; 
		y = in_y;
	}

	Location& operator+= (Location& otherLoc) 
	{
		x += otherLoc.x;
		y += otherLoc.y;
		
		return *this;
	}

	int x = 0; 
	int y = 0;
};