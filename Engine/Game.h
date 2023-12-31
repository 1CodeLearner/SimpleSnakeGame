/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Board.h"
#include "Snake.h"
#include "Food.h"
#include "Location.h"
#include "DeltaTime.h"
#include <random>
#include <ctime>

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void RespawnFood();
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	Board board;

	Snake snek;
	bool inhibitUp = false;
	bool inhibitDown = false;
	bool inhibitLeft = false;
	bool inhibitRight = false;
	bool inhibitSpace = false;

	Food food;
	Color foodColor = Colors::Green;


	const float timeScaleFixed = 2.f;
	float timeScaleMax = 1.f;
	float timeScaleDelta = -.1;

	const float maxTimeFixed = .1f;

	float maxTime = 0.f;
	float counterTime = 0.f;
	
	class DeltaTime dt;


	void CalculateSnakeSpeed()
	{
		if (snek.GetSegCurrentSize() != 0)
		{
			const float timeScaleCurrent = timeScaleFixed + timeScaleDelta * snek.GetSegCurrentSize();
			if (timeScaleCurrent > timeScaleMax)
			{
				maxTime = maxTimeFixed * timeScaleCurrent;
			}
		}
	}
	/********************************/
};