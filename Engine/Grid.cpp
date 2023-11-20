#include "Grid.h"

Grid::Grid(Rect in_box, float in_paddingSize, Color in_outerColor)
	: box(in_box), paddingSize(in_paddingSize), outerColor(in_outerColor)
{
}

void Grid::Draw(Graphics& gfx)
{
	//Draw bigger box first. Draw a smaller box within the previously drawn box.
	Rect OuterBox = Rect(box.GetX() - paddingSize, box.GetY() - paddingSize, 
		box.GetWidth() + 2 * paddingSize, box.GetHeight() + 2 * paddingSize, outerColor);

	OuterBox.Draw(gfx);
	box.Draw(gfx);
}
