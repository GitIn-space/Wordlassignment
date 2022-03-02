#ifndef WORDLIB_H
#define WORDLIB_H

#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "Trie.h"

class WordLib
{
public:
	WordLib();
	~WordLib();
	bool Contains(std::string word);
	std::string NewWord();

private:
	Trie* storage;
	int count;
};

#endif