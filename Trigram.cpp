/*
Student Name :- Yasiru Thishakya Kulasinghe
Student Number :- 10567003
Date of creation :- 2022/01/26

*/
#include "Trigram.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_set>
#include <exception>
void Trigram::fillValues(vector<Word> loadWord)
{
	string alphaWithSpace = "abcdefghijklmnopqrstuvwxyz ";
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	try
	{
		fstream file("WordAndProbability.txt", ios::in | ios:: out | ios:: app);
		

		if (file.is_open()) //checks whether the file is open
		{
			file.seekg(0, ios::end);
			if (file.tellg() == 0) //checks whether the text file is empty
			{
				int i = 0;
				while (alphaWithSpace[i])
				{
					int j = 0;
					while (alphabet[j])
					{
						int r = 0;
						while (alphabet[r])
						{
							string subStr; // the charactor combination gets stored in this variable
							subStr.push_back(alphaWithSpace[i]);
							subStr.push_back(alphabet[j]);
							subStr.push_back(alphabet[r]);
							int count = 0;

							int p = 0;
							while (p < loadWord.size())
							{
								string word = loadWord[p].getName();
								int q = 0;
								while (word[q])
								{
									if (word[q] == alphaWithSpace[i] && word[q + 1] == alphabet[j] && word[q + 2] == alphabet[r])
									{
										count++; // counts the number of time a given charactor combination appears in the dictionary file
									}
									q++;
								}
								p++;
							}
							
							file << subStr << endl; // store the charactor combination in the text file
							file << count << endl; // stores the number of time a combination of charactor appears in the text file

							r++;
						}
						j++;
					}
					i++;
				}
			}
		}
		file.close();
	}
	catch (string message) // if the text file does not exist
	{
		cerr << "An exception was thrown" << endl;
		cerr << message << endl;
	}

}

void Trigram::showValues()
{
	char charOne, charTwo;
	int count = 0;
	string line;
	WordProb newWordProb;
	fstream myFile("WordAndProbability.txt");

	cout << "Enter the first Charactor : "; // get the first charactor
	cin >> charOne;

	cout << "Enter the second Charactor : "; // get the second charactor
	cin >> charTwo;

	if(myFile.is_open()) // checks whether the text file is open
	{
		string word, probapility;
		
		while(getline(myFile , line)) // read the text file line by line
		{
			count++;
			word = probapility;
			probapility = line;
			
			if(count == 2)
			{
				float floatProb = stof(probapility); // convert the string to float
				newWordProb.setSubstring(word); // assign value to the 'newWordProb' object
				newWordProb.setProbability(floatProb); // assign value to the 'newWordProb' object
				wordProbability.push_back(newWordProb); // store the 'newWordProb' in the vector

				count = 0;
			}


		}
	}
	else
	{
		cout << "file cannot be opened" << endl; // if the file does not exist
	}

	float largest1 = 0.0, largest2 = 0.0, largest3 = 0.0;
	int index1 = -1, index2 = -1, index3 = -1;
	
	for (int i = 0; i < wordProbability.size(); i++) // finds the charactor that appears the most with the given charactor combination
	{
		
		string wordComb = wordProbability[i].getSubstring();
		if (charOne == wordComb[0] && charTwo == wordComb[1])
		{
			cout << wordProbability[i].getSubstring() << " - " << wordProbability[i].getProbability() << endl;
			if (largest1 < wordProbability[i].getProbability())
			{
				largest1 = wordProbability[i].getProbability();
				index1 = i;
			}
		}	
	}
	for (int i = 0; i < wordProbability.size(); i++)// finds the 2nd most appearing charactor with the given charactor combination
	{

		string wordComb = wordProbability[i].getSubstring();
		if (charOne == wordComb[0] && charTwo == wordComb[1])
		{
			if (largest2 < wordProbability[i].getProbability() && largest1 > wordProbability[i].getProbability())
			{
				largest2 = wordProbability[i].getProbability();
				index2 = i;
			}
		}
	}
	for (int i = 0; i < wordProbability.size(); i++)// finds the 3rd most appearing charactor with the given charactor combination
	{

		string wordComb = wordProbability[i].getSubstring();
		if (charOne == wordComb[0] && charTwo == wordComb[1])
		{
			if (largest3 < wordProbability[i].getProbability() && largest2 > wordProbability[i].getProbability())
			{
				largest3 = wordProbability[i].getProbability();
				index3 = i;
			}
		}
	}
	

	if (index1 == -1) // if the probability is zero
	{
		cout << charOne << "    and   " << charTwo << "    dont appear in words together " << endl;
	}
	else
	{
		cout << "\n\n" << wordProbability[index1].getSubstring() << " - " << wordProbability[index1].getProbability() << endl;
		cout <<"\' " << wordProbability[index1].getSubstring().substr(2, 2)<<" \'" << "is the charactor most likely to appear with\'" << charOne << "\' and \'" << charTwo << "\'" << endl;
	}
	
	if (index2 == -1)// if the probability is zero
	{
		cout << charOne << "    and   " << charTwo << "    dont appear in words together " << endl;
	}
	else
	{
		cout << "\n\n" << wordProbability[index2].getSubstring() << " - " << wordProbability[index2].getProbability() << endl;
		cout <<" \'" <<wordProbability[index2].getSubstring().substr(2, 2)<<" \'" << "is the charactor  2nd most likely to appear with\'" << charOne << "\' and \'" << charTwo << "\'" << endl;
	}

	if (index3 == -1)// if the probability is zero
	{
		cout << charOne << "    and   " << charTwo << "    dont appear in words together " << endl;
	}
	else
	{
		cout << "\n\n" << wordProbability[index3].getSubstring() << " - " << wordProbability[index3].getProbability() << endl;
		cout <<"\' " << wordProbability[index3].getSubstring().substr(2, 2)<<" \'" << " is the charactor 3rd most likely to appear with\'" << charOne << "\' and \'" << charTwo << "\'" << endl;
	}
	
	
	wordProbability.clear();
	
	myFile.close();
}