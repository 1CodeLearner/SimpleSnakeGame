#pragma once

#include "Graphics.h"
#include "Rect.h"

class Board
{
public:
	Board(Rect in_grid, int in_gridWidthAmount, int in_gridHeightAmount, float in_paddingSize, Color in_outerColor);

	void Draw(Graphics& gfx);


private:
	Rect grid;
	int gridWidthAmount;
	int gridHeightAmount;
	float paddingSize;
	Color outerColor;
		
};