#pragma once
#include <vector>
#include <memory>
#include <string>

struct Node {
	Node() : mEnd(false) {}


	bool mEnd;
	std::vector<std::shared_ptr<Node>> mVector = std::vector<std::shared_ptr<Node>>();
};

class Trie
{
public:
	void InsertWord(const std::string& word);



private:
	void InsertCharacter(const char& character, Node& node);
	bool Search(const char& c, Node& node);
	Node mHead = Node();
};

