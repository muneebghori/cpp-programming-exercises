#include "profile.h"

using namespace std;
//constructor
Profile::Profile(string new_name, int new_age, string new_city, string new_country, string new_pronouns) {
    name = new_name;
    age = new_age;
    city = new_city;
    country = new_country;
    pronouns = new_pronouns;
};

//deconstructor
Profile::~Profile() {
    std::cout << "\nDeconstructor Activated!\n";
};

//get profile function
void Profile::getProfile() {
    cout << "\n" << name << "'s Profile: \n";
    cout << "Age: " << age << "\n";
    cout << "City: " << city << "\n";
    cout << "Country: " << country << "\n";
    cout << "Pronouns: " << pronouns << "\n";
    cout << "Hobbies: ";
    for (int i = 0; i < hobbies.size(); i++) {
        cout << hobbies[i] << ", ";
    }
    cout << "\n";
    
}

//add hobby funciton
void Profile::addHobby(string new_hobby) {
    hobbies.push_back(new_hobby);
};