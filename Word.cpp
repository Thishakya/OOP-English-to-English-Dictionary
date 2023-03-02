/*
Student Name :- Yasiru Thishakya Kulasinghe
Student Number :- 10567003
Date of creation :- 2022/01/01

*/
#include "Word.h"

void Word::setName(string newName)
{
	name = newName; //gets the name from text file and sets it to this attribute
}

void Word::setType(string NewType)
{
	type = NewType; //gets the type from text file and sets it to this attribute
}

void Word::setDefinition(string NewDefinition)
{
	definition = NewDefinition; //gets the definition from text file and sets it to this attribute
}

string Word::getName()
{
	return name; //retuens the value stored in name.
}

string Word::getType()
{
	return type; //retuens the value stored in type.
}

string Word::getDefinition()
{
	return definition; //retuens the value stored in definition.
}