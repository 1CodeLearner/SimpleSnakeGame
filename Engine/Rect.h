#pragma once

#include "Graphics.h"

class Rect {
public:
	Rect(float in_x, float in_y, float in_width, float in_height, Color in_color);

public:
	virtual void Draw(Graphics& gfx);
	virtual void Move(const float in_x, const float in_y, const Graphics& gfx);
	virtual float GetX() const;
	virtual float GetY() const;
	virtual float GetWidth() const;
	virtual float GetHeight() const;
protected:
	float x = 0;
	float y = 0;
	float width = 0; 
	float height = 0;
	Color color;
};