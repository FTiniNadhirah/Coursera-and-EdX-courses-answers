#include "HexGame.h"

#include <iostream>
#include <string>

using namespace std;

void HexGame::playGame()
{
	while (true)
	{
		initGame();
		choosePlayer();

		cout << "Game starting ..." << endl << endl;
		int size = board.getBoardSize();
		bool terminal = false;
		/*if (robot == Player::BLUE)
		{
			cout << "Robot's turn: " << endl;
			board.placePiece(size/2, size/2, robot);
			terminal = board.win(size/2, size/2);
			cout << board;
		}*/

		int turn = (robot == Player::BLUE ? 0 : 1);
		while (terminal == false)
		{
			turn = !turn;
			if (turn)
			{
				terminal = robotTurn();
			}
			else
			{
				terminal = humanTurn();
			}
		}

		if (turn == 1)
			cout << "Robot wins!!!" << endl;
		else
			cout << "You win! Congratulations." << endl;

		cout << "Do you want a new game (y/n)? ";
		char flag;
		cin >> flag;
		if (flag != 'y' && flag != 'Y')
			break;
		cin.clear();
	}

	cout << "Thank you for playing HEX GAME! Bye-bye." << endl;
}

void HexGame::initGame()
{
	string guard(30, '*');
	cout << '\n' << guard << endl;
	cout << "*  Welcome to the HEX world  *" << endl;
	cout << guard << endl << endl;

	int boardSize;
	while (true)
	{
		cout << "Please choose the HexBoard size: ";
		cin >> boardSize;
		if (boardSize > 0)
			break;
		
		cout << "The HexBoard size should be positive." << endl;
		cin.clear();
	}

	board = HexBoard(boardSize);
	cout << "The HexBoard has been set up." << endl;
	cout << board;
}

void HexGame::choosePlayer()
{
	char side = '.';
	while (true)
	{
		cout << "Please choose your side (B/R): ";
		cin >> side;
		if (side == 'b' || side == 'B')
		{
			human = Player::BLUE;
			robot = Player::RED;
			break;
		}
		else if (side == 'r' || side == 'R')
		{
			human = Player::RED;
			robot = Player::BLUE;
			break;
		}

		cout << "Illegal side!" << endl;
		cin.clear();
	}
}

bool HexGame::robotTurn()
{
	cout << "Robot's turn: ";
	auto move = hexAI.getNextMove(board, robot);
	board.placePiece(move.first, move.second, robot);
	cout << move.first << " " << move.second << endl;
	cout << board;

	return board.win(move.first, move.second);
}

bool HexGame::humanTurn()
{
	int x, y;
	cout << "Your turn: " << endl;
	while (true)
	{
		cout << "Input your move: x y = ";
		cin >> x >> y;
		if (board.placePiece(x, y, human))
			break;

		cout << "Illegal move!" << endl;
	}

	cout << board;

	return board.win(x, y);
}
