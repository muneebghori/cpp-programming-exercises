#include <iostream>
#include <vector>
using namespace std;

/* Define your function here */
bool IsVectorEven(vector<int> myVec) {
	int evenCounter = 0;
	for (int i = 0; i < 6; i++) {
		if (myVec[i] % 2 == 0) {
			evenCounter += 1;
		}
	}
	
	if (evenCounter == 6) {
		return true;
	}
	else {
		return false;
	}
}

bool IsVectorOdd(vector<int> myVec) {
	int oddCounter = 0;
	for (int i = 0; i < 6; i++) {
		if (myVec[i] % 2 != 0) {
			oddCounter += 1;
		}
	}

	if (oddCounter == 6) {
		return true;
	}
	else {
		return false;
	}

}

int main() {
	vector<int> userVec;

	for (int i = 0; i < 6; i++) {
		int input;
		cin >> input;
		userVec.push_back(input);
	}

	if (IsVectorEven(userVec) == true) {
		cout << "all even" << endl;
	}
	else if (IsVectorOdd(userVec) == true) {
		cout << "all odd" << endl;
	}
	else {
		cout << "not even or odd" << endl;
	}


	return 0;
}
