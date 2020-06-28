#ifndef PRIM_MST_H
#define PRIM_MST_H

#include "MinSpanTree.h"

class PrimMST: public MinSpanTree
{
public:
	int generateMST(const Graph&, std::vector<EdgeNode>&) const;
};

#endif // PRIM_MST_H
