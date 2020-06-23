#include "DisjointSet.h"

using namespace std;

void DisjointSet::unionSets(int x, int y)
{
	int setX = findSet(x);
	int setY = findSet(y);

	if (setX >= 0 && setY >= 0)
	{
		if (array[setX] <= array[setY])
		{
			array[setX] += array[setY];
			array[setY] = setX;
		}
		else
		{
			array[setY] += array[setX];
			array[setX] = setY;
		}
	}
}

int DisjointSet::findSet(int x)
{
	if (x < 0 || x >= array.size())
	{
		return -1;
	}

	vector<int> traces;
	while (array[x] >= 0)
	{
		traces.push_back(x);
		x = array[x];
	}

	// compress the path
	for (auto itr = traces.begin(); itr != traces.end(); ++itr)
	{
		array[*itr] = x;
	}

	return x;
}
