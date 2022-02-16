#include <iostream>
using namespace std;

/* Define your functions here */
int LargestNumber(int num1, int num2, int num3) {
	int largest;

	if (num1 > num2 && num1 > num3) {
		largest = num1;
	}
	else if (num2 > num1 && num2 > num3) {
		largest = num2;
	}
	else {
		largest = num3;
	}

	return largest;
}

int SmallestNumber(int num1, int num2, int num3) {
	int smallest;
	
	if (num1 < num2 && num1 < num3) {
		smallest = num1;
	}
	else if (num2 < num1 && num2 < num3) {
		smallest = num2;
	}
	else {
		smallest = num3;
	}

	return smallest;
}

int main() {
	/* Type your code here. Your code must call the functions.  */
	int num1, num2, num3;

	cin >> num1 >> num2 >> num3;

	cout << "largest: " << LargestNumber(num1, num2, num3) << endl;

	cout << "smallest: " << SmallestNumber(num1, num2, num3) << endl;

	return 0;
}
