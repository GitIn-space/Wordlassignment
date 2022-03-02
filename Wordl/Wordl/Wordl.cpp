#include "Wordl.h"

Wordl::Wordl()
{
	lib = new WordLib();
	guesses = std::vector<std::string>();
}

Wordl::~Wordl()
{

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

		cout << endl << word << endl;

		while (guessing)
		{
			cout << endl;
			for (string each : guesses)
				cout << each << endl;

			cout << endl << "Guesses remaining: " << 6 - tries << "/6" << endl;

			if (cin >> guess)
			{
				if (lib->Contains(guess))
				{
					char* output{};
					for (int c = 0; c < guess.size(); c++)
					{
						if (toupper(guess[c]) == word[c])
							cout << BACKGROUND(BackgroundColor::Green, guess[c]);
						else if (word.find(toupper(guess[c])) != string::npos)
							cout << BACKGROUND(BackgroundColor::Yellow, guess[c]);
						else
							cout << guess[c];
					}
					cout << endl;
					tries++;
				}
				else
					cout << "Invalid word, doesn't exist in the list. Try again" << endl;
			}
			else
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "cin borked, resetting" << endl;
			}
		}
	}
}