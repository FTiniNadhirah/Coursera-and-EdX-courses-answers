#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

// implement graph via adjacent matrix
class Graph
{
public:
	Graph() {}

	Graph(std::istream &input);

	Graph(int verticeNum);	

	Graph(int verticeNum, double density);

	int getVerticeNum() const { return verticeNum; }

	int getEdgeNum() const { return edgeNum; }
	
	// tests whether there is an edge from node x to node y
	bool adjacent(int x, int y) const;

	// lists all nodes y such that there is an edge from
	// x to y
	std::vector<int> neighbors(int x) const;

	// return all vertices in the graph
	std::vector<int> getVertices() const;

	bool addEdge(int x, int y, int value);

	bool deleteEdge(int x, int y);

	int getEdgeValue(int x, int y) const;

	void setEdgeValue(int x, int y, int value);

private:
	// To check whether the input verticeNum greater than 0 or not.
	bool checkVerticeNum();

	int edgeNum;
	int verticeNum;

	// if adMatrix[i][j] == 0, there is no edge between i and j.
	std::vector<std::vector<int> > adMatrix;
};

#endif //GRAPH_H
