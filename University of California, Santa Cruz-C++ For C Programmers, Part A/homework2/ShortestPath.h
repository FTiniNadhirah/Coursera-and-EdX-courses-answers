#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#include <vector>
#include "Data.h"
#include "Graph.h"
#include "PriorityQueue.h"

// implement Dijkstra algorithm
class ShortestPath
{
public:
	// find the shortest path from u to w
	std::vector<int> path(const Graph &graph, int u, int w);

	// return the path cost associated with the shortest path
	int pathSize(const Graph &graph, int u, int w);

private:
	int dijkstra(const Graph &graph, int u, int w);

	// In order to construct the shorest path, store
	// each node's previous node
	std::vector<int> traces;
};

#endif // SHORTEST_PATH_H
