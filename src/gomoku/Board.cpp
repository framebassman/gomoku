#include "Board.h"

Board::Board()
{
	for (size_t i = 0; i < FIELD_SIZE; ++i)
	{
		for (int j = 0; j < FIELD_SIZE; ++j)
		{
			b[i][j] = 0;
		}
	}
}

Board::~Board()
{
}

bool Board::makeMove(int x, int y, Sign sign)
{
	if (getCell(x, y) == Sign::Free)
	{
		if (sign == Sign::White)
			b[x][y] = 1;
		else if (sign == Sign::Black)
			b[x][y] = 2;

		return true;
	}

	return false;
}

int Board::getSize()
{
	return FIELD_SIZE;
}

Turn Board::isWin()
{
	return Continue;
}

Sign Board::getCell(int x, int y) const
{
	if (b[x][y] == 1)
		return Sign::White;
	if (b[x][y] == 2)
		return Sign::Black;

	return Sign::Free;
}