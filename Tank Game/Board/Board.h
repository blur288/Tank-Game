#pragma once
#include <vector>
#include "../Player/Player.h"

constexpr unsigned int YDim = 12;
constexpr unsigned int XDim = 20;

class Board
{
public:
	Board();

	std::vector<Player> Players;

	void DrawBoard();

	void ClickPlayer(uint8_t x, uint8_t y);
};

