/* Napisati funkciju provjeri_zagrade() koja provjerava da li su zagrade
 u nekom stringu korektno zatvorene, te shodno tome vraca tacno ili netacno. Primjer: 
 { [ ( ) ] } -> True
 { [ 3 * ( 2 + 3 ) + 2 ] } -> True
 { [ ( ) } ] -> False 

Zatim napisati main funkciju tako da korisnik unosi recenice sve dok ne unese EOF karakter.
Za svaki unos pozvati funkciju provjeri_zagrade() i kao rezultat ispisati "OK", ako je 
povratna vrijednost true, odnosno ispisati "Error", ako je povratna vrijednost false. */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool provjeri_zagrade(string str) {

  vector<char> otv;

  for(int i = 0; i < str.length(); i++) {

    if(str[i] == '(' || str[i] == '[' || str[i] == '{')
      otv.push_back(str[i]);
    else if(str[i] == ')')
      if(otv.size())
        if(otv.at(otv.size() - 1) == '(')
          otv.pop_back();
        else
          return false;
      else
        return false;
    else if(str[i] == ']')
      if(otv.size())
        if(otv.at(otv.size() - 1) == '[')
          otv.pop_back();
        else
          return false;
      else
        return false;
    else if(str[i] == '}')
      if(otv.size())
        if(otv.at(otv.size() - 1) == '{')
          otv.pop_back();
        else
          return false;
      else
        return false;
  }

  return true;
}

int main() {
  
  string foo;

  while(getline(cin, foo))
    if(provjeri_zagrade(foo))
      cout << "OK" << endl;
    else
      cout << "Error" << endl;

  return 0;
}
