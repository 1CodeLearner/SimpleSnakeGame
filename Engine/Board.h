#pragma once

#include "Graphics.h"
#include "Rect.h"
#include "Location.h"

class Board
{
public:
	Board(Rect in_grid, int in_gridWidthAmount, int in_gridHeightAmount, float in_paddingSize, Color in_outerColor, Graphics& gfx);

	void Draw();

	void DrawEntity(Location in_loc, Color in_color);

private:
	Rect grid;
	int gridWidthAmount;
	int gridHeightAmount;
	float paddingSize;
	Color outerColor;
	Graphics& gfx;
		
};