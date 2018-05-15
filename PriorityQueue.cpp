#include "PriorityQueue.h"

#include <sstream>

PriorityQueue::PriorityQueue()
{
	heap_size = 0;
}

PriorityQueue::~PriorityQueue()
{
}

bool PriorityQueue::find_next(unsigned int start, int x, unsigned int &i)
{
	for (i = start; i < heap_size; i++)
	{
		if (queue[i].val == x)
		{
			return true;
		}
	}

	return false;
}

void PriorityQueue::heapify(unsigned int i)
{
	unsigned int l = LEFT(i);
	unsigned int r = RIGHT(i);
	unsigned int largest;

	if (l < heap_size && queue[l].p < queue[i].p)
	{
		largest = l;
	}
	else
	{
		largest = i;
	}

	if (r < heap_size && queue[r].p < queue[largest].p)
	{
		largest = r;
	}

	if (largest != i)
	{
		std::swap(queue[i], queue[largest]);
		heapify(largest);
	}
}

void PriorityQueue::insert(int x, unsigned int p)
{
	Element e(x, std::numeric_limits<unsigned int>::max());
	heap_size++;

	if (heap_size > queue.size())
	{
		queue.resize(heap_size);
	}
	queue[heap_size - 1] = e;

	priority(heap_size - 1, p);
}

bool PriorityQueue::empty()
{
	return heap_size == 0;
}

int PriorityQueue::top()
{
	return queue[0].val;
}

int PriorityQueue::pop()
{
	if (heap_size < 1)
	{
		// TODO: Exception
		return 0;
	}

	Element max = queue[0];
	queue[0] = queue[heap_size - 1];
	heap_size--;
	heapify(0);

	return max.val;
}

void PriorityQueue::priority(unsigned int i, unsigned int p)
{
	if (p > queue[i].p)
	{
		return;
	}

	queue[i].p = p;
	while (i > 0 && queue[PARENT(i)].p > queue[i].p)
	{
		std::swap(queue[i], queue[PARENT(i)]);
		i = PARENT(i);
	}
}

void PriorityQueue::priority(int x, unsigned int p)
{
	unsigned int i = 0;
	while (find_next(i, x, i))
	{
		Element before = queue[i];
		priority(i, p);
		if (queue[i].val == before.val && queue[i].p == before.p) i++;
	}
}

std::string PriorityQueue::to_string()
{
	std::stringstream ss;

	for (unsigned int i = 0; i < heap_size; i++)
	{
		ss << "(" << queue[i].val << ", " << queue[i].p << ") ";
	}

	return ss.str();
}
