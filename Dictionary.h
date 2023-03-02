/*
Student Name :- Yasiru Thishakya Kulasinghe
Student Number :- 10567003
Date of creation :- 2022/01/01

This Dictionary class loads the content of the text file in to a vector called myWord.

*/
#pragma once
#include <vector>
#include <string>
#include "Word.h"
class Dictionary
{
private:
	vector<Word> myWord;

public:
	vector<Word> loadDictionary();
	void findWord(string word, vector<Word> myThirdWord);
};

