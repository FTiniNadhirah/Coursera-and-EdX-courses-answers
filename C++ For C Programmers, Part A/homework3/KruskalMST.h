#ifndef KRUSKAL_MST_H
#define KRUSKAL_MST_H

#include "MinSpanTree.h"

#include <vector>

class KruskalMST: public MinSpanTree
{
public:
	int generateMST(const Graph&, std::vector<EdgeNode>&) const;
};

#endif // KRUSKAL_MST_H
