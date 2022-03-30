#include "trie.h"
#include <iostream>
#include <conio.h>

Trie::Trie()
{
	mHead = std::shared_ptr<Node>(new Node());
}

void Trie::InsertWord(const std::string& word)
{
	auto pnode = mHead.get();

	for (const auto& item : word)
	{
		if (int(item) >= 97 && int(item) <= 122)
		{
			if (!pnode->mVector[(int(item) - 97)].get())
			{
				Node newnode = Node();
				pnode->mVector[int(item) - 97] = std::make_shared<Node>(newnode);
			}
			pnode = pnode->mVector[int(item) - 97].get();
		}
	}
	if (word != "")
	{
		pnode->mEnd = true;
	}

}

bool Trie::WordChecker(const std::string& word) const
{
	auto pnode = mHead.get();
	for (const auto& item : word)
	{
		if (int(item) >= 97 && int(item) <= 122)
		{
			if (!pnode->mVector[(int(item) - 97)])
			{
				return false;
			}
			pnode = pnode->mVector[int(item) - 97].get();
		}
	}
	if (pnode->mEnd)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Trie::Start(std::string fileName)
{
	std::ifstream inputFile(fileName);

	while (!inputFile.eof())
	{
		std::string line;
		std::getline(inputFile, line);
		this->InsertWord(line);
	}

	std::string line = "";
	std::cout << "Write 0 to exit" << std::endl;
	while (line != "0")
	{
		std::cin >> line;
		if (line != "0")
		{
			if (this->WordChecker(line))
			{
				std::cout << "Correct word!" << std::endl;
			}
			else
			{
				std::cout << "Incorrect word!" << std::endl;
			}
		}
	}
}






