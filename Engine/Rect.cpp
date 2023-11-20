#include "Rect.h"

Rect::Rect(float in_x, float in_y, float in_width, float in_height, Color in_color)
	: x(in_x), y(in_y), width(in_width), height(in_height), color(in_color)
{
}

void Rect::Draw(Graphics& gfx)
{
	//Draw pixels from top-left to bottom-right
	for (float in_x = x; in_x < x + width; in_x++) {
		for (float in_y = y; in_y < y + height; in_y++) {
			gfx.PutPixel(in_x, in_y, color);
		}
	}
}

void Rect::Move(const float in_x, const float in_y, const Graphics& gfx)
{
	//Check if rectangle is within window screen.
	if(x + width + in_x <= (float)gfx.ScreenWidth && x + in_x >= 0.f)
		x += in_x; 
	if(y + height + in_y <= (float)gfx.ScreenHeight && y + in_y >= 0.f)
		y += in_y;
}

float Rect::GetX() const
{
	return x; 
}

float Rect::GetY() const
{
	return y;
}

float Rect::GetWidth() const
{
	return width;
}

float Rect::GetHeight() const
{
	return height;
}
