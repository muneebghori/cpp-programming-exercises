#include <iostream>
#include <iomanip>
using namespace std;

/* Define your function here */
int FeetToSteps(double userFeet) {
	int steps = userFeet / 2.5;

	return steps;
}

int main() {
	int steps;

	cin >> steps;

	cout << FeetToSteps(steps) << endl;

	return 0;
}
