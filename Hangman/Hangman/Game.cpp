/***********************************************************
 * filename: Game.cpp
 * The implementation file for the Game class.
 **********************************************************/
#include "Game.h"

 /***********************************************************************
  * Game(int players, string word)
  * The constructor for the game class, we set it up by initializing
  * both the Words object with the given word and the players vector
  * with enough space to cover each player. Then we make sure the word
  * is right. If it is, the game continues. If not, the game ends.
  ***********************************************************************/
Game::Game(int numPlayers, string word)
{
   words = Words(word);
   setPlayers(numPlayers);
   currentTurn = 1;
   if (!words.validateWord())
      wrongGuesses = 8;
   else
      wrongGuesses = 0;
}

/***********************************************************
 * Game::displayStatus
 * Displays necessary information to the players.
 **********************************************************/
void Game::displayStatus()
{
   cout << words.getHolder() << endl;
   cout << "Guessed Letters: ";
   words.printGuesses();
   cout << "Wrong guesses: " << wrongGuesses << "/8" << endl << endl;
}

/***********************************************************
 * Game::playerTurn()
 * Handles how a player's turn is done.
 **********************************************************/
void Game::playerTurn()
{
   // guess what letter is in the phrase
   char guess;
   cout << "Player " << currentTurn << ", enter your letter: ";
   cin >> guess;

   // after making the guess, check the guess to see if it's right
   if (!words.validateGuess(guess))
   {
      // If it's wrong, it will be noted within the wrong guess spots
      wrongGuesses++;
      players[currentTurn - 1].wrongGuess++;
   }
   // Otherwise it will count as a right guess for that player.
   else
      players[currentTurn - 1].rightGuess++;

   // ensures the turn count doesn't exceed the number of players
   currentTurn++;
   if (currentTurn > players.size())
      currentTurn = 1;
}

/***********************************************************
 * Game::displayEndStats()
 * At the end of the game, it will loop through each player
 * in the players vector and display how many right and wrong
 * guesses they got individually.
 **********************************************************/
void Game::displayEndStats()
{
   for (int i = 0; i < players.size(); i++)
   {
      cout << "Player " << players[i].playerNum << ": "
         << players[i].rightGuess << " correct and "
         << players[i].wrongGuess << " wrong" << endl;
   }

   cout << endl;
}

/***********************************************************
 * Game::setPlayers
 * A Game only method, this sets up the vector with the
 * players based on how many there are.
 **********************************************************/
void Game::setPlayers(int numPlayers)
{
   for (int i = 1; i <= numPlayers; i++)
   {
      Player player;
      player.playerNum = i;
      player.rightGuess = 0;
      player.wrongGuess = 0;
      players.push_back(player);
   }
}