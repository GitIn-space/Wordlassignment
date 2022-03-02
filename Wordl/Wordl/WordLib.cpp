#include "WordLib.h"

WordLib::WordLib()
{
	storage = new Trie();
	count = 0;

	std::ifstream file;
	file.open("../words.txt");

	std::string line{ "" };
	if (file.is_open())
		while (getline(file, line))
		{
			storage->Insert(line);
			count++;
		}
	file.close();
}

WordLib::~WordLib()
{

}

bool WordLib::Contains(std::string word)
{
	return storage->Contains(word);
}

std::string WordLib::NewWord()
{
	std::ifstream file;
	file.open("../words.txt");

	std::string line{ "" };
	int c{ 0 };
	srand(time(NULL));
	int r{ rand() % count};
	if (file.is_open())
		while (getline(file, line))
		{
			if (c == r)
				return line;
			c++;
		}
	file.close();
}