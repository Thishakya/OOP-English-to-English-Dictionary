/*
Student Name :- Yasiru Thishakya Kulasinghe
Student Number :- 10567003
Date of creation :- 2022/01/01

*/
#include "Dictionary.h"
#include <fstream>

vector<Word> Dictionary::loadDictionary()
{
	fstream myFile("dictionary2022_S0.txt"); //creates an object from fstream class
	string fileLine, holder1, holder2, holder3;
	int lineCount = 0, index = 0;

	if (myFile.is_open()) //check whether the file exists
	{
		while (getline(myFile, fileLine)) // reads the content of the text file line by line
		{
			if (fileLine == "**") // ignores lines that has two asterics marks
				continue;

			lineCount++;

			holder3 = holder2; // These variables holds the last three lines read by the fstream's object
			holder2 = holder1;
			holder1 = fileLine;

			if (lineCount == 3)
			{

				Word newWord;
				newWord.setType(holder3); // when lineCount becomes 3, holder1 contains the word type
				newWord.setName(holder2); // holder2 contains the word
				newWord.setDefinition(holder1); // holder3 contails the definition of the word
				
				myWord.push_back(newWord); //The word is pushed back to the vector

				lineCount = 0;
				continue;
			}
		}
		return myWord;
	}
	else
	{
		cout << "file not found" << endl;
	}
}

void Dictionary::findWord(string word, vector<Word> myThirdWord)
{
	for (size_t i = 0; i < myThirdWord.size(); i++) //searching for the word begins
	{
		if (myThirdWord[i].getName() == word)
		{
			cout << myThirdWord.size() << endl;
			//This block is executed only if the given word is found in the dictionary.
			cout << "\n\n" << myThirdWord[i].getName() << " (" << myThirdWord[i].getType() << ".)" << endl;
			cout << "\n\n" << myThirdWord[i].getDefinition() << endl;

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
