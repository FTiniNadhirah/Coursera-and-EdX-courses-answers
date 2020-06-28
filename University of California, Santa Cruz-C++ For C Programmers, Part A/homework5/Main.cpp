#include "HexGame.h"

using namespace std;

int main()
{
	HexAI hexAI;
	HexGame hexGame(hexAI);
	srand(time(0)); // set the rand seed.

	hexGame.playGame();

	return 0;
}
