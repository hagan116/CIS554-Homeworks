/*
  Sam Hagan
  CIS 554 Homework 2
  worker.h

  A header file for the Worker class.
*/

#include <string>

class Worker{

 public:
  Worker();
  void calculatePay();
 private:
  int hourlyPay, managerPay, commissionPay, piecePay;
  void printChart();
  void addHourly();
  void addManager();
  void addCommission();
  void addPiece();
};
