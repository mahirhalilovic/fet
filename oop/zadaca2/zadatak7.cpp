#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {

  vector<string> v;
  string k;

  cout << "Unesi rijec: ";
  
  while(cin >> k) {
    
    v.push_back(k);
    cout << "Unesi rijec: ";
  }

  cout << endl;

  sort(v.begin(), v.end());

  int max = v.at(0).length();

  for(int i = 1; i < v.size(); i++)
    if(max < v.at(i).length())
      max = v.at(i).length();

  string plusici(max + 4, '+');
  string red(max + 2, ' ');

  cout << plusici << endl;
  cout << "+" << red << "+" << endl;

  for(int i = 0; i < v.size(); i++) {

    cout << "+ ";

    cout << v.at(i);
    string space(max - v.at(i).length(), ' ');
    cout << space;

    cout << " +" << endl;
  }

  cout << "+" << red << "+" << endl;
  cout << plusici;

  return 0;
}
