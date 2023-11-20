#include "Rect.h"

Rect::Rect(float in_x, float in_y, float in_width, float in_height, Color in_color)
	: x(in_x), y(in_y), width(in_width), height(in_height), color(in_color)
{
}

void Rect::Draw(Graphics& gfx)
{
	for (float in_x = x; in_x < x + width; in_x++) {
		for (float in_y = y; in_y < y + height; in_y++) {
			gfx.PutPixel(in_x, in_y, color);
		}
	}
}

void Rect::Move(float in_x, float in_y)
{
	x += in_x; 
	y += in_y;
}
