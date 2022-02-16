#include <iostream>
using namespace std;

int main() {

	int red, green, blue;

	cin >> red >> green >> blue;

	int smallest;
	if (red < green) {
		smallest = red;
	}
	else {
		smallest = green;
	}

	if (blue < smallest) {
		smallest = blue;
	}

	red -= smallest;
	green -= smallest;
	blue -= smallest;

	cout << red << " " << green << " " << blue << endl;



	return 0;
}
