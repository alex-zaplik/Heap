#include "InputHandler.h"

#include <sstream>

InputHandler::InputHandler(PriorityQueue* cont) : cont{ cont }
{
	init();
}

void InputHandler::init()
{
	std::vector<std::string> commands;

	commands.push_back("insert");
	commands.push_back("top");
	commands.push_back("pop");

	commands.push_back("empty");
	commands.push_back("priority");
	commands.push_back("print");

	this->func_map["insert"] = [=](std::string key) { return this->ins(key); };
	this->func_map["top"] = [=](std::string key) { return this->top(key); };
	this->func_map["pop"] = [=](std::string key) { return this->pop(key); };

	this->func_map["empty"] = [=](std::string key) { return this->empty(key); };
	this->func_map["priority"] = [=](std::string key) { return this->priority(key); };
	this->func_map["print"] = [=](std::string key) { return this->print(key); };
}

std::string InputHandler::handle_line(std::string line)
{
	std::string command;
	std::string parameter;

	size_t pos = line.find(' ');
	size_t offset = 0;
	command = line.substr(0, pos);
	parameter = line.substr(pos + 1, line.size() - pos - 1);

	auto it = func_map.find(command);

	if (it != func_map.end())
	{
		return func_map[command](parameter);
	}
	return "Unknown command";
}

std::string InputHandler::ins(std::string key)
{
	std::stringstream ss(key);
	int x;
	unsigned int p;
	ss >> x >> p;
	cont->insert(x, p);
	return "";
}

std::string InputHandler::top(std::string key)
{
	if (cont->empty())
	{
		return " ";
	}

	return std::to_string(cont->top());
}

std::string InputHandler::pop(std::string key)
{
	if (cont->empty())
	{
		return " ";
	}

	return std::to_string(cont->pop());
}

std::string InputHandler::empty(std::string key)
{
	if (cont->empty())
	{
		return "1";
	}
	else
	{
		return "0";
	}
}

std::string InputHandler::priority(std::string key)
{
	std::stringstream ss(key);
	int x;
	unsigned int p;
	ss >> x >> p;
	cont->priority(x, p);
	return "";
}

std::string InputHandler::print(std::string key)
{
	return cont->to_string();
}
