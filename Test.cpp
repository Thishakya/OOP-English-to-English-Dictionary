#include <iostream>
#include "Dictionary.h"
#include "Dictionary_Part02.h"
#include "Word.h"
#include "Trigram.h"
#include <vector>
#include <string>

using namespace std;

int main()
{
    Dictionary myDict; //object is created from Dictionary class called myDict
    Dictionary_Part02 myDict_Part02;
    string findWord, userWord;
    char letter, userInput, exitProgram = 0;
    int number, wordCount = 0;
    vector<Word> loadWord;
    Trigram newTrigram;

    cout << "--------------The dictinary is being loaded. please wait!--------------" << endl;
    loadWord = myDict.loadDictionary(); //the content of the text file is loaded to the vector.

    while (!exitProgram) 
    {
        cout << "\n\n\n";
        cout << "------ Dictionary Search -----------\n\n";
        cout << "Please Select one option: \n";
        cout << "1 search a definition of a word\n";
        cout << "2 Find the word(s) that contain a given character more than a given number of times\n";
        cout << "3 words that have a 'q' without a following 'u'\n";
        cout << "4 Check for Palindromes" << endl;
        cout << "5 find anagrams" << endl;
        cout << "6 find a word's definition with a good formatting" << endl;
        cout << "7 guessing game" << endl;
        cout << "8 Tri-Gram" << endl;
        cout << "9 exit\n";
       
        cout << "\n\nPlease Enter your option: ";
        cin >> userInput;
        switch (userInput) 
        {
        case '1': 
            cout << "\n\nEnter the word you want to find the meaning of :-" << endl;
            cin.ignore();
            getline(cin, findWord);
            myDict.findWord(findWord, loadWord);
            break;
        case '2': 
            cout << "\n\nEnter the letter :-\n";
            cin >> letter;

            cout << "\n\nEnter the minimum number of time the letter should occur in a word :-\n";
            cin.ignore();
            cin >> number;

            for (size_t  i = 0; i < loadWord.size(); i++)
            {
                string term = loadWord[i].getName();
                int letterCount = 0;

                for (size_t  j = 0; j <= term.length(); j++)
                {
                    if (term[j] == letter)
                    {
                        letterCount++; // letterCount gets incremented if the givven letter is in the word.
                    }
                }

                if (letterCount >= number)
                {
                    //This block is executed only if the letter count is equal or greater than the given letter count by the user.
                    cout << loadWord[i].getName() << endl;
                    wordCount++;
                }
            }
            if (wordCount == 0)
            {
                //This block is executed only if the letter count id less than the letter count given by the user.
                cout << "\n\nThe letter [ " << letter << " ] couldnt be found more than [ " << number << " ] times in any word" << endl;
            }
            break;
        case '3': 
            for (size_t  i = 0; i < loadWord.size(); i++) //This loop runs through the vector
            {
                string term = loadWord[i].getName();

                for (size_t  j = 0; j < term.length(); j++) //This loop runs through the letters in a word.
                {
                    if ((term[j] == 'q') && (term[j + 1] != 'u'))
                    {
                        cout << loadWord[i].getName() << endl; // This block executes only if the letter 'q' is not followed by letter 'u'.
                    }
                }
            }
            break;
        case '4':
            myDict_Part02.checkForPalindromes(loadWord);
            break;
        case '5':
            cout << "Enter the word you want to find the anagram of :" << endl;
            cin >> userWord;
            myDict_Part02.findAnagrams(userWord, loadWord);
            break;
        case '6':
            cout << "Enter the word you want to find the meaning of:" << endl;
            cin >> userWord;
            myDict_Part02.findWord(userWord, loadWord);
            break;
        case '7':
            myDict_Part02.guessingGame(loadWord);
            break;
        case '8':
            newTrigram.fillValues(loadWord);
            newTrigram.showValues();
            break;
        case '9': 
            exitProgram = 1; // exists from the program.
            break;
        default: 
            cout << "\n\nPlease Insert a valid option between 1 to 8";
            break;
        }

    }

    system("pause");
    return 0;

}
