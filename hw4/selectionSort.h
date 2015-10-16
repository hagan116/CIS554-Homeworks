/*
  Sam Hagan
  CIS554 Homework 4
  selectionSort.h

  This is a header file for the SelectionSort class.
*/

#include <vector>
using std::vector;

class SelectionSort{
 public:
  void recursiveSort(int [], const int);
  void recursiveSort(vector<int> &, const int);
  void iterativeSort(int [], const int);
  void iterativeSort(vector<int> &, const int);
 private:
  void swap(int * const, int * const);
  void recursiveSortAscending(int [], const int, int);
  void recursiveSortAscending(vector<int> &, const int, int);
  void iterativeSortAscending(int [], const int);
  void iterativeSortAscending(vector<int> &, const int);
  void recursiveSortDescending(int [], const int, int);
  void recursiveSortDescending(vector<int> &, const int, int);
  void iterativeSortDescending(int [], const int);
  void iterativeSortDescending(vector<int> &, const int);
};
