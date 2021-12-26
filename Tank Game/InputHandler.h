#include "Board/Board.h"
#include <raylib.h>

class WarningMessage
{
public:
	void Display(std::string Message);

	bool GetResult();

private:
	bool Result;
	bool Show = 1;
};

namespace Input
{
	void GetInput(Board &board);
}