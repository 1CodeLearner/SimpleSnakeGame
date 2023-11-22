#include "Board.h"
#include <assert.h>

Board::Board(Rect in_grid, int in_gridWidthAmount, int in_gridHeightAmount, float in_paddingSize, Color in_outerColor, Graphics& gfx)
	: grid(in_grid), gridWidthAmount(in_gridWidthAmount), gridHeightAmount(in_gridHeightAmount), 
	paddingSize(in_paddingSize), outerColor(in_outerColor), gfx(gfx)
{
}

void Board::Draw()
{
	//find playing board size in pixel counts
	float boardSizeX = grid.GetWidth() * (float)gridWidthAmount;
	float boardSizeY = grid.GetHeight() * (float)gridHeightAmount;

	//Find outer border coordinates
	float x0 = grid.GetX() - paddingSize; 
	float y0 = grid.GetY() - paddingSize;
	float x1 = grid.GetX() + boardSizeX + paddingSize; 
	float y1 = grid.GetY() + boardSizeY + paddingSize; 

	if (x0 < 0 || x1 > gfx.ScreenWidth) {

	}
	else if (y0 < 0 || y1 > gfx.ScreenHeight){

	}
	else {
		//Draw outer border from top-left to bottom-right
		for (int i = (int)x0; i <= (int)x1; i++) {
			for (int j = (int)y0; j <= (int)y1; j++) {
				gfx.PutPixel(i, j, outerColor);
			}
		}

		//Draw playing board within outer border
		for (int i = (int)grid.GetX(); i <= (int)(grid.GetX() + boardSizeX); i++) {
			for (int j = (int)grid.GetY(); j <= (int)(grid.GetY() + boardSizeY); j++) {
				gfx.PutPixel(i, j, grid.GetColor());
			}
		}
	}


}

void Board::DrawEntity(Location in_loc, Color in_color)
{
	assert(in_loc.x < gridWidthAmount);
	assert(in_loc.y < gridHeightAmount);
	
	float leftGrid = grid.GetX() + (float)in_loc.x * grid.GetWidth();
	float topGrid = grid.GetY() + (float)in_loc.y * grid.GetHeight();

	Rect rectToDraw = Rect(leftGrid, topGrid, grid.GetWidth(), grid.GetHeight(), in_color);
	rectToDraw.Draw(gfx);
}
