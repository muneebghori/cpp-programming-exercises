#include <iostream>
#include <vector>
#include <fstream> //for inputting files

using namespace std;

int main() {
	int e;
	int n;
	cout << "Enter e for the RSA Public Key P=(e,n): ";
	cin >> e;
	cout << "\nEnter n for the RSA Public Key P=(e,n): ";
	cin >> n;
	cout << endl;

	//array of the 25 primes between 1 and 100
	int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

	//Find P & Q
	int p = 0;
	int q = 0;
	for (int i = 0; i < 25; i++) {
		if (n % primes[i] == 0) {
			if (p == 0) {
				p = primes[i];
			}
			else {
				q = primes[i];
			}
		}
	}

	//if input was invalid, the program will quit.
	if (p == 0 || q == 0) {
		cout << "Error: Invalid Input. Restart program to retry." << endl;
		exit(0);
	}

	//Insert file with encoded message
	string fileName;
	cout << "Enter the name of the file that contains the encoded message: ";
	cin >> fileName;
	cout << endl;
	ifstream encryptedFile (fileName);
	int encryptedInput;
	vector<int> encryptedNums;
	while (encryptedFile >> encryptedInput) {
		encryptedNums.push_back(encryptedInput);
	}

	/*for (string message : encryptedNums) {
		cout << message << " ";
	}*/

	//finds phi(n) totient value
	int totient;
	totient = (p - 1) * (q - 1);

	//finds d = (inverse of e) mod phi(n)
	int d = 0;
	for (int i = 0; i < totient; i++) {
		if (((e % totient) * (i % totient)) % totient == 1) {
			d = i;
		}
	}
	//outputting all found values
	cout << "p: " << p << " q: " << q << " phi(n): " << totient << " d: " << d << endl << endl;

	//decryption step
	cout << "Decoded message in Ints: \n";
	vector<int> decryptedNums;
	for (int i = 0; i < encryptedNums.size(); i++) {
		int tempd = d;
		//breaking down (C^d mod n) and computing since C^d is too large
		int modTemp = 1;
		while (tempd >= 3) {
			modTemp *= ((encryptedNums[i] * encryptedNums[i]) % n);
			tempd -= 2;
			modTemp %= n;
		}

		if (tempd == 2) {
			modTemp *= (encryptedNums[i] * encryptedNums[i]);
			modTemp = modTemp % n;
		}
		else if (tempd == 1) {

			modTemp *= encryptedNums[i];
			modTemp = modTemp % n;
			cout << modTemp << " ";
		}
		else {
			modTemp = modTemp % n;
			cout << modTemp << " ";
		}
		decryptedNums.push_back(modTemp);
	}
	cout << endl;
	
	cout << endl << "Decrypted message in Enlgish: " << endl;
	//convert decryped ints to chars
	string decryptedEnglish;
	for (int i = 0; i < decryptedNums.size(); i++) {
		if (decryptedNums[i] == 3) {
			decryptedEnglish += "A";
		}
		else if (decryptedNums[i] == 4) {
			decryptedEnglish += "B";
		}
		else if (decryptedNums[i] == 5) {
			decryptedEnglish += "C";
		}
		else if (decryptedNums[i] == 6) {
			decryptedEnglish += "D";
		}
		else if (decryptedNums[i] == 7) {
			decryptedEnglish += "E";
		}
		else if (decryptedNums[i] == 😎 {
			decryptedEnglish += "F";
		}
		else if (decryptedNums[i] == 9) {
			decryptedEnglish += "G";
		}
		else if (decryptedNums[i] == 10) {
			decryptedEnglish += "H";
		}
		else if (decryptedNums[i] == 11) {
			decryptedEnglish += "I";
		}
		else if (decryptedNums[i] == 12) {
			decryptedEnglish += "J";
		}
		else if (decryptedNums[i] == 13) {
			decryptedEnglish += "K";
		}
		else if (decryptedNums[i] == 14) {
			decryptedEnglish += "L";
		}
		else if (decryptedNums[i] == 15) {
			decryptedEnglish += "M";
		}
		else if (decryptedNums[i] == 16) {
			decryptedEnglish += "N";
		}
		else if (decryptedNums[i] == 17) {
			decryptedEnglish += "O";
		}
		else if (decryptedNums[i] == 18) {
			decryptedEnglish += "P";
		}
		else if (decryptedNums[i] == 19) {
			decryptedEnglish += "Q";
		}
		else if (decryptedNums[i] == 20) {
			decryptedEnglish += "R";
		}
		else if (decryptedNums[i] == 21) {
			decryptedEnglish += "S";
		}
		else if (decryptedNums[i] == 22) {
			decryptedEnglish += "T";
		}
		else if (decryptedNums[i] == 23) {
			decryptedEnglish += "U";
		}
		else if (decryptedNums[i] == 24) {
			decryptedEnglish += "V";
		}
		else if (decryptedNums[i] == 25) {
			decryptedEnglish += "W";
		}
		else if (decryptedNums[i] == 26) {
			decryptedEnglish += "X";
		}
		else if (decryptedNums[i] == 27) {
			decryptedEnglish += "Y";
		}
		else if (decryptedNums[i] == 28) {
			decryptedEnglish += "Z";
		}
		else if (decryptedNums[i] == 29) {
			decryptedEnglish += " ";
		}
		else if (decryptedNums[i] == 30) {
			decryptedEnglish += "\"";
		}
		else if (decryptedNums[i] == 31) {
			decryptedEnglish += ".";
		}
		else if (decryptedNums[i] == 32) {
			decryptedEnglish += ",";
		}
		else if (decryptedNums[i] == 33) {
			decryptedEnglish += "'";
		}
	}
	cout << decryptedEnglish << endl;
}