#include <iostream>
#include <cmath>

void resetReg(int arr[]) {

  for(int i = 0; i < 16; i++)
    arr[i] = 0;
}

int chooseRegister() {

  int reg;

  std::cout << "Choose a register: ";
  std::cin >> reg;

  return reg;
}

int startProcedure() {

  int option;

  std::cout << "1. Print register" << std::endl;
  std::cout << "2. Set bit in register" << std::endl;
  std::cout << "3. Reset bit in register" << std::endl;
  std::cout << "4. Swap register values" << std::endl;
  std::cout << "5. Exit" << std::endl;
  std::cout << "Enter option: ";
  std::cin >> option;

  return option;
}

int regValue(int arr[]) {

  int value;

  for(int i = 0; i < 16; i++)
    if(arr[i])
      value += pow(2, i);

  return value;
}

void printBits(int arr[]) {

  for(int i = 15; i >= 0; i--)
    std::cout << arr[i];

  std::cout << std::endl;
}

void setBit(int arr[]) {

  int bit;
  std::cout << "Enter bit number: ";
  std::cin >> bit;

  arr[bit] = 1;

  std::cout << "New register value: " << regValue(arr) << std::endl;
  printBits(arr);
}

void resetBit(int arr[]) {

 int bit;
  std::cout << "Enter bit number: ";
  std::cin >> bit;

  arr[bit] = 0;

  std::cout << "New register value: " << regValue(arr) << std::endl;
  printBits(arr); 
}

void swapReg(int arr1[], int arr2[]) {

  int temp[16];

  for(int i = 0; i < 16; i++) {

    temp[i] = arr1[i];
    arr1[i] = arr2[i];
    arr2[i] = temp[i];
  }
}

int main() {

  int reg1[16], reg2[16], reg, option;

  resetReg(reg1);
  resetReg(reg2);

  do{

    do{
      reg = chooseRegister();
    }while(reg == 1 || reg == 2);
    option = startProcedure();

    if(reg == 1) {

      if(option == 1)
        printBits(reg1);
      else if(option == 2)
        setBit(reg1);
      else if(option == 3)
        resetBit(reg1);
      else if(option == 4)
        swapReg(reg1, reg2);

      } 
      else if(reg == 2) {

        if(option == 1)
          printBits(reg2);
        else if(option == 2)
          setBit(reg2);
        else if(option == 3)
          resetBit(reg2);
        else if(option == 4)
          swapReg(reg1, reg2);
    }
 }while(option == 1 || option == 2 || option == 3 || option == 4);

  return 0;
}
