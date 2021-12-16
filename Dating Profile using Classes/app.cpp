#include <iostream>
#include "profile.h"
using namespace std;

int main() {

	//create profile with some information
	Profile muneeb("Muneeb", 21, "Irvine", "USA", "He/Him");
	//Add Hobbies
	muneeb.addHobby("Hiking");
	muneeb.addHobby("Running");
	//view profile
	muneeb.getProfile();
}