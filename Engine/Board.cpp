#include "Board.h"
#include <assert.h>

Board::Board(Rect in_grid, int in_gridWidthAmount, int in_gridHeightAmount, float in_paddingSize, Color in_outerColor)
	: grid(in_grid), gridWidthAmount(in_gridWidthAmount), gridHeightAmount(in_gridHeightAmount), paddingSize(in_paddingSize), outerColor(in_outerColor)
{
}

void Board::Draw(Graphics& gfx)
{
	//find playing board size in pixel counts
	float boardSizeX = grid.GetWidth() * gridWidthAmount;
	float boardSizeY = grid.GetHeight() * gridHeightAmount;

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
		for (int i = x0; i <= x1; i++) {
			for (int j = y0; j <= y1; j++) {
				gfx.PutPixel(i, j, outerColor);
			}
		}

		//Draw playing board within outer border
		for (int i = grid.GetX(); i <= grid.GetX() + boardSizeX; i++) {
			for (int j = grid.GetY(); j <= grid.GetY() + boardSizeY; j++) {
				gfx.PutPixel(i, j, grid.GetColor());
			}
		}
	}


}

void Board::DrawEntity(int in_x, int in_y, Color in_color, Graphics& gfx)
{
	assert(in_x < gridWidthAmount);
	assert(in_y < gridHeightAmount);
	
	int leftGrid = grid.GetX() + in_x * grid.GetWidth();
	int topGrid = grid.GetY() + in_y * grid.GetHeight();

	Rect rectToDraw = Rect(topGrid, leftGrid, grid.GetWidth(), grid.GetHeight(), in_color);
	rectToDraw.Draw(gfx);
}
