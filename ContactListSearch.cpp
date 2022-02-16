#include <iostream>
#include <vector>
using namespace std;

string GetPhoneNumber(vector<string> nameVec, vector<string> phoneNumberVec, string contactName) {
	for (int i = 0; i < nameVec.size(); i++) {
		if (nameVec[i] == contactName) {
			return phoneNumberVec[i];
		}
	}
}

int main() {
	int num; //num of contacts the list is gonna have
	string searchName;
	vector<string> nameVec;
	vector<string> phoneNumVec;

	cin >> num;

	string inputName;
	string inputPhone;
	for (int i = 0; i < num; i++) {
		cin >> inputName;
		cin >> inputPhone;
		nameVec.push_back(inputName);
		phoneNumVec.push_back(inputPhone);
	}

	cin >> searchName;

	cout << GetPhoneNumber(nameVec, phoneNumVec, searchName) << endl;

	return 0;
}
