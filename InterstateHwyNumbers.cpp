#include <iostream>
using namespace std;

int main() {
	int highwayNumber;
	int servingHwy;

	cin >> highwayNumber;

	if (highwayNumber == 0 || highwayNumber > 999) {
		cout << highwayNumber << " is not a valid interstate highway number." << endl;
	}
	else if (highwayNumber % 2 == 0 && highwayNumber < 100) {
		cout << "I-" << highwayNumber << " is primary, going east/west." << endl;
	}
	else if (highwayNumber % 2 != 0 && highwayNumber < 100) {
		cout << "I-" << highwayNumber << " is primary, going north/south." << endl;
	}
	else if (highwayNumber % 2 == 0 && highwayNumber > 99) {
		servingHwy = highwayNumber % 100;
		cout << "I-" << highwayNumber << " is auxiliary, serving I-" << servingHwy << ", going east/west." << endl;
	}
	else if (highwayNumber % 2 != 0 && highwayNumber > 99) {
		servingHwy = highwayNumber % 100;
		cout << "I-" << highwayNumber << " is auxiliary, serving I-" << servingHwy << ", going north/south." << endl;
	}
	return 0;
}
