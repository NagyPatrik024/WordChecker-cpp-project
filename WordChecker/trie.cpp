#include "trie.h"


Trie::Trie()
{
	mHead = std::shared_ptr<Node>(new Node());
}

void Trie::InsertWord(const std::string& word)
{
	auto pnode = mHead.get();
	for (const auto& item : word)
	{
		if (!pnode->mVector[(int(item) - 97)])
		{
			Node newnode = Node();
			pnode->mVector[int(item) - 97] = std::make_shared<Node>(newnode);
		}
		pnode = pnode->mVector[int(item) - 97].get();
	}
	pnode->mEnd = true;
}




