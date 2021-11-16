#include <iostream>
#include <string>
#include <fstream>
using namespace std;
    
    //Adds a contact to Phonebook.txt
    void addContact(){
        ofstream outputFile;
        string contactName;
        string phoneNumber;

        outputFile.open("Phonebook.txt", ios::app);
        cout << "Enter the name of the contacts: ";
        cin >> contactName;
        cout << "Enter the phone number: ";
        cin >> phoneNumber;
        outputFile << contactName << " " << phoneNumber << endl;
        outputFile.close();
    }

    //Prints all the contacts in the phonebook
    void openPhonebook() {
        string contactName;
        int contactNumber;
        string phoneNum;
        ifstream inputFile;

        inputFile.open("Phonebook.txt");
        contactName = 1;
        while (inputFile.eof() == false) {

            inputFile >> contactName >> phoneNum;
            if (inputFile.fail())
            {
                break;
            }
            cout << "Contact " << contactNumber << ": " << contactName << " #: " << phoneNum << endl;
            contactNumber++;
        }
        inputFile.close();
    }

    //finds contact and outputs the number linked to that contact
    string findContact(){
        string contactName;
        string searchName;
        string phoneNum;
        ifstream inputFile;

        cout << "Enter name of contact (case sensitive)" << endl;
        cin >> contactName;
        inputFile.open("Phonebook.txt");
            while (inputFile.eof() == false)
            {
                inputFile >> searchName >> phoneNum;
                if (contactName == searchName)
                {
                    return phoneNum;
                }
            }
        return "\nContact does not exist!\n";
        inputFile.close();
    }

        

        int main() {
            int option;
            string phoneNum;

            do {
                cout << endl << "-= MENU =-" << endl;
                cout << "1) Add Contact" << endl << "2) Find Number" << endl << "3) Print Contacts" << endl << "4) Quit" << endl << endl;
                cin >> option;

                if (option == 1) {
                    addContact();
                }
                else if (option == 2) {
                    phoneNum = findContact();
                    if (phoneNum == " ") {
                        cout << "The contact does not exist! " << endl;
                    }
                    else {
                        cout << phoneNum << endl;
                    }
                }
                else if (option == 3) {
                    openPhonebook();
                }
            } while (option != 4);
            return 0;
        }