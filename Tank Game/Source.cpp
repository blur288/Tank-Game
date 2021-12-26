#include <raylib.h>
#include <random>
#include <time.h>
#include "Board/Board.h"
#include "InputHandler.h"


int main()
{
	srand(time(0));

	InitWindow(1000, 500, "Tank Game");

	Board B;
	WarningMessage WM;

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		B.DrawBoard();

		WM.Display("Confirm Move?");

		//Send input
		Input::GetInput(B);

		EndDrawing();
	}

	CloseWindow();
}