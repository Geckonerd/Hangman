/*************************************************************************
 * filename: Game.h
 * The game class handles the game logic, including players
 * and turns. It'll include a Words object that will hold both
 * the given phrase and a placeholder to hide the world from the user.
 *************************************************************************/
#pragma once
#include <string>
#include "Words.h"
#include <iostream>
#include <vector>
using namespace std;

struct Player {
   int playerNum;
   int rightGuess;
   int wrongGuess;
};

class Game
{
public:
   // Non-default Constructor
   Game(int numPlayers, string word);

   // Checks if the game is done
   bool lostGame() { return wrongGuesses == 8; }
   bool wonGame()  { return words.completeWord(); }

   // displays needed information
   void displayStatus();

   // handles turn logic
   void playerTurn();

   // displays each players right and wrong guesses
   void displayEndStats();

private:
   vector<Player> players; // Pair helps keep track of each player's guesses
   int wrongGuesses;
   int currentTurn;
   Words words;

   // Sets up the pairs of player number to number of guesses
   void setPlayers(int numPlayers);
};