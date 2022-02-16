#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

vector<int> GetUserValues(vector<int>& userValues, int numValues) {
	for (int i = 0; i < numValues - 1; i++) {
		int val = 0;
		cin >> val;
		userValues.push_back(val);
	}
	return userValues;
}

void OutputIntsLessThanOrEqualToThreshold(vector<int> userValues, int upperThreshhold) {
	int smallest = *min_element(userValues.begin(), userValues.end());

	for (int i = 0; i < userValues.size(); i++) {
		if (userValues[i] < upperThreshhold + smallest) {
			cout << userValues[i] - smallest << " ";
		}
	}

	cout << upperThreshhold - smallest << " ";
}

int main() {
	vector<int> userValues;
	int upperThreshold;
	int numValues;

	cin >> numValues;
	userValues = GetUserValues(userValues, numValues);

	cin >> upperThreshold;
	OutputIntsLessThanOrEqualToThreshold(userValues, upperThreshold);

	cout << endl;

	return 0;
}
