#include "Wordl.h"

Wordl::Wordl()
{
	lib = new WordLib(); // feedback: could not find where this is being deleted. Seems like a memory leak as well.
	guesses = std::vector<std::string>(); // feedback: you don't really need to explicitly call a constructor like this. The class member
											// will be default-created when possible if it is a value-type memeber(not a pointer or ref)
}

Wordl::~Wordl()
{

}

bool Wordl::Input(std::string& output)
{
	if (std::cin >> output)
	{
		for(char& each : output)
				each = toupper(each);

		for (char each : output) // feedback: style: inconsistent usage or reference and value type in the loop here and above. I'd stick to ref
			if (each < 'A' || each > 'Z')
			{
				std::cout << "Contains non-alpha characters" << std::endl;
				return false;
			}

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
		bool inGame{ true };
		int tries{ 0 };
		guesses.clear();
		string input{ "" };
		string word{ lib->NewWord() };

		while (inGame && ((ATTEMPTS - tries) > 0))
		{
			cout << endl;
			for (string each : guesses)
				cout << each << endl;

			cout << endl << "Guesses remaining: " << 6 - tries << "/6" << endl;

			if (Input(input))
			{
				if(input.length() == WORDLENGTH)
				{
					if (lib->Contains(input))
					{
						string output{ "" };
						stringstream ss{};
						for (unsigned int c = 0; c < input.size(); c++)
						{
							if (input[c] == word[c])
							{
								ss << BACKGROUND(BackgroundColor::Green, input[c]);
							}
							else if (word.find(input[c]) != string::npos)
							{
								ss << BACKGROUND(BackgroundColor::Yellow, input[c]);
							}
							else
							{
								ss << BACKGROUND(BackgroundColor::Grey, input[c]);
							}
						}
						guesses.push_back(ss.str());
						tries++;

						if (!input.compare(word))
							inGame = false;
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

		if (!input.compare(word))
			cout << "Congratulations, you found the right word in only " << tries << " attempts. Play again? y/n" << endl;
		else
			cout << "Sorry, you ran out of attempts. The word was: " << word << ". Play again ? y / n" << endl;

		while (true)
		{
			if (Input(input))
				if (!input.compare("N"))
				{
					playing = false;
					break;
				}
				else if (!input.compare("Y"))
				{
					inGame = true;
					break;
				}
				else
					cout << "Invalid choice: y / n" << endl;
		}
	}
}