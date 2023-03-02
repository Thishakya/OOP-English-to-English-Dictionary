/*
Student Name :- Yasiru Thishakya Kulasinghe
Student Number :- 10567003
Date of creation :- 2022/01/01

Thw Word class holds the type, definition and the word itself.

*/
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Word
{
private:
	string name;
	string type;
	string definition;

public:
	//setters
	void setName(string newName);
	void setType(string NewType);
	void setDefinition(string NewDefinition);

	//Getters
	string getName();
	string getType();
	string getDefinition();

};

