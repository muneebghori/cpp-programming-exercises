#include <iostream>
#include <string>

using namespace std;

bool hasComma(string userString) {
    for (int i = 0; i < userString.size(); i++) {
        if (userString[i] == ',') {
            return true;
        }
    }
    return false;
}

void seperateString(string userString) {
    string first;
    string second;
    int count = 0;
    
    for (int i = 0; i < userString.size(); i++) {
        count++;
        if (userString[i] != ',') {
            first += userString[i];
        }
        else {
            break;
        }
    } 

    for (int i = count; i < userString.size(); i++) {
        if (userString[i] != ' ') {
            second += userString[i];
        }
    }
    cout << "First word: " << first << endl;
    cout << "Second word: " << second << endl;
}

int main(){

    string userString;

    while (userString != "q") {
        userString.clear();
        cout << "Enter input string:\n";
        getline(cin, userString);

        if(hasComma(userString)) {
            seperateString(userString);
        } 
        if (!hasComma(userString) && userString != "q") {
            cout << "Error: No comma in string.\n\n";
        }

    }

    return 0;
}


