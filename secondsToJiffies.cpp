#include <iostream>
#include <iomanip>
using namespace std;

/* Define your function here */
double SecondsToJiffies(double userSeconds) {

	return (userSeconds * 100);

}

int main() {
	/* Type your code here. Your code must call the function.  */
	double seconds;

	cin >> seconds;

	cout << fixed << setprecision(2);
	cout << SecondsToJiffies(seconds) << endl;

	return 0;
}