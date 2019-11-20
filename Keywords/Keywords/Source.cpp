// In order to read or write to the standard input/output #include <iostream> is required
// The program won't complie unless it's added in other words
#include <iostream>
// Allows sting functions to acutally be understood by the program 
// If this wasn't added any string functions wouldn't work
#include <string>
// Declares a set of general purpose functions 
// Without this some of my functions wouldn't run
#include <cstdlib>
// finds the function "time" and from there it compiles and link so it functions
#include <ctime>

// Allows cout, cin, string, vector, map, etc. to be used and understood
using namespace std;

// Main is a function used to start a C++ Program 
int main()
{
	// Starts a loop for playing again
	bool playAgain = false; 
	do    
	{
		// If you play again 
		// It should display Welcome to Code Breaker Training Simulation!
		if (playAgain == true)
		{
			cout << "\t\t\tWelcome back to Code Breaker Training Simulation!\n\n";
		}
		// Else statment if you aren't playing again and this is your first time 
		// It should display Welcome to Code Breaker Training Simulation
		else
		{
			cout << "\t\t\tWelcome to Code Breaker Training Simulation!\n\n";
		}
		// Displays Text 
		cout << "Unscramble the letters to make the codeword.\n";
		cout << "This program is cap sensitive, make sure everything you type is lower case.";

		// An Intger to count your wins 
		int numberOfWins = 0;
		// This will actually count your wins
		for (int i = 0; i < 3; i++)
		{
			// enumerated feilds for word, clue and num_feilds
			enum fields { WORD, Clue, NUM_FIELDS };
			// This is to make sure the program is randomly choosing from how many words I have listed
			const int NUM_WORDS = 10;
			// constant string for words and feilds 
			const string WORDS[NUM_WORDS][NUM_FIELDS] =
			{
				// Words and Clues
				{"hurricane", "A large rotating storm with high speeds of wind."},
				{"ape", "A large primate."},
				{"mountain", "A landmass formed through tectonic forces or volcanism."},
				{"tiger", "A large mammal with stripes."},
				{"otter", "A member of the weasel family."},
				{"mongoose", "Small carnivorans native to southern Eurasia and mainland Africa."},
				{"wolf", "An endangered species."},
				{"ocean", "A large body of water."},
				{"emperor", "Genghis Khan was this."},
				{"pluto", "A dwarf planet."},
			};

			srand(static_cast<unsigned int>(time(0)));
			// integer for choice so it can choose the word
			int choice = (rand() % NUM_WORDS);
			// The program choices a the word
			string theWord = WORDS[choice][WORD]; 
			// While choosing a random word the clue is pulled with it
			string theClue = WORDS[choice][Clue]; 

			// Jumbling codeword
			string jumbledCodeWord = theWord;  
			int length = jumbledCodeWord.size();
			for (int i = 0; i < length; ++i)
			{
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = jumbledCodeWord[index1];
				jumbledCodeWord[index1] = jumbledCodeWord[index2];
				jumbledCodeWord[index2] = temp;
			}
			// Displays round
			cout << "\nWelcome to round " << i + 1 << " of 3. Good Luck!" << endl;
			// Displays text that asks if you need a clue
			cout << "Enter 'clue' for a clue.\n";
			// Diplays text that asks if you want to quit
			cout << "Enter 'quit' to quit the game.\n\n";
			// Displays the jumbled codeword
			cout << "The codeword is: " << jumbledCodeWord;
			// A string for guess
			// With out this the prgram wouldn't process the guess
			string guess;
			cout << "\n\nYour guess: ";
			cin >> guess;
			// Allows you to quite 
			while ((guess != theWord) && (guess != "quit"))
			{
				// If statment that allows for clues if you type that for your guess
				if (guess == "clue")
				{
					// shows you the clue
					cout << theClue;
				}
				else
				{
					// If you got the word wrong this would display
					cout << "Sorry, that's not the code word.";
				}

				cout << "\n\nYour guess: ";
				cin >> guess;
			}
			// If statment for when you guess the word right 
			if (guess == theWord)
			{
				// if the words right this displays 
				cout << "\nThat's it!  You guessed the code word!\n";
				// adds to your wins
				numberOfWins++;
			}
			// after each round this displays 
			cout << "\nThanks for playing.\n";

		}
		 // displays score 
		cout << "\n\n\t****Your score is " << numberOfWins << " out of 3.\n\n";

		// your choice to play again
		char userChoice;

		// displays the text asking
		cout << "\n\nWould you like to play again? (y/n) ";
		cin >> userChoice;
		// if statment 
		// if you say y the program runs again
		if (userChoice == 'y' || userChoice == 'Y')
		{
			playAgain = true;
			cout << "\nYou choose to play again! Good luck!\n";
		}
		// if you say n the program won't run again
		else
		{
			playAgain = false;
		}

	} while (playAgain == true);
	// displays if you choose not to play again
	cout << "\nYou choose not to play again! Goodbye and good luck!\n";
	// closes program
	return 0;
}