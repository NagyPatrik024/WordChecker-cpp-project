#include "trie.h"

void Trie::InsertWord(const std::string& word)
{
	Node pnode = Node();
	pnode = mHead;
	for (const auto& item : word)
	{
		if (Search(item, pnode))
		{
			InsertCharacter(item, pnode);
		}
	}
}

void Trie::InsertCharacter(const char& c, Node& node)
{

	if (!Search(c, node))
	{
		Node newnode = Node();
		newnode.mEnd = false;
		node.mVector[int(c) - 97] = std::make_shared<Node>(newnode);
	}
	node = *node.mVector[int(c) - 97];
}

bool Trie::Search(const char& c, Node& node)
{
	if (node.mVector[int(c) - 97])
	{
		node = *node.mVector[int(c) - 97];
		return true;
	}
	return false;
}



