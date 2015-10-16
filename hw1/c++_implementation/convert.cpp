/*
  Sam Hagan
  CIS554 Homework 1
  convert.cpp
  
  This class provides a function to convert number to decimal form.
*/


#include <iostream>
#include <math.h>
#include "convert.h"
using std::cout;
using std::endl;


/*
  Function converts a value and its base to decimal representation

  Returns a decimal representation of the given value
*/
int Convert::convert(int value, int base){
  int lsDigit;
  int result = 0;
  int count = 0;
  
  while (value > 0){
    lsDigit = value % 10; // Store the least significant digit in lsDigit
    if (lsDigit >= base){ // If the input is invalid, inform the user and return 0
      cout << "Invalid input." << endl;
      return 0;
    }
    else {
      result += (lsDigit * pow(base,count)); // Perform the conversion
      value = value / 10; // Remove the least significant digit
      count++; // Increase the count for use in calculation
    }
  }
  return result; // Return the result
}

// A recursive implementation of the above method
int Convert::recursiveConvert(int value, int base, int count){
  if (value == 0){
    return 0;
  }
  else {
    int lsDigit = value % 10;
    value = value / 10;
    int val = (lsDigit * pow(base,count));
    count++;
    return val + recursiveConvert(value,base,count);
  }
}
