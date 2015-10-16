/*
  Sam Hagan
  CIS554 Homework 4
  selectionSort.cpp

  This file contains the implementation of the SelectionSort class.
  Recursive and iterative implementations of selection sort are provided,
  and overloaded to accept either arrays or vectors.
*/

#include "selectionSort.h"
#include <iostream>
using namespace std;

/*
  A method that asks the user if they wish to use recursive selection
  sort to sort an array in ascending or descending order. 
*/
void SelectionSort::recursiveSort(int a[], const int size){
  int input;
  bool valid = false;
  while (!valid){ // loop until valid input is entered
    cout << "Press 1 for ascending, 2 for descending: " << endl;
    cin >> input;
    switch (input){
    case 1:
      valid = true;
      recursiveSortAscending(a,size,0);
      break;
    case 2:
      valid = true;
      recursiveSortDescending(a,size,0);
      break;
    default:
      cout << "Invalid input." << endl;
      break;
    }
  }

}
/*
  A method that uses a recursive implementation of selection sort to sort an array
  in ascending order
*/
void SelectionSort::recursiveSortAscending(int a[], const int size, int place){
  int smallest = place;
  for (int j = place + 1; j < size; j++){
    if (a[j] < a[smallest]){
      smallest = j;
    }
  }
  swap(&a[place], &a[smallest]);
  if (place < (size-1)){
    place++;
    recursiveSortAscending(a,size,place);
  }
}

/*
  A method that uses a recursive implementation of selection sort to sort an array
  in descending order.
*/
void SelectionSort::recursiveSortDescending(int a[], const int size, int place){
  int largest = place;
  for (int j = place + 1; j < size; j++){
    if (a[j] > a[largest]){
      largest = j;
    }
  }
  swap(&a[place], &a[largest]);
  if (place < (size-1)){
    place++;
    recursiveSortDescending(a,size,place);
  }
}

/*
  A method that asks the user if the wish to use iterative selection sort
  to sort an array in ascending or descending order
*/
void SelectionSort::iterativeSort(int a[], const int size){
  int input;
  bool valid = false;
  while (!valid){
    cout << "Press 1 for ascending, 2 for descending: " << endl;
    cin >> input;
    switch (input){
    case 1:
      valid = true;
      iterativeSortAscending(a, size);
      break;
    case 2:
      valid = true;
      iterativeSortDescending(a, size);
      break;
    default:
      cout << "Invalid input." << endl;
      break;
  }
  }
}

/*
  A method that uses an iterative selection sort to sort an array in ascending order.
*/
void SelectionSort::iterativeSortAscending(int a[], const int size){
  int smallest;
  for (int i = 0; i < size - 1; i++){
    smallest = i;
    for (int j = i + 1; j < size; j++){
      if (a[j] < a[smallest]){
	smallest = j;
      }
    }
    swap(&a[i], &a[smallest]);
  }
}

/*
  A method that uses an iterative selection sort to sort and array in descending order.
*/
void SelectionSort::iterativeSortDescending(int a[], const int size){
  int largest;
  for (int i = 0; i < size - 1; i++){
    largest = i;
    for (int j = i + 1; j < size; j++){
      if (a[j] > a[largest]){
        largest = j;
      }
    }
    swap(&a[i], &a[largest]);
  }

}

/*
  A method that asks the user if they wish to use recursive selection sort
  to sort a vector in ascending or descending order.
*/
void SelectionSort::recursiveSort(vector<int> &a, const int size){
  int input;
  bool valid = false;
  while (!valid){
    cout << "Press 1 for ascending, 2 for descending: " << endl;
    cin >> input;
    switch (input){
    case 1:
      valid = true;
      recursiveSortAscending(a,size,0);
      break;
    case 2:
      valid = true;
      recursiveSortDescending(a,size,0);
      break;
    default:
      cout << "Invalid input." << endl;
      break;
    }
  }
}

/*
  A method that sorts a vector in ascending order using recursive selection sort
*/
void SelectionSort::recursiveSortAscending(vector<int> &a, const int size, int place){
  int smallest = place;
  for (int j = place + 1; j < size; j++){
    if (a[j] < a[smallest]){
      smallest = j;
    }
  }
  swap(&a[place], &a[smallest]);
  if (place < (size-1)){
    place++;
    recursiveSortAscending(a,size,place);
  }
}

/*
  A method that sorts a vector in descending order using recursive selection sort.
*/
void SelectionSort::recursiveSortDescending(vector<int> &a, const int size, int place){
  int largest = place;
  for (int j = place + 1; j < size; j++){
    if (a[j] > a[largest]){
      largest = j;
    }
  }
  swap(&a[place], &a[largest]);
  if (place < (size-1)){
    place++;
    recursiveSortDescending(a,size,place);
  }
}

/*
  A method that asks the user if they want to use iterative selection sort to sort
  a vector in ascending or descending order.
*/
void SelectionSort::iterativeSort(vector<int> &a, const int size){
  int input;
  bool valid = false;
  while (!valid){
    cout << "Press 1 for ascending, 2 for descending: " << endl;
    cin >> input;
    switch (input){
    case 1:
      valid = true;
      iterativeSortAscending(a, size);
      break;
    case 2:
      valid = true;
      iterativeSortDescending(a, size);
      break;
    default:
      cout << "Invalid input." << endl;
      break;
    }
  }
}

/*
  A method that sorts a vector in ascending order using iterative selection sort
*/
void SelectionSort::iterativeSortAscending(vector<int> &a, const int size){
  int smallest;
  for (int i = 0; i < size - 1; i++){
    smallest = i;
    for (int j = i + 1; j < size; j++){
      if (a[j] < a[smallest]){
        smallest = j;
      }
    }
    swap(&a[i], &a[smallest]);
  }
}

/*
  A method that sorts a vector in descending order using iterative selection sort
*/
void SelectionSort::iterativeSortDescending(vector<int> &a, const int size){
  int largest;
  for (int i = 0; i < size - 1; i++){
    largest = i;
    for (int j = i + 1; j < size; j++){
      if (a[j] > a[largest]){
        largest = j;
      }
    }
    swap(&a[i], &a[largest]);
  }
}

/*
  A method that swaps the values at two entries of an array or vector
*/
void SelectionSort::swap(int * const a1, int * const a2){
  int holder = *a1;
  *a1 = *a2;
  *a2 = holder;
}
