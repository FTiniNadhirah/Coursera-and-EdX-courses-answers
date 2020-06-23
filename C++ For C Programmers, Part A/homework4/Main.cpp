#include <iostream>
#include <ctime>
#include <cstdlib>
#include "HexBoard.h"

using namespace std;

int main()
{
	const int SIZE = 11;
	HexBoard board(SIZE);
	cout << "Initialize Hex board" << endl;
	board.printBoard(cout);

	int turn = 0;
	int steps = 0;
	int x, y;
	srand(time(0));
	while (true)
	{
		steps++;
		turn = !turn;
		if (turn == 1)
		{
			do
			{
				x = rand() % SIZE;
				y = rand() % SIZE;
			}while (!board.placePiece(x, y, Player::BLUE));

			cout << "Player Blue: " << x << ", " << y << endl;
		}
		else
		{
			do
			{
				x = rand() % SIZE;
				y = rand() % SIZE;
			}while (!board.placePiece(x, y, Player::RED));

			cout << "Player Red: " << x << ", " << y << endl;
		}

		if (board.win(x, y))
		{
			cout << (turn ? "Blue" : "Red") << " win" << endl;
			cout << "Total steps = " << steps << endl;
			board.printBoard(cout);
			break;
		}
	}

	return 0;
}
