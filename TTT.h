#pragma once
#include <iostream>
#include <string>
using namespace std;

class TTT{
public:
string board[9] = {"-", "-", "-", "-", "-", "-", "-", "-", "-"};
int moves = 0;
int movesO = 0;
int movesX = 0;
string victoryMarker;
string getWinner(){
  return victoryMarker;
}
bool end(){
  if((victory() && maxNumofMoves()) || victory() || tie()){
    return true;
  }
  return false;
}
int getMovesO(){
  return movesO;
}
int getMovesX(){
  return movesX;
}
int totalNumofMoves(){
  return moves;
}
bool quit(string choice){
  if(choice == "Y"){
    return true;
  }
  return false;
}
void display();
bool victory();
bool tie(){
  if(maxNumofMoves() && !victory()){
    return true;
  }
  return false;
}
bool maxNumofMoves(){
  if(moves == 9){
    return true;
  }
  return false;
}
bool placeO(int place);
bool placeX(int place);
};
void TTT::display(){
  cout << "----------------------------------" << endl;
  for(int i = 0; i <= 2; i++){
        cout << board[i] << " ";
 }
  cout << endl;
  for(int i = 3; i <= 5; i++){
        cout << board[i] << " ";
 }
  cout << endl;
  for(int i = 6; i <= 8; i++){
        cout << board[i] << " ";
 }
  cout << endl;
  cout << "----------------------------------" << endl;
}
bool TTT::placeO(int position){
  if(position >9 || position < 0){
    cout << "Position does not exist. " << endl;
    return false;
  }
  if(board[position] == "-"){
    board[position] = 'O';
    moves++;
    movesO++;
    return true;
 }
  cout << "Position already full. " << endl;
  return false;
}
bool TTT::placeX(int position){
  if(position >9 || position < 0){
    cout << "Position does not exist. " << endl;
    return false;
  }
  if(board[position] == "-"){
    board[position] = 'X';
    moves++;
    movesX++;
    return true;
 }
  cout << "Position already full. " << endl;
  return false;
}


bool TTT::victory(){
  //horizontal 
  if(board[0]!= "-" && board[0] == board[1] && board[1] == board[2]){
    victoryMarker = board[0];
    return true;
  }
  if(board[3]!= "-" && board[3] == board[4] && board[4] == board[5]){
    victoryMarker = board[3];
    return true;
  }
  if(board[6]!= "-" && board[6] == board[7] && board[7] == board[8]){
    victoryMarker = board[6];
    return true;
  }
  //vertical 
  if(board[0]!= "-" && board[0] == board[3] && board[3] == board[6]){
    victoryMarker = board[0];
    return true;
  }
  if(board[1]!= "-" && board[1] == board[4] && board[4] == board[7]){
    victoryMarker = board[1];
    return true;
  }
  if(board[2]!= "-" && board[2] == board[5] && board[5] == board[8]){
    victoryMarker = board[2];
    return true;
  }
  //diagonal 
  if(board[0]!= "-" && board[0] == board[4] && board[4] == board[8]){
    victoryMarker = board[0];
    return true;
  }
  if(board[2]!= "-" && board[2] == board[4] && board[4] == board[6]){
    victoryMarker = board[2];
    return true;
  }
  
  return false;
}