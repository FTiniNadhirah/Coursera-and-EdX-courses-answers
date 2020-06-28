#include "HexAI.h"

#include <vector>
#include <utility>

using namespace std;

pair<int, int> HexAI::getNextMove(HexBoard &board, Player player)
{
	auto unoccupied = board.getUnoccupied();

	double maxProb = 0;
	pair<int, int> move = unoccupied[0];
	for (int i=0; i<unoccupied.size(); i++)
	{
		int x = unoccupied[i].first;
		int y = unoccupied[i].second;
		board.placePiece(x, y, player);

		double curProb = MonteCarlo::getScore(board, player);
		if (curProb > maxProb)
		{
			move = unoccupied[i];
			maxProb = curProb;
		}

		board.undo(x, y);
	}

	return move;
}
