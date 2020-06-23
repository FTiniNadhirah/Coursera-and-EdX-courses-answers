#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <unordered_map>
#include <cassert>

#include "Data.h"

//the element of priority queue
struct QueueNode
{
	int symbol;
	int priority;

	QueueNode(int symbol=-1, int priority=INFINITY):
		symbol(symbol), priority(priority)
	{
	}
};

// an indexed priority queue implemented via minHeap
class PriorityQueue
{
public:
	PriorityQueue() {}

	PriorityQueue(const std::vector<int> &symbols);

	void changePriority(const QueueNode &node);

	// delete the top node
	void pop();

	inline bool contain(QueueNode &node);

	// if the node exists, return false, otherwise, return true
	bool insert(const QueueNode &node);

	// get the minimum node
	inline QueueNode& top();
	
	int size() const { return minHeap.size(); }

private:
	void minHeapfy();

	void downwards(int i);
	
	void upwards(int i);
	
	// swap corresponding nodes and indices
	inline void swap(int i, int j);

	std::vector<QueueNode> minHeap;

	// map from symbol to index in minHeap
	std::unordered_map<int, int> indices;
};

QueueNode& PriorityQueue::top()
{
	assert(size() > 0);

	return minHeap[0];
}

bool PriorityQueue::contain(QueueNode &node)
{
	if (indices.count(node.symbol) > 0)
	{
		node.priority = minHeap[indices[node.symbol]].priority;
		return true;
	}
	
	return false;
}

void PriorityQueue::swap(int i, int j)
{
	int symbol1 = minHeap[i].symbol;
	int symbol2 = minHeap[j].symbol;

	// swap nodes
	minHeap[i].symbol = symbol2;	
	minHeap[j].symbol = symbol1;
	int temp = minHeap[i].priority;
	minHeap[i].priority = minHeap[j].priority;
	minHeap[j].priority = temp;

	// swap indices
	indices[symbol1] = j;
	indices[symbol2] = i;
}

#endif //PRIORITY_QUEUE_H
