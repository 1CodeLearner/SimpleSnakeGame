#pragma once

#include "Graphics.h"

class Rect {
public:
	Rect(float in_x, float in_y, float in_width, float in_height, Color in_color);

public:
	void Draw(Graphics& gfx);
	void Move(const float in_x, const float in_y, const Graphics& gfx);
private:
	float x = 0;
	float y = 0;
	float width = 0; 
	float height = 0;
	Color color;
};