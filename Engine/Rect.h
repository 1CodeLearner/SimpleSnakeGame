#pragma once

#include "Graphics.h"

class Rect {
public:
	Rect();

public:
	void Draw(Graphics& gfx);
private:
	int x = 0;
	int y = 0;
	int width = 0; 
	int height = 0;
	Color color;
};