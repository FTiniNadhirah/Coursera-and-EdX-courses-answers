#include <cassert>
#include <algorithm>

#include "ShortestPath.h"

using namespace std;

vector<int> ShortestPath::path(const Graph &graph, int u, int w)
{
	vector<int> route;

	if (dijkstra(graph, u, w) == INFINITY)
	{
		return route;
	}
	
	int cur = w;
	do
	{
		route.push_back(cur);
		cur = traces[cur];

	} while (cur != -1);

	reverse(route.begin(), route.end());

	return route;
}

int ShortestPath::pathSize(const Graph &graph, int u, int w)
{
	return dijkstra(graph, u, w);
}

int ShortestPath::dijkstra(const Graph &graph, int u, int w)
{
	int size = graph.getVerticeNum();
	assert(u>=0 && u<size && w>=0 && w<size);

	// initiate traces;
	traces.clear();
	traces.resize(size, -1);

	PriorityQueue pQueue(graph.getVertices());
	pQueue.changePriority(QueueNode(u, 0));

	while (pQueue.size() > 0)
	{
		QueueNode top = pQueue.top();
		pQueue.pop();

		if (top.priority == INFINITY)
		{
			return INFINITY;
		}

		if (top.symbol == w)
		{
			return top.priority;
		}

		// relax path
		auto neighbors = graph.neighbors(top.symbol);
		QueueNode node;
		for (int i=0; i<neighbors.size(); i++)
		{
			node.symbol = neighbors[i];
			if (pQueue.contain(node))
			{
				int edge = graph.getEdgeValue(top.symbol, node.symbol);
				if (edge + top.priority < node.priority)
				{
					traces[node.symbol] = top.symbol;
					node.priority = edge + top.priority;
					pQueue.changePriority(node);
				}
			}
		}
	}

	return INFINITY;
}
