/*
Student Name :- Yasiru Thishakya Kulasinghe
Student Number :- 10567003
Date of creation :- 2022/01/25

This 'WordProb' class store the combination of strings and the number of time thoes appear in the dictionary text file

*/
#pragma once
#include <string> 
using namespace std;

class WordProb
{
private:
	string  substring;
	float probability;

public:
	//setters
	void setSubstring(string word);
	void setProbability(float prob);

	//getters
	string getSubstring();
	float getProbability();

};

