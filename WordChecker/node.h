#pragma once
#include <vector>
#include <string>
#include <memory>

class Node
{
public:
	Node();

private:
	bool mEnd;
	std::vector<std::unique_ptr<Node>> m;
};

