#include <iostream>
#include <string>

void hamming(std::string str1, std::string str2) {

  int s = 0;

  for(int i = 0; i < str1.length(); i++)
    if(str1[i] != str2[i])
      s++;

  std::cout << "Hammingova udaljenost izmedju stringova je " << s << ".";
}

int main() {

  std::string rijec1, rijec2;

  do{

    std::cout << "Unesite prvu rijec: ";
    std::cin >> rijec1;
    std::cout << "Unesite drugu rijec: ";
    std::cin >> rijec2;

    if(rijec1.length() != rijec2.length())
      std::cout << "Rijeci moraju biti iste duzine." << std::endl;
  }while(rijec1.length() != rijec2.length());

  for(int i = 0; i < rijec1.length(); i++) {

    rijec1[i] = tolower(rijec1[i]);
    rijec2[i] = tolower(rijec2[i]);
  }

  hamming(rijec1, rijec2);

  return 0;
}
