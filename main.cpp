#include <iostream>
#include "TTT.h"
using namespace std;
int main() {
  cout << "---------------------WELCOME TO TIC TAC TOE-----------------------" << endl;
  string player1;
  string player2;
  cout << "Player 1, enter your username. Your marker is: O" << endl;
  cin >> player1;
  cout << "Player 1 checked in. Player 2, enter your username. Your marker is: X" << endl;
  cin >> player2;
  cout << "Player1: " << player1 << endl;
  cout << "Player2: " << player2 << endl;
  cout << "All players locked in! " << endl;
  cout << "---------------HOW TO PLAY:--------------------" << endl;
  cout << player1 << " and " << player2 << ":" << endl;
  cout << "You are going to enter a number that corresponds with the desired position on the board that you want to place your marker on." << endl;
  cout << "BOARD LAYOUT: " << endl;
  cout << "0 1 2" << endl;
  cout << "3 4 5" << endl;
  cout << "6 7 8" << endl;
  cout << "Whoever gets three in a row is the winner!" << endl;
  cout << "REMINDER: nonexistent positions or full positions will still count as a turn. Don't make a mistake!" << endl;
  cout << "-----------------------------------------------------" << endl;
  cout << "Got it? " << endl;
  cout << "Let the games begin: " << endl;
  TTT game;
  game.display();
  int position1;
  int position2;
  cout << "REMINDER: positions only range from 0 to 8!" << endl;
  while(!game.end()){
    cout << player1 << ", enter your position (your marker is O)" << endl;
    cin >> position1;
    if(game.placeO(position1)){
      game.display();
    }
    cout << player2 << ", enter your position (your marker is X)" << endl;
    cin >> position2;
    if(game.placeX(position2)){
      game.display();
    }
    if(game.maxNumofMoves()){
      cout << "Game Over. Board is Full" << endl;
    }
    if(game.tie()){
     cout << "The game has tied. No one has won." << endl;
    }
    if(game.victory()){
    if(game.getWinner() == "O"){
      cout << "Player 1 has won. Their number of turns: " << game.getMovesO() << endl;
    }
    if(game.getWinner() == "X"){
      cout << "Player 2 has won. Their number of turns: " << game.getMovesX() << endl;
    }
    }
  }
  /*
  if(game.maxNumofMoves()){
      cout << "Game Over. Board is Full" << endl;
    }
 if(game.tie()){
     cout << "The game has tied. No one has won." << endl;
  }
  if(game.victory()){
    if(game.getWinner() == "O"){
      cout << "Player 1 has won. Their number of moves: " << game.getMovesO() << endl;
    }
    if(game.getWinner() == "X"){
      cout << "Player 2 has won. Their number of moves: " << game.getMovesX() << endl;
    }
  }
  */
  cout << "-----------------THANKS FOR PLAYING----------------------------" << endl;
  return 0;
}