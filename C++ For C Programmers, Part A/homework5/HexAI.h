#ifndef HEX_AI_H
#define HEX_AI_H

#include <utility>

#include "HexBoard.h"
#include "MonteCarlo.h"

class HexAI
{
public:
	virtual std::pair<int, int> getNextMove(HexBoard &board, Player player);
};

#endif // HEX_AI_H
