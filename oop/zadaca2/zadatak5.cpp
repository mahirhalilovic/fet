#include <iostream>
#include <vector>

int main() {

  int k, suma = 0, proizvod = 1, minDigit, maxDigit;
  std::vector<int> v;

  std::cout << "Unesite cijeli broj: ";
  std::cin >> k;

  while(k > 0) {

    v.push_back(k % 10);
    k /= 10;
  }

  minDigit = v.at(0);
  maxDigit = v.at(0);

  for(int i = 0; i < v.size(); i++) {

    std::cout << v.at(i);
    if(v.at(i) > maxDigit)
      maxDigit = v.at(i);
    if(v.at(i) < minDigit)
      minDigit = v.at(i);

    suma += v.at(i);
    proizvod *= v.at(i);
  }

  std::cout << std::endl << minDigit << std::endl << maxDigit << std::endl << suma << std::endl << proizvod;

  return 0;
}
