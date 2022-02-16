#include <iostream>
using namespace std;

int main() {

	int change;

	cin >> change;

	if (change < 1) {
		cout << "No change\n";
		return 0;
	} 
	
	//Dollars
	if (change < 200 && change >= 100) {
		cout << change / 100 << " Dollar\n";
		change -= 100;
	}
	else if (change >= 200) {
		cout << change / 100 << " Dollars\n";
		change -= ((change / 100) * 100);
	}

	//Quarters
	if (change < 50 && change >= 25) {
		cout << change / 25 << " Quarter\n";
		change -= 25;
	}
	else if (change >= 50) {
		cout << change / 25 << " Quarters\n";
		change -= ((change / 25) * 25);
	}

	//dimes
	if (change < 20 && change >= 10) {
		cout << change / 10 << " Dime\n";
		change -= 10;
	}
	else if (change >= 20) {
		cout << change / 10 << " Dimes\n";
		change -= ((change / 10) * 10);
	}

	//nickles
	if (change < 10 && change >= 5) {
		cout << change / 5 << " Nickel\n";
		change -= 5;
	}
	else if (change >= 10) {
		cout << change / 5 << "Nickels\n";
		change -= ((change / 5) * 5);
	}

	//pennies
	if (change == 1) {
		cout << 1 << " Penny\n";
	}
	else if (change < 5 && change >= 1) {
		cout << change / 1 << " Pennies\n";
	}


	return 0;
}