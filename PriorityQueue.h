#pragma once

#include <string>
#include <vector>

#define PARENT(i) ((i + 1) / 2 - 1)
#define LEFT(i) (2 * (i + 1) - 1)
#define RIGHT(i) (2 * (i + 1))

struct Element
{
	int val;
	unsigned int p;

	Element() : val{ 0 }, p{ std::numeric_limits<unsigned int>::max() } {}
	Element(int val, unsigned int p) : val{ val }, p{ p } {}
};

class PriorityQueue
{
private:
	std::vector<Element> queue;
	unsigned int heap_size;

	bool find_next(unsigned int start, int x, unsigned int &i);
	void heapify(unsigned int i);
	void priority(unsigned int i, unsigned int p);

public:
	PriorityQueue();
	~PriorityQueue();

	void insert(int x, unsigned int p);
	bool empty();
	int top();
	int pop();
	void priority(int x, unsigned int p);
	std::string to_string();
};

