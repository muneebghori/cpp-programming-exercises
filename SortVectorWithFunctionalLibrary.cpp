#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void SortVector(vector<int> &myVec) {
	sort(myVec.begin(), myVec.end(), less<int>());
}

int main() {

	int numNums;

	cin >> numNums;

	vector<int> myVec;

	for (int i = 0; i < numNums; i++) {
		int vecInt = 0;
		cin >> vecInt;
		myVec.push_back(vecInt);
	}

	SortVector(myVec);

	for (int i = 0; i < numNums; i++) {
		cout << myVec[i] << " ";
	}
	cout << endl;

	return 0;
}
