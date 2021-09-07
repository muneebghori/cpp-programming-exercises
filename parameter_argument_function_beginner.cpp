#include <iostream>
//prints my name as many time as my age
void name_x_age_times(std::string name, int x){
  while(x > 0){
    std::cout << name << "\n";
    x-=1;
  }
}


int main() {
  
  std::string my_name = "Muneeb Ghori";
  int age = 21;
  name_x_age_times(my_name, age);
  
}