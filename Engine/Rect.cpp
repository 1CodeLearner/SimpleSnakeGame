#include "Rect.h"

Rect::Rect()
{
	x = 100; 
	y = 100;
	width = 10; 
	height = 10;
	color = Colors::Gray;
}

void Rect::Draw(Graphics& gfx)
{
	for (int in_x = x; in_x < x + width; in_x++) {
		for (int in_y = y; in_y < y + height; in_y++) {
			gfx.PutPixel(in_x, in_y, color);
		}
	}
}
