#include <iostream>
#include <cstdlib>
using namespace std;

/* Define your function here */
string HeadsOrTails(int loops) {
	int randNum;
	string coinSide;

	for (int i = loops; i > 0; i--) {
		randNum = rand() % 2;
		if (randNum == 1) {
			coinSide += "tails\n";
		}
		else {
			coinSide += "heads\n";
		}

	}	
	return coinSide;
}

int main() {
	
	srand(2);  // Unique seed

	int loops;
	cin >> loops;

	cout << HeadsOrTails(loops);

	return 0;
}
