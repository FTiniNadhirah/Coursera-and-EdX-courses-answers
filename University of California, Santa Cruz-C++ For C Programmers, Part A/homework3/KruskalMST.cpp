#include "KruskalMST.h"
#include "DisjointSet.h"

#include <algorithm>

using namespace std;

bool cmp(const EdgeNode &a, const EdgeNode &b)
{
	return a.value < b.value;
}

int KruskalMST::generateMST(const Graph &graph, 
	vector<EdgeNode> &mstEdges) const
{
	int verticeNum = graph.getVerticeNum();
	vector<EdgeNode> edges;
	for (int i=0; i<verticeNum-1; i++)
	{
		for (int j=i+1; j<verticeNum; j++)
		{
			if (graph.adjacent(i, j))
			{
				edges.push_back(EdgeNode(i, j, graph.getEdgeValue(i,j)));
			}
		}
	}

	sort(edges.begin(), edges.end(), cmp);
	DisjointSet sets(verticeNum);
	int n = 0;
	int totalCost = 0;
	while (mstEdges.size() != verticeNum-1 && n < edges.size())
	{
		int setX = sets.findSet(edges[n].x);
		int setY = sets.findSet(edges[n].y);
		if (setX != setY)
		{
			totalCost += edges[n].value;
			mstEdges.push_back(edges[n]);
			sets.unionSets(setX, setY);
		}

		n++;
	}

	return totalCost;
}
