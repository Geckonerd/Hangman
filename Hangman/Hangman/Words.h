/***********************************************************
 * filename: Words.h
 * The Words class handles all functions regarding
 * both the word/phrase as well as the blank string
 * that holds what letters have been successfully guessed.
 **********************************************************/

#include <string>
#include <set>
#include <iostream>
using namespace std;

#pragma once
class Words
{
public:
   // Constructors
   Words();
   Words(string word);

   // getters for the phrase and holder
   string getWord()   { return word;   }
   string getHolder() { return holder; }

   // Validation methods to ensure everything is correct
   bool validateWord();
   bool validateGuess(char guess);
   bool completeWord();

   // Displays the guessed letters
   void printGuesses();

private:
   string word;
   string holder;
   set<char> guesses; // Holds what has been guessed
   
   // Sets up the holder string. Only Words needs this.
   void setHolder();
};

