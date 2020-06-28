#include "MonteCarlo.h"

#include <ctime>
#include <cstdlib>
#include <vector>
#include <utility>

using namespace std;

const int MonteCarlo::TrialNum = 1000;

double MonteCarlo::getScore(HexBoard &board, Player player)
{
	auto unoccupied = board.getUnoccupied();
	auto perm = generatePermutation(unoccupied.size());

	int count = 0; // count the player's winning times
	for (int n=0; n<TrialNum; n++)
	{
		int turn = (player == Player::BLUE ? 0 : 1);
		adaptPermutation(perm);
		for (int i=0; i<perm.size(); i++)
		{
			turn = !turn;
			int x = unoccupied[perm[i]].first;
			int y = unoccupied[perm[i]].second;
			if (turn) // RED's turn
			{
				board.placePiece(x, y, Player::RED);
			}
			else      // BLUE's turn
			{
				board.placePiece(x, y, Player::BLUE);
			}
		}

		if (board.win() == player)
			count++;

		// retract random moves
		for (auto itr = unoccupied.begin(); itr != unoccupied.end(); ++itr)
		{
			board.undo(itr->first, itr->second);
		}
	}

	return static_cast<double>(count) / TrialNum;
}

vector<int> MonteCarlo::generatePermutation(int n)
{
	vector<int> perm(n);

	for (int i=0; i<n; i++)
		perm[i] = i;

	return perm;
}

void MonteCarlo::adaptPermutation(vector<int> &perm)
{
	for (int i=perm.size(); i>1; i--)
	{
		int choose = rand() % i;
		int temp = perm[i-1];
		perm[i-1] = perm[choose];
		perm[choose] = temp;
	}
}
