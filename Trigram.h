/*
Student Name :- Yasiru Thishakya Kulasinghe
Student Number :- 10567003
Date of creation :- 2022/01/26

This 'Trigram' class creates a vector called 'wordProbability' and stores the objects of the 'WordProb' class in the vactor

*/
#pragma once
#include <vector>
#include "Word.h"
#include "WordProb.h"
using namespace std;
class Trigram
{
private:
	vector<WordProb> wordProbability;
public:
	//stores the words and their probabilities in a text file.
	void fillValues(vector<Word> loadWord);

	//shows how many times a charactor appears with a given two charactors
	void showValues();
};

