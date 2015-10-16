/*
  Sam Hagan
  CIS 554 Homework 3
  cai.h

  A header file for the CAI class.
*/

#include <string>
using namespace std;
class CAI {

 public:
  CAI();
  void startTest();

 private:
  void printRandomGoodJob();
  void printRandomEncouragementMessage();
  void askRandomMultiplicationQuestion();
  void askRandomDivisionQuestion();
  int chooseRandomNumber();
  void printTestSummary();
  int firstTries;
  int wrongGuesses;
};
