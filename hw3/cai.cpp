/*
  Sam Hagan
  CIS 554 Homework 3
  cai.cpp

  This class implements a CAI object that performs Computer-Assisted Instruction.
  Creating a CAI object and calling startTest(), the class' only public method,
  asks the user five random multiplication and division questions. Once the user has
  correctly answered all questions, the test ends and information regarding the
  user's performance is printed.
*/

#include <cstdlib>
#include "cai.h"
#include <iostream>
using namespace std;

/*
  The CAI class constructor. A counter for how many questions are answered on
  the first try is initialized to zero. A counter for the total wrong answers
  the user enters is initialized to zero.
*/
CAI::CAI() {
  firstTries = 0;
  wrongGuesses = 0;
}

/*
  A method that starts the users' test. This method asks the user
  five multiplication questions, five division questions, and
  prints a summary of how the test went
*/
void CAI::startTest(){
  for (int i = 0; i < 5; i++){ // Loop for five multiplication questions
    askRandomMultiplicationQuestion();
  }
  for (int i = 5; i < 10; i++){ // Loop for five division questions
    askRandomDivisionQuestion();
  }
  printTestSummary(); // Print the test summary
}

/*
  A method that prints a random congratulatory message.
*/
void CAI::printRandomGoodJob(){
  int randomNum = rand() % 4 + 1; // Generate a random number between 1 and 4
  switch (randomNum) { // Print a message depending on the number generated
  case 1: 
    cout << "Very good!" << endl;
    break;
  case 2:
    cout << "Excellent!" << endl;
    break;
  case 3:
    cout << "Nice work!" << endl;
    break;
  case 4:
    cout << "Keep up the good work!" << endl;
    break;
  }
}

/*
  A message that prints a random encouragement message
*/
void CAI::printRandomEncouragementMessage(){
  int randomNum = rand() % 4 + 1; // Generate a random number between 1 and 4
  switch (randomNum) { // Print a message depending on the number generated
  case 1:
    cout << "No. Please try again." << endl;
    break;
  case 2:
    cout << "Wrong. Try once more." << endl;
    break;
  case 3:
    cout << "Don't give up!" << endl;
    break;
  case 4:
    cout << "No. Keep trying." << endl;
    break;
  }
}

/*
  A method that generates and returns a random number between 1 and 10.
*/
int CAI::chooseRandomNumber(){
  int randomNum = rand() % 10 + 1;
  return randomNum;
}

/*
  A method that asks the user a random multiplication question using two random
  numbers between 1 and 10. The method loops infinitely, encouraging the user
  until the correct answer is entered, at which point a congratulatory message
  is printed, instance variables are updated, and the method returns.
*/
void CAI::askRandomMultiplicationQuestion(){
  bool correct = false;
  int count = 1;
  int x = chooseRandomNumber(); // Generate two random numbers
  int y = chooseRandomNumber();
  int correctAnswer = x * y; // Calculate the correct answer
  int userAnswer;
  while (!correct){ // While the user has not entered the correct answer
    cout << "How much is " << x << " times " << y << "?" << endl;
    cin >> userAnswer; // Store the user answer
    if (userAnswer == correctAnswer){ // If the user enters the correct answer
      printRandomGoodJob(); // Print a congratulatory message
      correct = true;  // Set correct to true to break out of while loop
      if (count == 1){ // If the question was answered on the first try
	firstTries++;  // Update the first try counter
      }
      else { // Not the first try
	count--; // Decrement count to represent the number of wrong guesses for this question
	wrongGuesses += count; // Update the total wrong guesses instance variable
      }
    }
    else { // The user's answer is incorrect
      printRandomEncouragementMessage(); // Print an encouraging message
      count++; // Increment the counter tracking while loop iterations
    }
  }
}

/*
  A method that asks the user a random division question using two random
  numbers between 1 and 10. The method loops infinitely, encouraging the user
  until the correct answer is entered, at which point a congratulatory message
  is printed, instance variables are updated, and the method returns.
*/
void CAI::askRandomDivisionQuestion(){
  bool correct = false;
  int count = 1;
  int x = chooseRandomNumber(); // Generate two random numbers
  int y = chooseRandomNumber();
  while ((x%y) != 0){ // Ensure that x is evenly divisible by y
    x = chooseRandomNumber();
    y = chooseRandomNumber();
  }
  double correctAnswer = x / y; // Calculate the correct answer
  double userAnswer;
  while (!correct){ // While the user has not entered the correct answer
    cout << "How much is " << x << " divided by " << y << "?" << endl;
    cin >> userAnswer; // Store the user's answer
    if (userAnswer == correctAnswer){ // If the user enters the correct answer
      printRandomGoodJob(); // Print a congratulatory message
      correct = true; // Set correct to true to break out of while loop
      if (count== 1){ // If the question was answered on the first try
	firstTries++; // Update the first try counter
      } 
      else { // Not the first try
	count--; // Decrement count to represent the number of wrong guesses for this question
	wrongGuesses += count; // Update the total wrong guesses instance variable
      }
    }
    else { // The user's answer is correct
      printRandomEncouragementMessage(); // Print an encouraging message
      count++; // Increment the counter tracking while loop iterations
    }
  }
}

/*
  A method that prints a summary of the test results. Relevant information includes:
  number of questions answered on the first try, and average number of wrong guesses
  for questions answered with more than 1 try.
*/
void CAI::printTestSummary(){
  cout << "Number of questions answered on the first try: " << firstTries << endl;
  int questions = 10 - firstTries;
  int averageWrongGuesses = wrongGuesses / questions;
  cout << "Average number of wrong guesses: " << averageWrongGuesses << endl;
}
