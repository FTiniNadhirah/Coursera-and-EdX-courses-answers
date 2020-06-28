#include "PrimMST.h"
#include "PriorityQueue.h"

using namespace std;

int PrimMST::generateMST(const Graph &graph, vector<EdgeNode> &mstEdges) const
{
	vector<int> prevs(graph.getVerticeNum(), -1);
	PriorityQueue pq(graph.getVertices());
	QueueNode qNode(0, 0);
	pq.changePriority(qNode);

	int totalCost = 0;
	while (pq.size() > 0)
	{
		QueueNode top = pq.top();
		pq.pop();
		int curVertice = top.symbol;
		int curCost = top.priority;
		if (prevs[curVertice] != -1)
		{
			totalCost += curCost;
			mstEdges.push_back(
					EdgeNode(prevs[curVertice], curVertice, curCost));
		}

		// relax edges
		vector<int> neighbors = graph.neighbors(curVertice);
		for (int i=0; i<neighbors.size(); i++)
		{
			int v = neighbors[i];
			qNode.symbol = v;
			if (pq.contain(qNode))
			{
				int cost = graph.getEdgeValue(curVertice, v);
				if (qNode.priority > cost)
				{
					qNode.priority = cost;
					pq.changePriority(qNode);
					prevs[v] = curVertice; // update previous vertices
				}
			}
		}
	}

	return totalCost;
}
