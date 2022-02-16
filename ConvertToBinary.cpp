#include <iostream>
using namespace std;

/* Define your functions here */
string IntegerToReverseBinary(int integerValue) {
	string binaryVal;
	while (integerValue > 0) {
		if ((integerValue % 2) == 1) {
			binaryVal += '1';
		}
		else {
			binaryVal += "0";
		}
		integerValue /= 2;
	}

	return binaryVal;
}

string ReverseString(string userString) {
	string newString;
	for (int i = userString.length(); i >= 0; i--) {
		newString += userString[i];
	}

	return newString;
}

int main() {
	/* Type your code here. Your code must call the functions.  */
	int intVal;
	cin >> intVal;

	cout << ReverseString(IntegerToReverseBinary(intVal)) << endl;

	return 0;
}
