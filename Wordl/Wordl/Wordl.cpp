#include "Wordl.h"

Wordl::Wordl()
{
	lib = new WordLib();
	guesses = std::vector<std::string>();
}

Wordl::~Wordl()
{

}

bool Wordl::Input(std::string& output)
{
	if (std::cin >> output)
	{
		std::for_each(output.begin(), output.end(), [](char& c)
			{
				c = ::toupper(c);
			});
		return true;
	}
	else
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "cin borked, resetting" << std::endl;
	}
	return false;
}

void Wordl::Start()
{
	using namespace std;

	bool playing = true;

	cout << "Welcome to the Wordl-look-alike assignment. Try to guess the word within the try limit" << endl;
	while (playing)
	{
		bool guessing{ true };
		int tries{ 0 };
		guesses.clear();
		string guess{ "" };
		string word{ lib->NewWord() };

		while (guessing && ((ATTEMPTS - tries) > 0))
		{
			cout << endl;
			for (string each : guesses)
				cout << each << endl;

			cout << endl << "Guesses remaining: " << 6 - tries << "/6" << endl;

			if (Input(guess))
			{
				if(guess.length() == WORDLENGTH)
				{
					if (lib->Contains(guess))
					{
						string output{ "" };
						stringstream ss{};
						for (unsigned int c = 0; c < guess.size(); c++)
						{
							if (guess[c] == word[c])
							{
								ss << BACKGROUND(BackgroundColor::Green, guess[c]);
							}
							else if (word.find(guess[c]) != string::npos)
							{
								ss << BACKGROUND(BackgroundColor::Yellow, guess[c]);
							}
							else
							{
								ss << BACKGROUND(BackgroundColor::Grey, guess[c]);
							}
						}
						guesses.push_back(ss.str());
						tries++;

						if (!guess.compare(word))
							guessing = false;
					}
					else
						cout << "Invalid word, doesn't exist in the list. Try again" << endl;
				}
				else
					cout << "Invalid length of word, five letters please" << endl;
			}
		}

		cout << endl;
		for (string each : guesses)
			cout << each << endl;

		if (!guess.compare(word))
			cout << "Congratulations, you found the right word in only " << tries << " attempts. Play again? y/n" << endl;
		else
			cout << "Sorry, you ran out of attempts. The word was: " << word << ". Play again ? y / n" << endl;

		while (true)
		{
			if (Input(guess))
				if (!guess.compare("N"))
				{
					playing = false;
					break;
				}
				else if (!guess.compare("Y"))
				{
					guessing = true;
					break;
				}
				else
					cout << "Invalid choice: y / n" << endl;
		}
	}
}