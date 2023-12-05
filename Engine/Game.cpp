/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	board(Rect(50.f, 50.f, 25.f, 25.f, Colors::Gray), 5.f, Colors::Blue, gfx),
	snek(Location(2, 2), Colors::Yellow, Colors::Blue, gfx),
	food(Location(2, 5), foodColor)
{
	maxTime = maxTimeFixed * timeScaleFixed;
}
void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}


void Game::UpdateModel()
{
	if (!isGameOver)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP)) {
			if (inhibitUp)
			{
			}
			else {
				snek.ChangeMoveDirection(Location(0, -1));
				inhibitUp = true;
			}
		}
		else {
			inhibitUp = false;
		}

		if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
			if (inhibitDown)
			{
			}
			else {
				snek.ChangeMoveDirection(Location(0, 1));
				inhibitDown = true;
			}
		}
		else {
			inhibitDown = false;
		}

		if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
			if (inhibitRight)
			{
			}
			else {
				snek.ChangeMoveDirection(Location(1, 0));
				inhibitRight = true;
			}
		}
		else {
			inhibitRight = false;
		}

		if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
			if (inhibitLeft)
			{
			}
			else {
				snek.ChangeMoveDirection(Location(-1, 0));
				inhibitLeft = true;
			}
		}
		else {
			inhibitLeft = false;
		}
		
		if (counterTime <= maxTime)
		{
			counterTime += dt.Mark();
		}
		else
		{
			if (board.IsEntityOutOfBounds(snek) || snek.WillCollideWithItself())
			{
				isGameOver = true;
			}
			else {
				//Where game action happens, check all events here.
				if (food.IsBeingEaten(snek))
				{
					snek.Grow();
					RespawnFood();
					CalculateSnakeSpeed();
				}
				snek.Move();
				counterTime = 0.f;
			}
		}
	}
}

void Game::ComposeFrame()
{
	board.Draw();
	food.Draw(board);
	snek.Draw(board);
}


void Game::RespawnFood()
{
	Location randomLoc;
	int valueX = 0;
	int valueY = 0;
	std::mt19937 randomizer((int)time(0));
	std::uniform_int_distribution<> rangeX(0, Board::gridAmountInWidth - 1);
	std::uniform_int_distribution<> rangeY(0, Board::gridAmountInHeight - 1);
	do
	{
		valueX = rangeX(randomizer);
		valueY = rangeY(randomizer);
		randomLoc = Location(valueX, valueY);
	} while (snek.HasLocation(randomLoc));

	food.ChangeLocation(randomLoc);
}