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
	if (IsMouseButtonPressed(KEY_LEFT))
	{

	}
}

bool WarningMessage::GetResult()
{
	return this->Result;
}