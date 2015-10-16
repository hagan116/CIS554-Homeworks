/*
  Sam Hagan
  CIS554 Homework 1
  main.cpp

  This file contains a main function that prompts the user for a number input and its base.
  The function then converts the number to decimal form, and displays it to the user
*/

#include <iostream>
#include <string>
#include "convert.h"

int main() {

  using std::cout;
  using std::cin;
  using std::endl;
  
  int number;
  int base;

  // Prompt for user input
  cout << "Please enter a number: ";
  cin >> number; // Store the entered value in number
  cout << "Please enter its base: ";
  cin >> base; // Store the entered value in base
  
  Convert c;

  int answer = c.convert(number,base); // Convert
  //int answer = c.recursiveConvert(number,base,0); //alternative convert
  
  cout << "Answer: " << answer << endl;// Display answer


  return 0;
}
