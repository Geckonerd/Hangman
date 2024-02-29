/***********************************************************
 * filename: Hangman.cpp
 * This is the primary file that contains the main function.
 * This file is in charge of setting up the game, laying out
 * the rules, and giving the user the option to start a new
 * game when the game ends.
 **********************************************************/
#include <iostream>
#include <string.h>
#include "Game.h"

using namespace std;

int main()
{
   cout << "*WELCOME TO HANGMAN*" << endl;
   cout << "     _____" << endl;
   cout << "     |   |" << endl;
   cout << "     |   " << endl;
   cout << "     |" << endl;
   cout << "     |" << endl;
   cout << "     |" << endl;
   cout << "-----------" << endl << endl;

   cout << "Rules of the game:" << endl;
   cout << "1. Letters and spaces are the only thing allowed." << endl;
   cout << "2. You have 8 guesses to correctly guess the word or phrase." << endl;
   cout << "3. Guesses are to be made in lowercase letters." << endl;

   // exit is what allows the users to set up an additional game.
   bool exit = false;
   while (!exit)
   {
      // The user will be asked how many players will
      // be playing and what the word or phrase will be
      int players;
      cout << endl << "How many players will be playing: ";
      cin >> players;
      string word;
      cout << "Enter the word or phrase: ";
      cin.ignore();
      getline(cin, word);

      // After getting the players and phrase, the game object will
      // be made, validating the word/phrase to ensure that the game
      // will properly run. If the word is valid, the game will continue
      // until they guess the word or run out of guesses
      Game game(players, word);

      // While in this loop, the game is running. Players will take their
      // turns guessing letters. The loop will only end when they win or lose.
      while (!game.lostGame() && !game.wonGame())
      {
         system("cls");
         game.displayStatus();
         game.playerTurn();
      }

      game.displayEndStats();
      // After the game stops, the user has the option to start a new game.
      // If they say no, the game will exit the loop and the game will end.
      string response;
      cout << "Would you like to play again? y/n: ";
      cin >> response;
      if (response != "y")
         exit = true;
   }

}