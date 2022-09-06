#include <vector>
#include <iostream>

using namespace std;


/// @brief Draws the provided tic-tac-toe board to the screen
//  @param board is the tic-tac-toe board that should be drawn
void drawBoard(const vector < char >&gameBoard) {
   for (int i = 0; i < 9; i += 3) {
      cout << "  " << gameBoard.at(i) << "  |  " << gameBoard.at(i + 1) << "  |  "
         << gameBoard.at(i + 2) << "  " << endl;
      if (i < 6) {
         cout << "-----|-----|-----" << endl;
      }
   }
   cout << endl;
    
   return;
}



/// @brief Fills vector with characters starting at lower case a.
///
///     If the vector is size 2 then it will have characters a to b.
///     If the vector is size 6 then it will have characters a to f.
///     If the vector is size 26 then it will have characters a to z.
///
/// @param v the vector to initialize
/// @pre-condition the vector size will never be over 26
void initVector(vector <char> &v) {
    if(v.size() <= 26){
     for(int i = 0; i < v.size(); i++){
        v[i] = 'a' + i;
     }
    }
   return;
}


/// @brief Converts a character representing a cell to associated vector index
/// @param the position to be converted to a vector index
/// @return the integer index in the vector, should be 0 to (vector size - 1)
int convertPosition(char boardPosition) {
   vector<char> myVec(9);
   
   initVector(myVec);
   
   for(int i = 0; i < myVec.size(); i++){
    if(boardPosition == myVec[i]){
     return i;  
    }
   }
   
   return -1;
}


/// @brief Predicate function to determine if a spot in board is available.
/// @param board the current tic-tac-toe board 
/// @param position is an index into vector to check if available
/// @return true if position's state is available (not marked) AND is in bounds
bool validPlacement(const vector<char>  &gameBoard, int positionIndex) {
   if(positionIndex < gameBoard.size()){
      if((gameBoard[positionIndex] != 'X' && gameBoard[positionIndex] != 'O')){
       return true;  
      } else {
       return false;  
      }
   }
   //return false;
}

/// @brief Acquires a play from the user as to where to put her mark
///
///     Utilizes convertPosition and validPlacement functions to convert the
///     user input and then determine if the converted input is a valid play.
///     Continues asking for a position until a valid position has been entered.
///
/// @param board the current tic-tac-toe board 
/// @return an integer index in board vector of a chosen available board spot
int getPlay(const vector<char> &gameBoard) {

   char boardPosition = ' ';
   int myInt; 
   
   do{
      cout << "Please choose a position: ";
      cin >> boardPosition;
      cout << endl;
      myInt = convertPosition(boardPosition);
   } while ((!validPlacement(gameBoard, myInt)));
   return myInt;
    
   return -1;
}


/// @brief Predicate function to determine if the game has been won
///
///     Winning conditions in tic-tac-toe require three marks from same 
///     player in a single row, column or diagonal.
///
/// @param board the current tic-tac-toe board 
/// @return true if the game has been won, false otherwise
bool gameWon(const vector<char> &gameBoard) {
    
   for(int i = 0; i < 3; i++){
    if(gameBoard[3 * i] == gameBoard[3 * i + 1] && gameBoard[3 * i + 1] == gameBoard[3 * i + 2]){
       return true;
    } else if (gameBoard[i] == gameBoard[i + 3] && gameBoard[i + 3] == gameBoard[i + 6]){
       return true;
    }
   }
   
   if(gameBoard[0] == gameBoard[4] && gameBoard[4] == gameBoard[8]){
      return true;
   } else if (gameBoard[2] == gameBoard[4] && gameBoard[4] == gameBoard[6]){
      return true;
   }
   return false;
}


/// @brief Predicate function to determine if the board is full
/// @param board the current tic-tac-toe board 
/// @return true iff the board is full (no cell is available)
bool boardFull(const vector<char> &gameBoard) {
   
   int myInt = 0;
   for(int i = 0; i < gameBoard.size(); i++){
      if(gameBoard[i] == 'X' || gameBoard[i] == 'O'){
         myInt++;
      }
   }
      if (myInt >= 9){
         return true;
      }
      else 
         return false;
   
   //return false;
}


// Global constants for player representation
const int PLAYER1 = 0;
const int PLAYER2 = 1;

int main() {
   // Variables that you may find useful to utilize
   vector<char> gameBoard(9);
   int curPlay;
   int whosTurn = PLAYER1; // Player 1 always goes first and is 'X'

   /// TODO: Initialize board to empty state
   initVector(gameBoard);

   
   /// TODO: Display the empty board
   
   drawBoard(gameBoard);
   while(!gameWon(gameBoard) && !boardFull(gameBoard)){
      curPlay = getPlay(gameBoard);
      if(whosTurn == PLAYER1){
       gameBoard[curPlay] = 'X';  
      } else {
         gameBoard[curPlay] = 'O';
      } 
         if(!boardFull(gameBoard) && !gameWon(gameBoard)){
          if(whosTurn == PLAYER1){
           whosTurn = PLAYER2;  
          } else if (whosTurn == PLAYER2){
           whosTurn = PLAYER1;  
          }
         }
        // drawBoard(gameBoard);
      
      drawBoard(gameBoard);
   }
   
   if(whosTurn == PLAYER1 && gameWon(gameBoard)){
    cout << "Player 1 Wins!!" << endl << endl;
   } else if (whosTurn == PLAYER2 && gameWon(gameBoard)){
    cout << "Player 2 Wins!!" << endl << endl;  
   } else {
      cout << "No one wins" << endl << endl;
   }

   return 0;
}