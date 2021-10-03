#include <iostream>
#include "play.h"

//global stuff
std::string board[9] = { " ", " ", " ", " ", " ", " ", " ", " ", " " }; //9 spots on the 3x3 board
int player = 1;
int position = 0;

//outputs the intro to the game and the grid the game will be played ond
void introduction() {
    std::cout << "Press [Enter] to begin Tic-Tac-Toe";
    std::cin.ignore();

    std::cout << "\n-=-=-=-=-=-=-\n";
    std::cout << "Tic-Tac-Toe!\n";
    std::cout << "-=-=-=-=-=-=-\n\n";

    std::cout << "Player 1 is X\n";
    std::cout << "Player 2 is O\n\n";

    std::cout << "Here's the 3x3 grid:\n\n";

    std::cout << "  1  |  2  |  3   \n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "  4  |  5  |  6   \n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "  7  |  8  |  9   \n\n";
}

//checks to see if the player has won or not
bool is_winner() {
    bool winner = false;
    //if rows are matching
    //code is saying if spot 1 & 2 and 1 & 3 are equal and spot 1 is not blank, then its matching.
    if ((board[0] == board[1]) && (board[1] == board[2]) && board[0] != " ") {
        winner = true;
    }
    else if ((board[3] == board[4]) && (board[3] == board[5]) && board[3] != " ") {
        winner = true;
    }
    else if ((board[6] == board[7] && (board[6] == board[8]) && board[6] != " "))
        winner = true;

    //if columns are matching
    else if ((board[0] == board[3]) && (board[0] == board[6]) && board[0] != " ") {
        winner = true;
    }
    else if ((board[1] == board[4]) && (board[1] == board[7]) && board[1] != " ") {
        winner = true;
    }
    else if ((board[2] == board[5]) && (board[2] == board[8] && board[2] != " ")) {
        winner = true;
    }

    //if 3 diagonal spots are matching
    else if ((board[0] == board[4]) && board[0] == board[8] && board[0] != " ") {
        winner = true;
    }
    else if ((board[2] == board[4]) && (board[2] == board[6]) && board[2] != " ") {
        winner = true;
    }

    return winner;
}

//goes thru all the grid spots to see if they've all been filled up or not
bool filled_up() {
    bool filled = true;

    for (int i = 0; i < 9; i++) {
        if (board[i] == " ") {
            filled = false;
        }
    }
    return filled;
}

//draws out the current status of the board
void draw() {
    std::cout << board[0] << "  |  " << board[1] << "|  " << board[2] << "\n";
    std::cout << "___|___|___ \n";
    std::cout << board[3] << "  |  " << board[4] << "|  " << board[5] << "\n";
    std::cout << "___|___|___ \n";
    std::cout << board[6] << "  |  " << board[7] << "|  " << board[8] << "\n\n";
}


void set_position() {
    std::cout << "Player " << player << "'s Turn (Enter 1-9): ";
    
    std::cin >> position;
    bool passTest1 = false;
    bool passTest2 = false;
    while (!passTest1 || !passTest2) {
        if (position < 1 || position > 9) {
            bool passTest1 = false;
            std::cout << "Player " << player << ", please enter a valid number between 1 and 9: ";
            std::cin >> position;
        } else passTest1 = true;
        
        if ((board[position - 1] != " ") && (1 < position < 9)) {
            bool passTest2 = false;
            std::cout << "Error: Position " << position << " is already filled up, select a blank spot!\n\n";
            std::cin >> position;
      
            std::cout << "\n";
        } else passTest2 = true;
    }
    //sets the position of the board to either X or O 
    if (player == 1) {
        board[position - 1] = "X";
    }
    else {
        board[position - 1] = "O";
    }
}

//swaps between player 1 & 2. If current player is 1, then next is 2 & vice versa. 
void change_player() {
    if (player == 1) {
        player = 2;
    }
    else {
        player = 1;
    }
}
void take_turn() {
    while (!filled_up() && !is_winner()) {
        set_position();
        change_player();
        draw();
    }
}

void gameOver() {
    if (is_winner()) {
        std::cout << "WINNER!\n";
    }
    else if (filled_up()) {
        std::cout << "TIE!\n";
    }

    std::cout << "\n-=GAME OVER=-\n";
    std::cout << "Credits: Muneeb Ghori October 2021\n";
}