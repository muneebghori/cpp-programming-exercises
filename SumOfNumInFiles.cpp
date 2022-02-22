#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(string filename);

int main() {
	string filename;
	cout << "Enter the name of the input file: ";
	cin >> filename;
	cout << "Sum: " << fileSum(filename) << endl;
	
	return 0;
}

// Place fileSum implementation here
int fileSum(string filename) {
	int sum = 0;
	int currNum;

	ifstream textFile;
	textFile.open(filename, ios::in);
	if (textFile.is_open()) {
		while(!textFile.eof()){
			textFile >> currNum;
			sum += currNum;
		}

		return sum;
	}
	else {
		cout << "File not found\n";
		exit(1);
	}
}