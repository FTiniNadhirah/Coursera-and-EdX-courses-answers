#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include <vector>

class DisjointSet
{
public:
	DisjointSet() {}

	DisjointSet(int setNum): array(setNum, -1) {}

	// union 2 sets which contain x and y respectively.
	void unionSets(int x, int y);

	// find the representative element of set containing x
	int findSet(int x);

private:
	std::vector<int> array;
};

#endif // DISJOINT_SET_H
