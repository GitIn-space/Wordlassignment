#ifndef Wordl_H
#define Wordl_H
#include <iostream>
#include <vector>
#include "WordLib.h"

class Wordl
{
#define FOREGROUND(color, text) "\x1B[" << static_cast<int>(color) << "m" << text << "\033[0m"
#define BACKGROUND(color, text) "\033[3;42;" << static_cast<int>(color) << "m" << text << "\033[0m"

public:
	Wordl();
	~Wordl();
	void Start();

private:
	WordLib* lib;
	std::vector<std::string> guesses;

	enum class BackgroundColor : int
	{
		Red = 41,
		Green = 42,
		Yellow = 43,
		BrightRed = 101,
		BrightGreen = 102,
		BrightYellow = 103
	};
};

#endif