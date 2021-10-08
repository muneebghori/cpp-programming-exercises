#include <iostream>
using namespace std;


int getNum(string stringInput){
    cout << stringInput << endl;
    int numMade;
    cin >> numMade;
    while (numMade < 0){
        cout << "Error: negative number! " << stringInput;
        
        cin >> numMade;
    }
    
    return numMade;
}

void getTotalScore(int freeThrow, int twoPoint, int threePoint){
    int totalScore;
    totalScore = freeThrow + (2 * twoPoint) + (3 * threePoint);
    
    cout << "Total score is: " << totalScore << endl;
}

int main(){
    cout << "-=Basketball Score Calculator=-" << endl;
    
    int freeThrow;
    int twoPoint;
    int threePoint; 
    
    freeThrow = getNum("Enter number of free throws made: ");
    twoPoint = getNum("Enter number of two point shots made: ");
    threePoint = getNum ("Enter number of three point shots made: ");
   
    getTotalScore(freeThrow, twoPoint, threePoint);   
   return 0;
}
