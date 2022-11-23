#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void swap(int &a, int &b) {

  int temp = a;
  a = b;
  b = temp;
}

void bubbleSort(int arr[], int n) {

  for(int i = 0; i < n - 1; i++)
    for(int j = 0; j < n - i - 1; j++)
      if(arr[j] > arr[j+1])
        swap(arr[j], arr[j+1]);
}

void modulusSort(int arr[], int n) {

  for(int i = 0; i < n - 1; i++)
    for(int j = 0; j < n - i - 1; j++)
      if((arr[j] % 2 != 0) && (arr[j+1] % 2 == 0))
        swap(arr[j], arr[j+1]);
}

int main() {

  srand(time(NULL));

  int maxNums, drawnNums;

  cout << "Unesite ukupan broj kuglica: ";
  cin >> maxNums;

  cout << "Unesite broj kuglica za izvlacenje: ";
  cin >> drawnNums;

  int drawns[drawnNums], sorted[drawnNums], sorted2[drawnNums];

  for(int i = 0; i < drawnNums; i++) {

    drawns[i] = rand() % maxNums;
    sorted[i] = drawns[i];
  }

  bubbleSort(sorted, drawnNums);

  for(int i = 0; i < drawnNums; i++)
    sorted2[i] = sorted[i];

  modulusSort(sorted2, drawnNums);

  cout << "Izvuceno              Sortirano" << endl;
  cout << "--------------------------------------" << endl;
  
  for(int i = 0; i < drawnNums; i++) {
  
    int n, m;

    drawns[i] < 10 ? n = 17 : n = 16;
    sorted[i] < 10 ? m = 17 : m = 16;

    string spaces(n, ' ');
    string spaces2(m, ' ');

    cout << drawns[i] << spaces << sorted[i] << spaces2 << sorted2[i] << endl;
  }

  return 0;
}
