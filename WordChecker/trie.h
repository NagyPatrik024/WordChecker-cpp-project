#pragma once
#include <vector>
#include <memory>
#include <string>


struct Node {
	Node() {}
	Node(bool mEnd) : mEnd(mEnd) {}


	bool mEnd = false;
	std::vector<std::shared_ptr<Node>> mVector = std::vector< std::shared_ptr<Node>>(26);
};

class Trie
{
public:
	Trie();
	void InsertWord(const std::string& word);

private:
	std::shared_ptr<Node> mHead;
};

