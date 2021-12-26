#include "Board.h"
#include <raylib.h>
#include <iostream>
#include <sstream>

Board::Board()
{
	Players.push_back(Player());

	for (int i = 0; i < 5; i++)
	{
		Player NewPlayer = Player();
		for (int j = 0; j < Players.size(); j++)
		{
			while (NewPlayer.X == Players[j].X && NewPlayer.Y == Players[j].Y)
			{
				NewPlayer = Player();
			}
		}
		Players.push_back(NewPlayer);
	}
}

void Board::DrawBoard()
{
	//Verticle lines
	for (int i = 0; i < XDim; i++)
	{
		DrawRectangle(i * 50, 0, 2, 500, BLACK);
	}

	//Horizontial lines
	for (int i = 0; i < YDim; i++)
	{
		DrawRectangle(0, i * 42, 1000, 2, BLACK);
	}


	//Draw Players
	for (int i = 1; i < this->Players.size(); i++)
	{
		DrawRectangle(Players[i].X * 50 + 1, Players[i].Y * 42 + 1, 50, 42, BLUE);
		if (Players[i].IsClicked)
		{
			//If player is at the top player info is out of window
			if (Players[i].Y > 1)
			{
				//Draw Background rectangle
				DrawRectangle(Players[i].X * 50 - 50, Players[i].Y * 42 - 84, 150, 84, GRAY);
				//Name
				DrawText(("Name: " + Players[i].Name).c_str(), Players[i].X * 50 - 50, Players[i].Y * 42 - 80, 10, RED);
				//Health
				std::string Health;
				Health = Health + "Health: " + std::to_string(Players[i].HealthPoints);
				DrawText(Health.c_str(), Players[i].X * 50 - 50, Players[i].Y * 42 - 70, 10, RED);
				//Action points
				std::string Action;
				Action = Action + "Power: " + std::to_string(Players[i].ActionPoints);
				DrawText(Action.c_str(), Players[i].X * 50 - 50, Players[i].Y * 42 - 60, 10, RED);
			}
			else
			{
				//Draw Background rectangle
				DrawRectangle(Players[i].X * 50 - 50 , Players[i].Y * 42 + 42, 150, 84, GRAY);
				//Name
				DrawText(("Name: " + Players[i].Name).c_str(), Players[i].X * 50 - 50, Players[i].Y * 42 + 80, 10, RED);
				//Health
				std::string Health;
				Health = Health + "Health: " + std::to_string(Players[i].HealthPoints);
				DrawText(Health.c_str(), Players[i].X * 50 - 50, Players[i].Y * 42 + 70, 10, RED);
				//Action points
				std::string Action;
				Action = Action + "Power: " + std::to_string(Players[i].ActionPoints);
				DrawText(Action.c_str(), Players[i].X * 50 - 50, Players[i].Y * 42 + 60, 10, RED);
			}
		}
		DrawRectangle(Players[0].X * 50 + 1, Players[0].Y * 42 + 1, 50, 42, GREEN);
	}
	if (Players[0].IsClicked)
	{
		if (Players[0].Y > 1)
		{
			DrawRectangle(Players[0].X * 50 - 50, Players[0].Y * 42 - 84, 150, 84, GRAY);
		}
		else
		{
			//Draw Background rectangle
			DrawRectangle(Players[0].X * 50 - 50, Players[0].Y * 42 + 42, 150, 84, GRAY);
		}
	}
}

//info box is 
void Board::ClickPlayer(uint8_t x, uint8_t y)
{
	//Get rid of old clicked on players
	for (int i = 0; i < Players.size(); i++)
	{
		if (Players[i].IsClicked || Players[i].X != x && Players[i].Y != y)
		{
			Players[i].IsClicked = false;
		}
	}

	for (int i = 0; i < Players.size(); i++)
	{
		if (Players[i].X == x && Players[i].Y == y)
		{
			Players[i].IsClicked = !Players[i].IsClicked;
		}
	}
	
}