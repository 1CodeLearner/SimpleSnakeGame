#pragma once

#include "Graphics.h"
#include "Board.h"
#include "Snake.h"

class Food 
{
public:
	Food(int in_x, int in_y, Color in_color);
public:
	void CheckIfEaten(Snake& snek);
	void SetEaten();
	void Draw(Board& brd);
private:
	int loc_x = 0; 
	int loc_y = 0;
	Color color;
	bool isEaten = false;
};