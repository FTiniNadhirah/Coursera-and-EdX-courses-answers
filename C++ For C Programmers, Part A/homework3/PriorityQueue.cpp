#include "PriorityQueue.h"

using namespace std;

PriorityQueue::PriorityQueue(const vector<int> &symbols)
{
	for (int i=0; i<symbols.size(); i++) 
	{
		if (indices.count(symbols[i]) == 0)
		{
			minHeap.push_back(QueueNode(symbols[i]));
			indices[symbols[i]] = i;
		}
	}

	minHeapfy();
}

void PriorityQueue::changePriority(const QueueNode &node)
{
	// if the node does not exist, return false;
	if (indices.count(node.symbol) == 0)
	{
		return;
	}

	int index = indices[node.symbol];
	if (minHeap[index].priority < node.priority)
	{
		minHeap[index].priority = node.priority;
		downwards(index);
	}
	else if (minHeap[index].priority > node.priority)
	{
		minHeap[index].priority = node.priority;
		upwards(index);
	}
}

void PriorityQueue::pop()
{
	if (size() <= 1)
	{
		minHeap.clear();
		indices.clear();
		return;
	}

	int topSymbol = minHeap[0].symbol;

	// swap the last node to the fisrt place
	swap(0, size()-1);

	// delete the top node
	minHeap.pop_back();
	indices.erase(topSymbol);

	// downheapfy
	downwards(0);
}

bool PriorityQueue::insert(const QueueNode &node)
{
	// if the node exists, return false;
	if (indices.count(node.symbol) > 0)
	{
		return false;
	}

	minHeap.push_back(node);

	int index = size() - 1;
	indices[node.symbol] = index;
	upwards(index);

	return true;
}

void PriorityQueue::minHeapfy()
{
	// nodes which have children need downwards heapfy
	int start = (size() - 2) / 2;

	for (int i=start; i>=0; i--)
	{
		downwards(i);
	}
}

void PriorityQueue::upwards(int i)
{
	if (i <= 0)
		return;

	int parent = (i - 1) / 2;

	if (minHeap[parent].priority > minHeap[i].priority)
	{
		swap(parent, i);
		upwards(parent);
	}
}

void PriorityQueue::downwards(int i)
{
	int left = i * 2 + 1;
	int right = i * 2 + 2;

	if (right < size())
	{
		if (minHeap[i].priority <= minHeap[left].priority &&
				minHeap[i].priority <= minHeap[right].priority)
		{
			return;
		}

		int smaller = 
			minHeap[left].priority<minHeap[right].priority ? left : right;

		swap(i, smaller);
		downwards(smaller);
	}
	else if (left < size())
	{
		if (minHeap[i].priority <= minHeap[left].priority)
		{
			return;
		}

		swap(i, left);
		downwards(left);
	}
}
