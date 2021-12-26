#pragma once
#include <cstdint>
#include <random>
class Player
{
public:
	//Position on board
	uint8_t X = 0, Y = 0;
	uint8_t ActionPoints = 0;
	uint8_t HealthPoints = 0;
	std::string Name = "Sample Test";
	bool IsClicked = 0;

	Player();
};

