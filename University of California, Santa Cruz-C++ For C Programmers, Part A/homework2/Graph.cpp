#include <vector>
#include <cassert>
#include <ctime>
#include <cstdlib>

#include "Graph.h"

using namespace std;

Graph::Graph(int verticeNum): verticeNum(verticeNum)
{
	if (verticeNum <= 0)
	{
		this->verticeNum = 0;
		return;
	}

	adMatrix = vector<vector<int> >(verticeNum, vector<int>(verticeNum));
}

Graph::Graph(int verticeNum, double density):
	edgeNum(0), verticeNum(verticeNum)
{
	if (verticeNum <= 0)
	{
		this->verticeNum = 0;
		return;
	}

	adMatrix = vector<vector<int> >(verticeNum, vector<int>(verticeNum));

	srand(time(0));
	const int RANGE = 10;
	for (int i=0; i<verticeNum-1; i++)
	{
		for (int j=1; j<verticeNum; j++)
		{
			double prob = (rand() % 100) / 100.0;
			
			if (prob < density)
			{
				int value = rand() % RANGE + 1;
				addEdge(i, j, value);
			}
		}
	}
}

bool Graph::adjacent(int x, int y) const
{
	assert(x>=0 && x<verticeNum && y>=0 && y<verticeNum);

	return adMatrix[x][y] > 0;
}

vector<int> Graph::neighbors(int x) const
{
	assert(x>=0 && x<verticeNum);

	vector<int> list;
	for (int i=0; i<verticeNum; i++)
	{
		if (adMatrix[x][i] > 0)
		{
			list.push_back(i);
		}
	}

	return list;
}

vector<int> Graph::getVertices() const
{
	vector<int> vertices;

	for (int i=0; i<verticeNum; i++)
	{
		vertices.push_back(i);
	}

	return vertices;
}

bool Graph::addEdge(int x, int y, int value)
{
	assert(x>=0 && x<verticeNum && y>=0 && y<verticeNum);

	if (adMatrix[x][y] > 0)
		return false;

	adMatrix[x][y] = value;
	adMatrix[y][x] = value;

	return true;
}

bool Graph::deleteEdge(int x, int y)
{
	assert(x>=0 && x<verticeNum && y>=0 && y<verticeNum);

	if (adMatrix[x][y] > 0) 
	{
		adMatrix[x][y] = 0;
		adMatrix[y][x] = 0;
		return true;
	}

	return false;
}

int Graph::getEdgeValue(int x, int y) const
{
	assert(x>=0 && x<verticeNum && y>=0 && y<verticeNum);

	return adMatrix[x][y];
}

void Graph::setEdgeValue(int x, int y, int value)
{
	assert(x>=0 && x<verticeNum && y>=0 && y<verticeNum);

	adMatrix[x][y] = value;
	adMatrix[y][x] = value;
}
