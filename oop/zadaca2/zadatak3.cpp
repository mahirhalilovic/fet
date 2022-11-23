#include <iostream>

int main() {

  int a;

  std::cout << "Unesite cijeli broj: ";
  std::cin >> a;

  for(int i = 3; i <= a; i++) {

    for(int j = 2; j < i; j++) {

      for(int k = 1; k < j; k++) {

        if(k*k + j*j == i*i)
          std::cout << "(" << k << ", " << j << ", " << i << ")" << std::endl;
      }
    }
  }

  return 0;
}
