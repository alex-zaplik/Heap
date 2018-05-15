#pragma once

#include <map>
#include <functional>
#include <string>

#include "PriorityQueue.h"

class InputHandler
{
private:
	PriorityQueue * cont;
	std::map<std::string, std::function<std::string(std::string)> > func_map;

	void init();

	std::string ins(std::string key);
	std::string top(std::string key);
	std::string pop(std::string key);

	std::string empty(std::string key);
	std::string priority(std::string key);
	std::string print(std::string key);

public:
	InputHandler(PriorityQueue * cont);
	std::string handle_line(std::string line);
};

