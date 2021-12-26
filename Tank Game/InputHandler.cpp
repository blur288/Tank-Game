#include <raylib.h>
#include "InputHandler.h"
#include <iostream>

void WarningMessage::Display(std::string Message)
{
	if (Show)
	{
		//font size + # of characters - 3 pixels between characters
		DrawRectangle(1000 / 2 - 250, 500 / 2 - 150, 500, 300, GRAY);

		DrawText(Message.c_str(), 500 - Message.size() * 10 + (Message.size() - 1) * 3, 250 - 21, 30, BLACK);

		//yes
		DrawRectangle(500 - 100, 250 + 40, 80, 40, GREEN);
		//no
		DrawRectangle(500 + 100 - 80, 250 + 40, 80, 40, RED);

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			//get mouse position
			Vector2 MousePosition = GetMousePosition();
			//yes pressed
			if (MousePosition.x > 400 && MousePosition.x < 480)
			{
				if (MousePosition.y > 290 && MousePosition.y < 330)
				{
					Result = 1;
					Show = 0;
				}
			}
			//no pressed
			else if (MousePosition.x > 520 && MousePosition.x < 600)
			{
				if (MousePosition.y > 290 && MousePosition.y < 330)
				{
					Result = 0;
					Show = 0;
				}
			}
		}
	}
}

void Input::GetInput(Board& board)
{
	Player* Client = &board.Players[0];

	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Vector2 MousePosition = GetMousePosition();
		MousePosition.x /= 50;
		MousePosition.y /= 42;

		MousePosition.x = (float)(int)MousePosition.x;
		MousePosition.y = (float)(int)MousePosition.y;

		std::cout << MousePosition.x << ':' << MousePosition.y << std::endl;

		board.ClickPlayer(MousePosition.x, MousePosition.y);
	}
	//cycles player
	if (IsKeyPressed(KEY_N))
	{
		board.Players.push_back(*Client);
		board.Players.erase(board.Players.begin());
	}
	//Player movement
	//Up
	if (IsKeyPressed(KEY_W))
	{
		if (Client->ActionPoints > 0 && Client->Y != 0)
		{
			bool CanMove = 1;
			for (int i = 0; i < board.Players.size(); i++)
			{
				if (board.Players[i].X == Client->X && board.Players[i].Y == Client->Y - 1)
				{
					CanMove = 0;
				}
			}
			if (CanMove)
			{
				Client->Y--;
			}
		}
	}
	//Down
	if (IsKeyPressed(KEY_S))
	{
		if (Client->ActionPoints > 0 && Client->Y != 11)
		{
			bool CanMove = 1;
			for (int i = 0; i < board.Players.size(); i++)
			{
				if (board.Players[i].X == Client->X && board.Players[i].Y == Client->Y + 1)
				{
					CanMove = 0;
				}
			}
			if (CanMove)
			{
				Client->Y++;
			}
		}
	}
	//Left
	if (IsKeyPressed(KEY_A))
	{
		if (Client->ActionPoints > 0 && Client->X != 0)
		{
			bool CanMove = 1;
			for (int i = 0; i < board.Players.size(); i++)
			{
				if (board.Players[i].X == Client->X - 1 && board.Players[i].Y == Client->Y)
				{
					CanMove = 0;
				}
			}
			if (CanMove)
			{
				Client->X--;
			}
		}
	}
	//Right
	if (IsKeyPressed(KEY_D))
	{
		if (Client->ActionPoints > 0 && Client->X != 19)
		{
			bool CanMove = 1;
			for (int i = 0; i < board.Players.size(); i++)
			{
				if (board.Players[i].X == Client->X + 1 && board.Players[i].Y == Client->Y)
				{
					CanMove = 0;
				}
			}
			if (CanMove)
			{
				Client->X++;
			}
		}
	}

	//Attack / give
	if (IsKeyPressed(KEY_F))
	{
		for (int i = 0; i < board.Players.size(); i++)
		{
			if (board.Players[i].IsClicked)
			{
				if (Client->ActionPoints > 0)
				{
					--board.Players[i].HealthPoints;
					--Client->ActionPoints;
				}
			}
		}
	}
	if (IsKeyPressed(KEY_G))
	{
		for (int i = 0; i < board.Players.size(); i++)
		{
			if (board.Players[i].IsClicked)
			{
				if (Client->ActionPoints > 0)
				{
					++board.Players[i].ActionPoints;
					--Client->ActionPoints;
				}
			}
		}
	}
}

bool WarningMessage::GetResult()
{
	return this->Result;
}