#pragma once
#include <vector>
#include <fstream>
#include <memory>
#include <string>


struct Node {
	Node() : mEnd(false) {}

	bool mEnd;
	std::vector<std::shared_ptr<Node>> mVector = std::vector< std::shared_ptr<Node>>(26);
};

class Trie
{
public:
	Trie();
	void Start(const std::string fileName);
private:
	void InsertWord(const std::string& word);
	bool WordChecker(const std::string& word) const;
	std::shared_ptr<Node> mHead;
};

