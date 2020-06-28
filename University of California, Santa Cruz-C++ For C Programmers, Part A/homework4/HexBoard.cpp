#include "HexBoard.h"

#include <queue>
#include <utility>

using namespace std;

const int HexBoard::dirs[6][2] = 
{
	{-1, 0}, {-1, 1}, // top left, top right
	{0, -1}, {0, 1},  // left, right
	{1, -1}, {1, 0}   // buttom left, buttom right
};

bool HexBoard::placePiece(int x, int y , Player player)
{
	if (inBoard(x, y) == false)
		return false;

	if (board[x][y] != Blank)
		return false;

	if (player == Player::BLUE)
		board[x][y] = Blue;
	else if (player == Player::RED)
		board[x][y] = Red;

	return true;
}

bool HexBoard::undo(int x, int y)
{
	if (inBoard(x, y) == false)
		return false;

	board[x][y] = Blank;

	return true;
}

// check from the last move via BFS
bool HexBoard::win(int x, int y) const
{
	if (inBoard(x, y) == false || board[x][y] == Blank)
		return false;

	char side = board[x][y];
	vector<bool> flags(2, false);
	
	vector<vector<bool> > visited(size, vector<bool>(size));
	queue<pair<int, int> > traces;
	traces.push(make_pair(x, y));
	visited[x][y] = true;

	while (!traces.empty())
	{
		auto top = traces.front();
		checkBorders(top.first, top.second, flags, side);
		traces.pop();

		for (int n=0; n<6; n++)
		{
			int curX = top.first + dirs[n][0];
			int curY = top.second + dirs[n][1];
			if (inBoard(curX, curY) && board[curX][curY] == side
					&& visited[curX][curY] == false)
			{
				visited[curX][curY] = true;
				traces.push(make_pair(curX, curY));
			}
		}
	}

	return flags[0] && flags[1];
}

void HexBoard::printBoard(ostream &out) const
{
	if (size <= 0)
		return;

	// print the first line
	out << board[0][0];
	for (int j=1; j<size; j++)
		out << " - " << board[0][j];
	out << endl;

	string spaces = "";
	for (int i=1; i<size; i++)
	{
		spaces += ' ';
		out << spaces << connectedLine << endl;
		spaces += ' ';
		out << spaces << board[i][0];
		for (int j=1; j<size; j++)
			out << " - " << board[i][j];
		out << endl;
	}
}
