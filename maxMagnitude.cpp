#include <iostream>
#include <cmath>
using namespace std;

/* Define your function here */
int MaxMagnitude(int userVal1, int userVal2) {
	int max;
	if (abs(userVal1) > abs(userVal2)) {
		max = userVal1;
	}
	else {
		max = userVal2;
	}

	return max;
}

int main() {
	int num1, num2;

	cin >> num1 >> num2;

	cout << MaxMagnitude(num1, num2) << endl;
	

	return 0;
}
