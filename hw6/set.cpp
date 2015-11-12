/*
    Sam Hagan
    CIS 554 Homework 6
    set.cpp

    This file contains the implementation of the Set class. A Set is a size 21 vector
    of type bool. If a truth value at a given index is set to true, then that index is
    in the set. For example, if values[5] is true, then 5 is in the set.
*/
#include "set.h"
#include <iostream>
#include <vector>
using namespace std;

// Default constructor which initializes an empty Set.
Set::Set() : values(21,false){}


// A constructor which initializes the Set using an input vector of ints.
Set::Set(vector<int> & v) : values(21,false){
    for (int i = 0; i < v.size(); i++){
        if (v[i] > 20){
            cout << "Input value too high";
            continue;
        }
        values[v[i]] = true;
    }
}

// A method that return whether or not an integer is in the Set.
bool Set::isMember(int x){
    if (x > 20){
        return false;
    }
    return values[x];
}

// A method that returns the intersection between this Set and a parameter Set s.
Set Set::intersectionSet(Set & s){
    vector<int> hold;
    for (int i = 0; i < values.size(); i++){
        if (this->isMember(i) && s.isMember(i)){
            hold.push_back(i);
        }
    }
    Set result(hold);
    return result;
}

// A method that returns the union of this Set and a parameter Set s.
Set Set::unionSet(Set & s){
    vector<int> hold;
    for (int i = 0; i < values.size(); i++){
        if (this->isMember(i) || s.isMember(i)){
            hold.push_back(i);
        }
    }
    Set result(hold);
    return result;
}

// A setter method that sets the values of a Set using a parameter vector v.
void Set::setValues(vector<int> & v){
    for (int i = 0; i < v.size(); i++){
        if (v[i] > 20){
            cout << "Input value too high";
            continue;
        }
        values[v[i]] = true;
    }
}

//A method that prints the contents of this Set.
void Set::print(){
    cout << "[";
    for (int i = 0; i < values.size(); i++){
        if (this->isMember(i)){
            if (i == (values.size()-1)){
                cout << i;
            }
            else {
                cout << i << "," << " ";
            }
        }
    }
    cout << "]";
    cout << endl;
}