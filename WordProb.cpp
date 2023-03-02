/*
Student Name :- Yasiru Thishakya Kulasinghe
Student Number :- 10567003
Date of creation :- 2022/01/26

*/
#include "WordProb.h"

void WordProb::setSubstring(string word)
{
	substring = word; //get the word from the text file and sets it to this attribute
}

void WordProb::setProbability(float prob)
{
	probability = prob; //get the probability from the text file and sets it to this attribute
}

string WordProb::getSubstring()
{
	return substring; //return the value stored in substring
}

float WordProb::getProbability()
{
	return probability; //return the value stored in probability
}