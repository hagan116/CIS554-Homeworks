/*
    Sam Hagan
    CIS 554 Homework 6
    setTest.cpp

    This file contains a main() method which tests the methods of the Set class.
*/
#include "set.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v1; // Create a vector and add values
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(8);
    v1.push_back(9);
    v1.push_back(15);
    v1.push_back(16);
    v1.push_back(17);
    v1.push_back(18);
    Set s1(v1); // Create a Set using the vector
    cout << "Set 1:" << endl;
    s1.print(); // Print the Set
    
    vector<int> v2; // Create a second vector and add values
    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(7);
    v2.push_back(9);
    v2.push_back(11);
    v2.push_back(13);
    v2.push_back(16);
    v2.push_back(18);
    Set s2(v2); // Create a second Set using the second vector
    cout << "Set 2:" << endl;
    s2.print(); // Print the second Set
    
    cout << "Union of Sets 1 and 2:" << endl;
    Set unionTest = s1.unionSet(s2); // Test the Set union method
    unionTest.print();
    
    cout << "Intersection of Sets 1 and 2:" << endl;
    Set intersectionTest = s1.intersectionSet(s2);
    intersectionTest.print();
    return 0;
}
