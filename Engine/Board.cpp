#include "Board.h"

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

	//Draw outer border from top-left to bottom-right
	for (int i = x0; i <= x1; i++){
		for (int j = y0; j <= y1; j++){
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
