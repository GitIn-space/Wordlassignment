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
	file.open("../words.txt"); //feedback: file reading is an expensive operation. Considering you read the file once in the constructor of this class
								// I'd prefer to see storing of the file contents in memory and not reading the file again when you need a particular line.

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