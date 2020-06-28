#ifndef HEX_BOARD_H
#define HEX_BOARD_H

#include <vector>
#include <iostream>
#include <string>

enum class Player { BLUE, RED };

class HexBoard
{
public:
	HexBoard() {}
	HexBoard(int size): 
		size(size), board(size, std::vector<char>(size, '.')) 
	{
		connectedLine = "\\";
		for (int i=1; i<size; i++)
		{
			connectedLine += " / \\";
		}
	}

	// place a piece on the board, and if no conflicts, return ture
	bool placePiece(int x, int y, Player player);

	// retact a false move
	bool undo(int x, int y);

	// check whehter one side win or not
	bool win(int x, int y) const;

	// print out the board
	void printBoard(std::ostream &out) const;

private:
	inline bool inBoard(int x, int y) const;
	inline void checkBorders(int x, int y, 
			std::vector<bool> &flags, char side) const;

	const static int dirs[6][2]; // six directions
	const static char Blue = 'B';
	const static char Red = 'R';
	const static char Blank = '.';
	int size;
	std::string connectedLine;
	std::vector<std::vector<char> > board;
};

bool HexBoard::inBoard(int x, int y) const
{
	return x>=0 && x<size && y>=0 && y<size;
}

void HexBoard::checkBorders(int x, int y, 
		std::vector<bool> &flags, char side) const
{
	if (side == Blue)
	{
		if (y == 0)
			flags[0] = true;
		if (y == size - 1)
			flags[1] = true;
	}
	else if (side == Red)
	{
		if (x == 0)
			flags[0] = true;
		if (x == size - 1)
			flags[1] = true;
	}
}

#endif // HEX_BOARD_H
