#ifndef HEX_GAME_H
#define HEX_GAME_H

#include "HexBoard.h"
#include "HexAI.h"

class HexGame
{
public:
	HexGame() {}
	HexGame(const HexAI &hexAI): hexAI(hexAI) {}

	// start playing HEX GAME
	void playGame();

private:
	// initialize the hex board size
	void initGame();

	// the player choose side
	void choosePlayer();

	// if robot or human wins, return true;
	bool robotTurn();
	bool humanTurn();

	Player robot;
	Player human;
	HexAI hexAI;
	HexBoard board;
};

#endif // HEX_GAME_H
