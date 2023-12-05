#pragma once

#include "Graphics.h"
#include "Rect.h"
#include "Location.h"

class Board
{
public:
	Board(Rect _oneGridDim, float in_paddingSize, Color in_outerColor, Graphics& gfx);

	void Draw();
	void DrawEntity(Location in_loc, Color in_color);
	bool IsEntityOutOfBounds(const class Snake& snek) const;
private:
	Rect oneGridDim;
	float paddingSize;
	Color outerColor;
	Graphics& gfx;
public:
	static constexpr int gridAmountInWidth = 20;
	static constexpr int gridAmountInHeight = 20;
	
};