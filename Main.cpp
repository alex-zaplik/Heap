#include <iostream>

#include "PriorityQueue.h"
#include "InputHandler.h"

int main()
{
	PriorityQueue* cont = new PriorityQueue;
	InputHandler ih(cont);

	int T;
	std::cin >> T;
	std::cin.get();

	std::string line;
	for (int i = 0; i < T; ++i)
	{
		std::getline(std::cin, line);
		line = ih.handle_line(line);

		if (line.size() != 0) std::cout << line << std::endl;
	}

	return 0;
}