/*
  Sam Hagan
  CIS554 Homework 4
  main.cpp

  This files contains a main() function that fills arrays
  and vectors with random integers, sorts them using iterative
  and recursive versions of selection sort, and outputs
  the runtime of the sorting algorithms for comparison.
*/

#include "selectionSort.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
//#include "TimeStamp.h"
using namespace std;


void arrayTest();
void vectorTest();
void timeTest();
void copyArray(int [], int [], const int);

/*
  A method that prints the contents of an array or vector
*/
template<typename T>
void printData(T data, unsigned int size){
  cout << "[";
  for (int i = 0; i < size; i++){
    if (i == (size-1)){
      cout << data[i] << "]";
      break;
    }
    cout << data[i] << ", ";
  }
  cout << endl;
}

/*
  A method that fills an array or vector with random integers
  between 0 and 1000.
*/
template<typename T>
void fillRandomData(T &data, unsigned int size){
  for (int i = 0; i < size; i++){
    int r = rand() % 1000 +1;
    data[i] = r;
  }
}

int main(){
  arrayTest();
  vectorTest();
  timeTest();
  return 0;
}

/*
  A method that tests the selection sort implementation provided
  in SelectionSort.cpp on arrays of size 20. Both the recursive and
  iterative implementations are tested.
*/
void arrayTest(){
    const int size = 20;
    int a1[size];
    int a2[size];
    SelectionSort s;
    cout << "Array test:" << endl;
    fillRandomData(a1, size);
    cout << "Random array for iterative sort:" << endl;
    printData(a1, size);
    s.iterativeSort(a1, size);
    cout << "Same array sorted:" << endl;
    printData(a1, size);
    fillRandomData(a2, size);
    cout << "Another random array for recursive sort:" << endl;
    printData(a2, size);
    s.recursiveSort(a2, size);
    cout << "Same array sorted:" << endl;
    printData(a2, size);
    cout << endl;
}
/*
  A method that tests the selection sort implementation provided
  in SelectionSort.cpp on vectors of size 20. Both the recursive and
  iterative implementations are tested.
*/
void vectorTest(){
  const int size = 20;
  vector<int> v1(size);
  vector<int> v2(size);
  SelectionSort s;
  cout << "Vector test:" << endl;
  fillRandomData(v1, size);
  cout << "Random vector for iterative sort:" << endl;
  printData(v1, size);
  s.iterativeSort(v1, size);
  cout << "Same vector sorted:" << endl;
  printData(v1, size);
  fillRandomData(v2, size);
  cout << "Another vector array for recursive sort:" << endl;
  printData(v2, size);
  s.recursiveSort(v2, size);
  cout << "Same vector sorted:" << endl;
  printData(v2, size);
  cout << endl;
}

/*
  A method that tests the runtime of iterative and recursive
  selection sort algorithm implementations. Runtime is tested on
  large arrays and vectors.
*/
void timeTest(){
  const int size = 10000;
  int a[size];
  int a2[size];
  vector<int> v(size);
  SelectionSort s;
  //TimeStamp ts;
  string timestring;
  
  fillRandomData(a, size);
  copyArray(a,a2,size);
  //timestring = ts.GetTime();
  //cout << timestring << endl;
  s.iterativeSort(a,size);
  //timestring = ts.GetTime();
  //cout << timestring << endl;
  
  //timestring = ts.GetTime();
  //cout << timestring <<endl;
  s.recursiveSort(a2,size);
  //timestring = ts.GetTime();
  //cout << timestring <<endl;

  
  fillRandomData(v, size);
  vector<int> v2 = v;
  
  //timestring = ts.GetTime();
  //cout << timestring <<endl;
  s.iterativeSort(v,size);
  //timestring = ts.GetTime();
  //cout << timestring <<endl;

  //timestring = ts.GetTime();
  //cout << timestring <<endl;
  s.recursiveSort(v2,size);
  //timestring = ts.GetTime();
  //cout << timestring <<endl;
  
}

/*
  A method that copies the contents of one array into another
*/
void copyArray(int a[], int b[], const int size){
  for (int i = 0; i < size; i++){
    b[i] = a[i];
  }
}
