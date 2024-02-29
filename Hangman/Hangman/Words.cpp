/***********************************************************
 * filename: Words.cpp
 * The implementation file for the Words class
 **********************************************************/
#include "Words.h"
#include <algorithm>

 /***********************************************************
  * Words()
  * The default constructor if the user doesn't give a word
  **********************************************************/
Words::Words()
{
   word = "";
   holder = "";
}

/***********************************************************
 * Words(string word)
 * The non-default constructor for the Words class, setting
 * up both strings based on the provided word/phrase
 **********************************************************/
Words::Words(string word)
{
   this->word = word;
   setHolder();
}

/***********************************************************
 * Words::validateWord()
 * Makes sure that the provided word fits in the rules.
 * If it doesn't work, it will return false, ending the game
 * on the user.
 **********************************************************/
bool Words::validateWord()
{
   // If the provided word is empty, the game just ends,
   // as there's no way to play the game.
   if (word.length() == 0)
   {
      cout << "Must have at least one letter!" << endl;
      return false;
   }

   // converts all letters into lowercase for simplicity
   for (int i = 0; i < word.length(); i++)
   {
      word[i] = tolower(word[i]);
   }

   for (int i = 0; i < word.length(); i++)
   {
      // if any character is neither a letter nor a space
      // the word will not be accepted and the game ends
      if (isalpha(word[i]) == false && word[i] != ' ')
      {
         cout << "Incorrect format! Use only letters and spaces!" << endl;
         return false;
      }
   }
   return true;
}

/***********************************************************
 * Words::validateGuess(char guess)
 * This function takes the player's guess to verify whether
 * the letter exists in the word/phrase.
 **********************************************************/
bool Words::validateGuess(char guess)
{
   // If the user previously entered a non lowercase letter, they
   // will be stuck in this loop until they enter a lowercase letter
   while (!isalpha(guess) || isupper(guess))
   {
      cout << "Incorrect format! Enter only lowercase letters: ";
      cin >> guess;
   }

   // before anything else, the letter is added to the set
   // containing all of the guesses that have been made.
   guesses.insert(guess);
   bool exists = false;
   for (int i = 0; i < word.size(); i++)
   {
      // if the letter does exist
      if (guess == word[i])
      {
         holder[i] = guess;
         exists = true;
      }
   }
   return exists;
}

/***********************************************************
 * Words::completeWord()
 * At the end of a player's turn, this function will check
 * the holder string to see if the word/phrase had been
 * completed.
 **********************************************************/
bool Words::completeWord()
{
   for (int i = 0; i < holder.size(); i++)
   {
      if (holder[i] == '-')
         return false;
   }
   return true;
}

/***********************************************************
 * Words::printGuesses()
 * A simple function that displays all of the guesses
 * that have been made in the game.
 **********************************************************/
void Words::printGuesses()
{
   for (auto it = guesses.begin(); it != guesses.end(); it++)
   {
      cout << *it << " ";
   }
   cout << endl;
}

/***********************************************************
 * Words::setHolder()
 * This method sets the placeholder string based on the
 * positioning of letters and spaces, replacing the letters
 * with -.
 **********************************************************/
void Words::setHolder()
{
   holder = word;
   replace_if(holder.begin(), holder.end(), ::isalpha, '-');
}