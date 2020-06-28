#ifndef HEX_BOARD_H
#define HEX_BOARD_H

#include <vector>
#include <iostream>
#include <string>
#include <utility>

#include "Player.h"

class HexBoard
{
public:
	HexBoard() {}

	HexBoard(int size): 
		size(size), board(size, std::vector<char>(size, HexBoard::Blank)) 
	{
		// construct the connected edges
		connectedLine = "\\";
		for (int i=1; i<size; i++)
		{
			connectedLine += " / \\";
		}
	}

	// place a piece on the board, and if no conflicts, return ture
	bool placePiece(int x, int y, Player player);

	// retract a false move
	bool undo(int x, int y);

	// check whehter one player wins or not for the move at (x, y)
	bool win(int x, int y) const;

	// After finishing a Monte Carlo selection of moves (fill all blanks),
	// determine who wins.
	Player win() const;

	// get the Blank locations
	std::vector<std::pair<int, int> > getUnoccupied() const;

	int getBoardSize() const
	{
		return size;
	}

	// overload << operator
	friend std::ostream& operator<<(std::ostream&, const HexBoard&);

private:
	// Start breadth-first search from startNodes and set flags
	// if reach associated borders: N,S for RED, W,E for BLUE
	void BFS(const std::vector<std::pair<int, int> > &startNodes,
			std::vector<bool> &flags) const;

	// check whether (x,y) within board or not
	inline bool inBoard(int x, int y) const;

	// It's an auxiliary function for determining the winner.
	// Since a winner must reach two opposite sides, this function
	// is to check whether (x,y) at board's edges.
	// Flags is a 2-element vector which tracks whether reached
	// two borders for each player.
	inline void checkBorders(int x, int y, 
			std::vector<bool> &flags, char side) const;

	// six directions to find neighbors
	const static int dirs[6][2];

	// three states in hex board
	const static char Blue;
	const static char Red;
	const static char Blank;

	// the hex board's size
	int size;

	// the connected edges between two rows
	std::string connectedLine;

	// a 2-d matrice to store board content
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
