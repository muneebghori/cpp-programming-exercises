#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    cout << "Coin Flipper!" << endl;
    cout << "Press 1 for heads or 2 for tails: " << endl;
    int userInput;
    string coinSide;
    cin >> userInput;
    
    
    if (userInput == 1){
        coinSide = "Heads";
        cout << "You chose Heads" << endl;
    } else if (userInput == 2) {
        coinSide = "Tails";
        cout << "You chose Tails" << endl;
    }
    
    int coinFlip;
    coinFlip = rand() % 2 + 1;
    
    cout << "The side is: ";
    if (coinFlip == 1){
        cout << "HEADS!" << endl;
    } else {
        cout << "TAILS!" << endl;
    }
    
    return 0;
}
