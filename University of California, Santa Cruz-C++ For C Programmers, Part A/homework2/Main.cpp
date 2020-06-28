#include <iostream>
#include "Data.h"
#include "Graph.h"
#include "ShortestPath.h"

using namespace std;

int main()
{
	double densities[3] = {0.2, 0.4, 0.5};
	int verticeNum = 50;
	ShortestPath sp;

	for (int i=0; i<3; i++)
	{
		int sum = 0;
		int count = 0;
		Graph graph(verticeNum, densities[i]);

		for (int n=1; n<50; n++)
		{
			int pathSize = sp.pathSize(graph, 0, n);
			if (pathSize != INFINITY)
			{
				sum += pathSize;
				count++;
			}
		}

		cout << "For the graph with density = " << densities[i];
		cout << ", the average path length = " << 
			(static_cast<double>(sum) / count) << endl;
	}

	return 0;
}
