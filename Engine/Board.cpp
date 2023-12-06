#include <assert.h>
#include "Board.h"
#include "Snake.h"
#include "Food.h"
#include <random>
#include <ctime>

Board::Board(Rect _oneGridDim, float in_paddingSize, Color in_outerColor, Graphics& gfx)
	: oneGridDim(_oneGridDim), paddingSize(in_paddingSize), 
	outerColor(in_outerColor), gfx(gfx)
{
}



void Board::Draw()
{
	//find playing board size in pixel counts
	float boardSizeX = oneGridDim.GetWidth() * (float)gridAmountInWidth;
	float boardSizeY = oneGridDim.GetHeight() * (float)gridAmountInHeight;

	//Find outer border coordinates
	float x0 = oneGridDim.GetX() - paddingSize;
	float y0 = oneGridDim.GetY() - paddingSize;
	float x1 = oneGridDim.GetX() + boardSizeX + paddingSize;
	float y1 = oneGridDim.GetY() + boardSizeY + paddingSize;

	//Check out-of-bounds
	if (x0 < 0 || x1 > gfx.ScreenWidth) {

	}
	//Check out-of-bounds
	else if (y0 < 0 || y1 > gfx.ScreenHeight) {

	}
	else {
		//Draw outer border from top-left to bottom-right
		for (int i = (int)x0; i <= (int)x1; i++) {
			for (int j = (int)y0; j <= (int)y1; j++) {
				gfx.PutPixel(i, j, outerColor);
			}
		}

		//Draw playing board within outer border
		for (int i = (int)oneGridDim.GetX(); i <= (int)(oneGridDim.GetX() + boardSizeX); i++) {
			for (int j = (int)oneGridDim.GetY(); j <= (int)(oneGridDim.GetY() + boardSizeY); j++) {
				gfx.PutPixel(i, j, oneGridDim.GetColor());
			}
		}
	}

	if(isEnableObstacle)
	{
		int totalGrids = gridAmountInHeight * gridAmountInWidth;
		for (int i = 0; i < gridAmountInWidth; i++)
		{
			for (int j = 0; j < gridAmountInHeight; j++)
			{
				if (Obstacles[i * gridAmountInWidth + j])
				{
					DrawEntity(Location{ j,i }, Colors::Red);
				}
			}
		}
	}
}

void Board::DrawEntity(Location in_loc, Color in_color)
{
	float leftGrid = oneGridDim.GetX() + (float)in_loc.x * oneGridDim.GetWidth();
	float topGrid = oneGridDim.GetY() + (float)in_loc.y * oneGridDim.GetHeight();

	Rect rectToDraw = Rect(leftGrid, topGrid, oneGridDim.GetWidth(), oneGridDim.GetHeight(), in_color);
	rectToDraw.Draw(gfx);
}

bool Board::IsEntityOutOfBounds(const Snake& snek) const
{
	return snek.GetNextLocation().x >= gridAmountInWidth || snek.GetNextLocation().x < 0
		|| snek.GetNextLocation().y >= gridAmountInHeight || snek.GetNextLocation().y < 0;
}

void Board::InitializeBoard(const Snake& snek, const Food& food)
{
	assert(numObstacles < gridAmountInHeight * gridAmountInWidth);

	std::mt19937 random((unsigned int)time(NULL));
	std::uniform_int_distribution<int> distX(0, gridAmountInWidth - 1);
	std::uniform_int_distribution<int> distY(0, gridAmountInHeight - 1);

	if (isEnableObstacle)
	{
		int x;
		int y;

		for (int i = 0; i < numObstacles; i++)
		{
			do
			{
				x = distX(random);
				y = distY(random);
			} while (
				snek.HasLocation(Location(x, y)) && food.HasLocation(Location(x, y)) && 
				Obstacles[y * gridAmountInWidth + x]
			);
			Obstacles[y * gridAmountInWidth + x] = true;
		}
	}

}

void Board::SetObstacles(int numObstacles, bool _isEnableObstacle)
{
	assert(numObstacles < gridAmountInHeight * gridAmountInWidth);
	
	isEnableObstacle = _isEnableObstacle;
	this->numObstacles = numObstacles;
}
