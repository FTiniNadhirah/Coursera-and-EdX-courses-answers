#include <iostream>
#include <fstream>
#include <vector>

#include "Graph.h"
#include "MinSpanTree.h"
#include "PrimMST.h"
#include "KruskalMST.h"

using namespace std;

void runMST(const Graph &graph, const MinSpanTree &mst)
{
	vector<EdgeNode> mstEdges;
	int cost = mst.generateMST(graph, mstEdges);

	cout << "Total cost of MST = " << cost << endl;
	cout << "MST's edges: " << endl;
	for (int i=0; i<mstEdges.size(); i++)
	{
		cout << "(" << mstEdges[i].x << "->" << mstEdges[i].y 
			 << ", cost=" << mstEdges[i].value << ") ";

		if ( (i + 1) % 5 == 0)
			cout << endl;
	}

	cout << endl;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "Usage: " << argv[0] << " test_data_file" << endl;
		return 1;
	}

	ifstream input(argv[1]);
	Graph graph(input);
	input.close();

	cout << "The results of Prim Algorithm" << endl;
	runMST(graph, PrimMST());

	cout << "The results of Kruskal Algorithm" << endl;
	runMST(graph, KruskalMST());

	return 0;
}
