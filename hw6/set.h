/*
	Sam Hagan
	CIS 554 Homework 6
	set.h

	This is a header file for the Set class.
*/
#include <vector>
using namespace std;

class Set {
public:
	Set();
    Set(vector<int> &);
    bool isMember(int);
    Set unionSet(Set &);
    Set intersectionSet(Set &);
    void setValues(vector<int> &);
    void print();
private:
    vector<bool> values;
};
