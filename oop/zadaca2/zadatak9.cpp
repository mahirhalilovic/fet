#include <iostream>
#include <vector>
#include <string>

int main() {

  std::vector<std::string> v;
  std::string k;
  int numChar = 0, maxChar = 0, maxIndex = 0;

  std::cout << "Unesi rijec: ";

  while(std::cin >> k) {

    v.push_back(k);
    std::cout << "Unesi rijec: ";
  }

  std::cout << std::endl;

  std::cout << "======================================" << std::endl;

  std::cout << "Lista rijeci" << std::endl;

  for(int i = 0; i < v.size(); i++) {

    if(maxChar < v.at(i).length()) {
      
      maxChar = v.at(i).length();
      maxIndex = i;
    }
    numChar += v.at(i).length();
    std::cout << v.at(i) << " ";
  }

  std::cout << std::endl << "Ukupan broj karaktera: " << numChar << std::endl; 

  std::cout << "======================================" << std::endl;

  std::cout << "Najduza rijec" << std::endl;

  std::string plusici(maxChar + 4, '+');
  std::string red(maxChar + 2, ' ');

  std::cout << plusici << std::endl;
  std::cout << "+" << red << "+" << std::endl;
  std::cout << "+ " << v.at(maxIndex) << " +" << std::endl;
  std::cout << "+" << red << "+" << std::endl;
  std::cout << plusici;

  return 0;
}
