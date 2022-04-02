#include "trie.h"
#include <iostream>
#include <conio.h>
#include <string>

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

char to_lowercase(char c)
{
	if (c >= 'A' && c <= 'Z') {
		return c + 32;
	}

	return c;
}

bool Trie::WordChecker(const std::string& word) const
{
	std::string word2 = word;
	for (char& c : word2) {
		c = to_lowercase(c);
	}

	auto pnode = mHead.get();
	for (const auto& item : word2)
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


void Trie::Start(const std::string fileName)
{
	std::ifstream inputFile(fileName);
	while (!inputFile.eof())
	{
		std::string line;
		std::getline(inputFile, line);
		this->InsertWord(line);
	}

	std::string line;
	std::cout << "Write a sentence" << std::endl;
	std::getline(std::cin, line);

	auto pos = line.find(' ');
	if (pos != std::string::npos)
	{
		do {
			const auto word = line.substr(0, pos);
			if (!this->WordChecker(word))
			{
				std::cout << "Incorrect word! --> " << word << std::endl;
			}
			else
			{
				std::cout << "Correct word! --> " << word << std::endl;
			}
			line = line.substr(pos + 1);
			pos = line.find(' ');
		} while (pos != std::string::npos);
	}
	if (!this->WordChecker(line))
	{
		std::cout << "Incorrect word! --> " << line << std::endl;
	}
	else
	{
		std::cout << "Correct word! --> " << line << std::endl;
	}
}






