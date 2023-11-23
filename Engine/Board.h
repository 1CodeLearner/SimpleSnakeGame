#pragma once

#include "Graphics.h"
#include "Rect.h"
#include "Location.h"

class Board
{
public:
	Board(Rect in_grid, float in_paddingSize, Color in_outerColor, Graphics& gfx);

	void Draw();
	void DrawEntity(Location in_loc, Color in_color);
	bool IsEntityOutOfBounds(const class Snake& snek) const;
private:
	Rect grid;
	float paddingSize;
	Color outerColor;
	Graphics& gfx;
public:
	static constexpr int gridWidthAmount = 10;
	static constexpr int gridHeightAmount = 10;
		
};