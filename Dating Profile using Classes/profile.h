#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Profile {
private:
    string name;
    int age;
    string city;
    string country;
    string pronouns;
    vector<string> hobbies;

public:
    Profile(string new_name, int new_age, string new_city, string new_country, string new_pronouns);

    ~Profile();

    void getProfile();

    void addHobby(string new_hobby);
};