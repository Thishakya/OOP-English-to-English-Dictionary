/*
Student Name :- Yasiru Thishakya Kulasinghe
Student Number :- 10567003
Date of creation :- 2022/01/25

*/
#include "Dictionary_Part02.h"
#include "Dictionary.h"
#include <vector>
#include <algorithm>
#include <random>
#include <time.h> 
#include "Word.h"

using namespace std;

//checks for Palindromes
void Dictionary_Part02::checkForPalindromes(vector<Word> myWord)
{
	for (size_t i = 0; i < myWord.size(); i++)
	{
		string word = myWord[i].getName();
		string reversedWord = string(word.rbegin(), word.rend()); //reverse the string and stores in the variable 'reversedWord'
		
		if(myWord[i].getName() == reversedWord) //checks whether 'reversedWord' is equal to the word in vector
		{
			cout<< myWord[i].getName() << endl;
		}
	}
}

void Dictionary_Part02::findAnagrams(string userWord, vector<Word> mySecondWord)
{
	bool anagramFound = false;
	string term = userWord;
	sort(userWord.begin(), userWord.end());
	cout << "\n" << endl;
	for (size_t i = 0; i < mySecondWord.size(); i++) // runs throught every element in the vector
	{
		string word = mySecondWord[i].getName();
		if (term == word)
			continue;

		sort(word.begin(), word.end()); // sorts the vector
		
		if(userWord == word) // check the sorted word and sorted word in the vector is equal
		{
			cout<< mySecondWord[i].getName() << endl;
			anagramFound = true;
		}
	}
	if (anagramFound == false)
	{
		cout << "\nNo words found that are anagrams of the word :" << term << endl;
	}
	
}

void Dictionary_Part02::findWord(string word, vector<Word> myThirdWord)
{
	int j = 0;
	char ch;
	while(word[j])
	{
		ch = word[j];
		word[j] = tolower(ch);
		j++;
	}
	
	for (size_t i = 0; i < myThirdWord.size(); i++) //searching for the word begins
	{
		if (myThirdWord[i].getName() == word)
		{
			if (myThirdWord[i].getType() == "pn")
			{
				int len = myThirdWord[i].getName().length();
				char capitalLetter = toupper(myThirdWord[i].getName()[0]);
				cout << "\n\n"<< capitalLetter << myThirdWord[i].getName().substr(1, len-1) << " (" << myThirdWord[i].getType() << ".)" << endl;
			}
			else
			{
				cout << "\n\n" << myThirdWord[i].getName() << " (" << myThirdWord[i].getType() << ".)" << endl;
			}
			
			int r = 0, q= 2;
			string str = myThirdWord[i].getDefinition();
			cout << "\nDefinition - ( 1 )" << endl;
			while (r != str.length())
			{
				if((str[r] == ';') && (str[r + 1] == ' ') && (str[r + 2] == ' '))
				{
					cout << "\n";
					r += 2;
					cout << "\nDefinition - " << "( " << q << " )\t" << endl;
					q++;
					continue;
				}
				cout << str[r];

				r++;
			}
			break;
		}
		else
		{
			//This block is executed only if the given word is not found in the dictionary.
			if (i == myThirdWord.size() - 1)
				cout << "\nword not found" << endl;
		}
	}
}

void Dictionary_Part02::guessingGame(vector<Word> myFourthWord)
{
	string guessedWord;
	int len = myFourthWord.size();
	
	srand(time(NULL));

	int numOfAttempts = 0;

	while (true)
	{
		int randomNum = rand() % len + 1; // generate random numbers
		if (myFourthWord[randomNum].getType() == "n")
		{
			cout << "Find the noun for this definition :\n" << endl;
			cout << myFourthWord[randomNum].getDefinition() << endl;

			while (numOfAttempts != 4)
			{
				cout << "\nEnter the noun for the above definition :";
				cin >> guessedWord;
				numOfAttempts++;

				if (guessedWord == myFourthWord[randomNum].getName()) // goes inside if the answer is correct
				{
					cout << "Correct answer is :" << myFourthWord[randomNum].getName() << endl;
					cout << "Congratulatins...Your answer is correct!....." << endl;
					break;
				}
				else if (numOfAttempts <= 3) //goes inside if the answer is incorrect and there more attems to do
				{
					cout << numOfAttempts << " - letter is : " << myFourthWord[randomNum].getName()[numOfAttempts - 1] << endl;
					cout << "try again..." << endl;
					continue;
				}
				else // goes inside if all the answers are incorrect and there are on more attempts
				{
					cout << "You answer is incorrect...!" << endl;
					cout << "Correct answer is :" << myFourthWord[randomNum].getName() << endl;
				}

			}
			break;

		}
	}
	


}