#include <iostream>

//text game -> crashing airplane choices
int main (){

std::cout << "You're on an airplane above the ocean.\n The airplane is starting to lose power and the pilot announces that you will be crashing.\n\n";

std::cout << "You have two choices!\n 1) You will jump off the airplane into the ocean. \n 2) You will stay on the airplane and wait for it to hit the ocean.\n";

int choice;

while (choice != 1 && choice != 2){
  
  std::cin >> choice;
  if (choice == 1){
    std::cout << "YOU'RE DEAD! You jump off the plane and get blended by the engine right behind you!\n";
    return 0;
  } else if (choice == 2){
    std::cout << "YOU LIVE! You wait and the airplane lands on the ocean without breaking into peices!\n";
  } else {
      std::cout << "Invalid input! Enter again: \n";
    }
  }
  
  std::cout << "\nNow the plane is floating on the ocean. Will you:\n 1) Get out quickly\n 2) Help others get out first?\n";
  
  choice = 0;
  
  while (choice != 1 && choice != 2){
    std::cin >> choice;
    if (choice == 1){
        std::cout << "YOU LIVE! The airplane sinks shortly after killing all other 324 passengers on board\n";
    } else if (choice == 2){
        std::cout << "YOU'RE DEAD! The airplane sinks and you die inside of it, including the other passengers.\n";   
        return 0;
    } else {
        std::cout << "Invalid input! Enter again: \n";
    }
  }
  
  std::cout << "\nThe airplane has sunk but the emergency raft is still there. You're the only one who made it out.\n";
  std::cout <<  "The raft has some weights next to it and some paddles. Will you: \n";
  std::cout << " 1) Tie the weights to your waist and jump into the ocean\n";
  std::cout << " 2) Use the paddles to row the boat in hopes of reaching land\n\n"; 

std::cin >> choice;
  if (choice == 1){
     std::cout << "YOU'RE DEAD! You drowned yourself\n";
  } else if (choice == 2){
        std::cout << "YOU'RE DEAD! You keep paddling but get tired and die\n";
    } else {
        std::cout << "\nYOU'RE DEAD! Invalid input, but you're dead either way!";
    }
      std::cout << "\n\nGAME OVER!";
}
  
  
