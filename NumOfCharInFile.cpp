#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(string filename, char ch);


int main() {
	string filename;
	char ch;
	cout << "Enter the name of the input file: ";
	cin >> filename;
	cout << "Enter a character: ";
	cin >> ch;

	cout << "# of " << ch << "'s: " << charCnt(filename, ch) << endl;

	return 0;
}

// Place charCnt implementation here
int charCnt(string filename, char ch) {
	int numOfChar = 0;
	char currChar;
	ifstream myFile;
	myFile.open(filename, ios::in);
	if (myFile.is_open()) {
		while (!myFile.eof()) {
			myFile >> currChar;
			if (currChar == ch) {
				numOfChar++;
			}
		}
		return numOfChar;
	}
	else {
		cout << "File not found" << endl;
		exit(1);
	}
}