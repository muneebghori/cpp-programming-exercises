#include <iostream>
//outputting 1 - 100
//for every # divisible by 3, outputting Fizz
//for every # divisible by 5, outputting Buzz
//for every # divisible by both 3 & 5, outputting FizzBuzz

int main (){

for (int i = 1; i <= 100; i++){
  if (i % 3 == 0){
    std::cout << "Fizz\n";
  } else if (i % 5 == 0) {
      std::cout << "Buzz\n";
  } else if ((i % 3 == 0) && (i % 5 == 0)){
      std::cout << "FizzBuzz\n";
  } else {
    std::cout << i << "\n";
  }
}


}