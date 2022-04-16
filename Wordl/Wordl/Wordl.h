#ifndef Wordl_H
#define Wordl_H
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "WordLib.h"

class Wordl
{
#define BACKGROUND(color, text) "\033[3;42;" << static_cast<int>(color) << "m" << text << "\033[0m"
#define ATTEMPTS 6
#define WORDLENGTH 5

public:
	Wordl();
	~Wordl(); // feedback: empty destructor
	void Start();

private:
	WordLib* lib;
	std::vector<std::string> guesses;

	bool Input(std::string&);

	enum class BackgroundColor : int
	{
		Red = 41,
		Green = 42,
		Yellow = 43,
		Grey = 100,
		BrightRed = 101,
		BrightGreen = 102,
		BrightYellow = 103
	};
};

#endif