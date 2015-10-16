/*
  Sam Hagan
  CIS 554 Homework 2
  worker.cpp

  This class implements a worker object that tracks the total
  pay for various types of employees. It loops infinitely, recording
  weekly pay from user input, then prints a chart displaying
  the information once the user has finished.
*/


#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "worker.h"

/*
  The constructor for the worker class. Instance variables
  are initialized to zero, and each represents the total
  weekly pay for a specific type of worker.
*/ 
Worker::Worker() {
  hourlyPay = 0;
  commissionPay = 0;
  managerPay = 0;
  piecePay = 0;
}

/*
  This function contains an infinite loop that prompts the user for input.
  The user is prompted to enter a paycode, and appropriate functions are called
  depending on the entered code. 
*/
void Worker::calculatePay(){
  while (true){
    int paycode;
    cout << "Enter paycode (-1 to end): "; // Request paycode
    cin >> paycode;
    if (paycode == -1){ // If -1 is entered, break out of the loop
      break;
    }
    else{
      switch (paycode) { // Otherwise continue based on paycode selection
      case 1: 
	addManager(); // Add money to manager pay
	cout << endl;
	break;
      case 2:
	addHourly(); // Add money to hourly pay
	cout << endl;
	break;
      case 3:
	addCommission(); // Add money to commission pay
	cout << endl;
	break;
      case 4:
	addPiece(); // Add money to pieceworker pay
	cout << endl;
	break;
      default:
	cout << "Unknown paycode." << endl; // If unknown paycode, do nothing and loop continues
	cout << endl;
	break;
      
      }
    }
  }
  printChart(); // If the program reaches this function call,
                // -1 has been selected, so print chart
}

/*
  Function that prompts the user to enter a manager's pay.
*/
void Worker::addManager(){
  double salary;
  cout << "Manager selected." << endl;
  cout << "Enter weekly salary: ";
  cin >> salary;
  managerPay += salary; // Add user input to managerPay
  cout << "Manager's pay is $" << salary << endl;
}

/*
  Function that prompts the user to enter an hourly worker's pay.
*/
void Worker::addHourly(){
  double salary, hours, totalPay;
  cout << "Hourly worker selected." << endl;
  cout << "Enter the hourly salary: ";
  cin >> salary;
  cout << "Enter the total hours worked: ";
  cin >> hours;
  if (hours > 40){ // If the employee worked overtime, pay them time and a half
    hours -= 40;
    totalPay = (salary * 40) + (salary * hours);
    hourlyPay += totalPay;
  }
  else{ // If not, pay them their regular salary
    totalPay = hours * salary;
    hourlyPay += totalPay;
  }
  cout << "Worker's pay is $" << totalPay << endl;
  
}

/*
  Function that prompts the user to enter a commission Worker's pay.
*/
void Worker::addCommission(){
  double sales, totalPay;
  cout << "Commission worker selected." << endl;
  cout << "Enter gross weekly sales: ";
  cin >> sales;
  totalPay = 250 + (.057 * sales); // Add the users commission to their baseline salary
  commissionPay += totalPay;
  cout << "Commission Worker's pay is $" << totalPay << endl;
}

/*
  Function that prompts the user to enter a pieceworker's pay.
*/
void Worker::addPiece(){
  double pieces, wage, totalPay;
  cout << "Pieceworker selected." << endl;
  cout << "Enter number of pieces: ";
  cin >> pieces;
  cout << "Enter wage per piece: ";
  cin >> wage;
  totalPay = pieces * wage; // Multiply the number of pieces the employee makes by their wage per piece
  piecePay += totalPay; // Add the result to the overall pieceworker pay
  cout << "Pieceworker's pay is $" << totalPay << endl;
}

/*
  Function that prints a chart of '*'s indicating how much
  pay each type of worker made.

  Known bug: The '\t' character next to "Hourly" isn't working.
*/
void Worker::printChart(){
  cout << "Managers\t";
  for (int i = 0; i < (managerPay/100); i++){ // Print a '*' for every $100
    cout << "*";
  }
  cout << endl;
  cout << "Hourly\t"; // '\t' not working properly here
  for (int i = 0; i < (hourlyPay/100); i++){
    cout << "*";
  }
  cout << endl;
  cout << "Commission\t";
  for (int i = 0; i < (commissionPay/100); i++){
    cout << "*";
  }
  cout << endl;
  cout << "Pieceworker\t";
  for (int i = 0; i < (piecePay/100); i++){
    cout << "*";
  }
  cout << endl;
}
