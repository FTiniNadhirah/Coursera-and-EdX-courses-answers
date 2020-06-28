#include "HexBoard.h"

#include <queue>

using namespace std;

const char HexBoard::Blue = 'B';
const char HexBoard::Red = 'R';
const char HexBoard::Blank = '.';

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

vector<pair<int, int> > HexBoard::getUnoccupied() const
{
	vector<pair<int, int> > unoccupied;

	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
		{
			if (board[i][j] == Blank)
				unoccupied.push_back(make_pair(i, j));
		}
	}

	return unoccupied;
}

// Start BFS from the last move at (x, y), if reached
// two-opposited borders, then return true.
bool HexBoard::win(int x, int y) const
{
	if (inBoard(x, y) == false || board[x][y] == Blank)
		return false;

	char side = board[x][y];
	vector<bool> flags(2, false); // indicate whether reached two borders
	vector<pair<int, int> > startNodes(1, make_pair(x, y));

	BFS(startNodes, flags);

	return flags[0] && flags[1];
}

// After Monte Carlo selection, only one side wins.
// So I just check BLUE wins or not, starting BFS
// from west-border nodes. If it reached east border,
// then BLUE wins, otherwise RED wins.
Player HexBoard::win() const
{
	vector<bool> flags(2, false); // indicate whether reached two borders
	vector<pair<int, int> > startNodes;
	for (int i=0; i<size; i++)
	{
		if (board[i][0] == Blue)
			startNodes.push_back(make_pair(i, 0));
	}

	BFS(startNodes, flags);

	return (flags[0] && flags[1]) ? Player::BLUE : Player::RED;
}

void HexBoard::BFS(const vector<pair<int, int> > &startNodes, 
	vector<bool> &flags) const
{
	if (startNodes.size() == 0)
		return;

	int x = startNodes[0].first;
	int y = startNodes[0].second;
	char side = board[x][y]; // side = B or R
	
	vector<vector<bool> > visited(size, vector<bool>(size));
	queue<pair<int, int> > traces;

	for (auto itr = startNodes.cbegin(); itr != startNodes.cend(); ++itr)
	{
		traces.push(*itr);
		visited[itr->first][itr->second] = true;
	}

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
}

ostream& operator<<(ostream &out, const HexBoard &rhs)
{
	out << "***Hex Board***" << endl;
	int size = rhs.size;
	if (size <= 0)
		return out;

	// print the north border
	out << "  0";
	for (int j=1; j<size; j++)
		out << " r " << j;
	out << endl;

	// print the first line
	out << "0 " << rhs.board[0][0];
	for (int j=1; j<size; j++)
		out << " - " << rhs.board[0][j];
	out << endl;

	string spaces = "";
	for (int i=1; i<size; i++)
	{
		spaces += ' ';
		out << spaces << "b " << rhs.connectedLine << endl;
		if (i < 10)
		{
			spaces += ' ';
			out << spaces << i << ' ' << rhs.board[i][0];
		}
		else
		{
			out << spaces << i << ' ' << rhs.board[i][0];
			spaces += ' ';
		}

		for (int j=1; j<size; j++)
			out << " - " << rhs.board[i][j];
		out << endl;
	}

	return out;
}
