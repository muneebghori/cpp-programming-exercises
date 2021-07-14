#include <iostream>
#include <stdlib.h>

int main() {

int computerChoice = 0;
int userChoice = 0;



while (userChoice == computerChoice){
//Computer choosing random number
srand (time(NULL));
computerChoice = (rand() % (3-1+1)) + 1; //rand# from 1-3

//Getting input from User
std::cout << "What's your play?\n 1) Rock\n 2) Paper\n 3) Scissors\n";
std::cin >> userChoice;
std::cout << "Computers Choice: " << computerChoice << "\n";
std::cout << "Users Choice: " << userChoice << "\n\n";

if (computerChoice == 1){
  if (userChoice == 2){
    std::cout << "User Wins!\n";
  } else if (userChoice == 3){
      std::cout << "Computer Wins!\n";
  }
}

  if (computerChoice == 2){
    if (userChoice == 1){
      std::cout << "Computer Wins!\n";
    } else if (userChoice == 3){
        std::cout << "User Wins!\n";
    }
  }

  if (computerChoice == 3){
    if (userChoice == 1){
      std::cout << "User Wins!\n";
    } else if (userChoice == 2){
      std::cout << "Computer Wins!\n";
    }
  }
}
}