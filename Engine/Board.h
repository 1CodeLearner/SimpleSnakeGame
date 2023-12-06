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
	void InitializeBoard(const Snake& snek, const class Food& food);
	void SetObstacles(int numObstacles = 1, bool _isEnableObstacle = true);

public:
	static constexpr int gridAmountInWidth = 3;
	static constexpr int gridAmountInHeight = 3;

private:
	bool isEnableObstacle = false; 
	Rect oneGridDim;
	float paddingSize;
	Color outerColor;
	Graphics& gfx;
	int numObstacles = 0;
	bool Obstacles[gridAmountInWidth * gridAmountInHeight] = { false };
};