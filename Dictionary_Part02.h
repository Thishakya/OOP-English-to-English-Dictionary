/*
Student Name :- Yasiru Thishakya Kulasinghe
Student Number :- 10567003
Date of creation :- 2022/01/22

This Dictionary_Part2 class checks panindromes, finds anagrams, Finds word with more formatting than the 
first part of the assignment and runs the guessing game

*/
#pragma once
#include "Dictionary.h"
#include <vector>
#include "Word.h"
class Dictionary_Part02 : public Dictionary
{
public:
	//checks for Palindromes
	void checkForPalindromes(vector<Word> myWord); 

	//finds anagrams
	void findAnagrams(string userWord, vector<Word> mySecondWord);

	//Finds meaning of words and presents in a more formatted manner than the first part of the assignment 1
	void findWord(string word, vector<Word> myThirdWord);

	//runs the guessing game
	void guessingGame(vector<Word> myThirdWord);
};

