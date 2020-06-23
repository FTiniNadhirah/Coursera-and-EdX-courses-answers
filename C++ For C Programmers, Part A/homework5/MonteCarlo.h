#ifndef MONTE_CARLO_H
#define MONTE_CARLO_H

#include "HexBoard.h"
#include "Player.h"

class MonteCarlo
{
public:
	// get MonteCarlo score
	static double getScore(HexBoard &board, Player player);

private:
	// generate a increased permutation
	// e.g n = 5, return a permutation, say, 0,1,2,3,4 
	static std::vector<int> generatePermutation(int n);

	// adapt the order of input permutation to make it in
	// random order.
	static void adaptPermutation(std::vector<int> &perm);

	const static int TrialNum;
};

#endif // MONTE_CARLO_H
