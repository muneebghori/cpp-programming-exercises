#include <iostream>

using namespace std;

void mainMenu(){
    cout << "-=Temperature Converter V1.0!=-" << endl;
    cout << "1. C to F" << endl;
    cout << "2. F to C" << endl;
    cout << "3. Quit" << endl;
}

void CtoF(){
    int tempC, tempF;

    cout << "Enter the temperature in C: ";
    cin >> tempC;
    cout << endl;

    tempF = ((tempC * 1.8) + 32);

    cout << tempC << " deg C is " << tempF << " deg F" << endl;
}

void FtoC(){
    int tempC, tempF;

    cout << "Enter the temperature in F: ";
    cin >> tempF;
    cout << endl;

    tempC = ((tempF - 32) * .5556);

    cout << tempF << " deg F is " << tempC << " deg C" << endl;
    
}

void inputSelection(){
    int userInput;
    while(userInput != 3){
        mainMenu();
        cin >> userInput;
        if(userInput == 1) {
            CtoF();
            cout << endl;
        }
        else if (userInput == 2){
            FtoC();
            cout << endl;
        }
        else {
            cout << "Enter a valid input" << endl;
        }
    }
    if(userInput == 3){
        cout << "Thank you for using Temperature Converter V1.0" << endl;
        exit;
    }
}

int main(){

    inputSelection();

}