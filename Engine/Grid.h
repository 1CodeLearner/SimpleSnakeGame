#pragma once

#include "Graphics.h"
#include "Rect.h"

class Grid
{
public:
	Grid(Rect in_box, float in_paddingSize, Color in_outerColor);

	void Draw(Graphics& gfx);


private:
	Rect box; 
	float paddingSize;
	Color outerColor;

};