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
	board(Rect(20.f, 20.f, 25.f, 25.f, Colors::Gray), boardWidthTotal, boardHeightTotal, 5.f, Colors::Blue,gfx),
	snek(Location(2, 2), Colors::Blue, Colors::Yellow, gfx),
	food(Location(2, 5), foodColor)
{}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}


void Game::UpdateModel()
{
	if (food.IsBeingEaten(snek)) 
	{
		snek.Grow();
	}

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
	
	if (frameCounter != frameCounterMax)
	{
		frameCounter++;
	}
	else
	{
		snek.Move();
		frameCounter = 0;
	}
}

void Game::ComposeFrame()
{
	board.Draw();
	food.Draw(board);
	snek.Draw(board);
	
}