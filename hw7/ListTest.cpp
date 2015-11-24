#include "NodeSLList.h"
#include <iostream>
using namespace std;

void listTest();

int main(){
  listTest();
  return 0;
}

void listTest(){
	NodeSLList list1;

	IntNode n1;
    n1.data=10;
    IntNode n2;
    n2.data=20;
    IntNode n3;
    n3.data=30;
    IntNode n4;
    n4.data=40;
    IntNode n5;
    n5.data=50;

    //test add to head
    list1.AddToHead(n1);
    list1.AddToHead(n2);
    list1.AddToHead(n3);
    list1.AddToHead(n4);
    list1.AddToHead(n5);

    //test cout
    cout << list1 << endl;

    //test copy constructor
    NodeSLList list2(list1);

    NodeSLList list3;
    list3.AddToHead(n3);
    list3.AddToHead(n4);
    list3.AddToHead(n2);
    list3.AddToHead(n1);
    list3.AddToHead(n5);

    //test == operator
    if (list1 == list2){
    	cout << "True" << endl;
    }
    else{
    	cout << "False" << endl;
    }

    if (list2 == list3) {
    	cout << "True" << endl;
    }
    else {
    	cout << "False" << endl;
    }

    if (list2 != list3) {
        cout << "In inequality test" << endl;
        cout << "False" << endl;
    }
    else {
        cout << "In inequality test" << endl;
        cout << "True" << endl;
    }


    IntNode n6;
    n6.data = 3;
    //test insertNode
    cout << "List 2 before insertNode: " << endl;
    cout << list2 << endl;
    list2.InsertNode(3,n6);
    cout << "List 2 after inserting 3 at position 3" << endl;
    cout << list2 << endl;
    list2.InsertNode(9,n6);
    cout << "List 2 after inserting 3 at out of bounds position" << endl;
    cout << list2 << endl;

    //test = operator
    NodeSLList list4;
    list4 = list3;
    cout << "List 4: " << endl;
    cout << list4;

    cout << "List 3 unsorted: " << endl;
    cout << list3;
    list3.SortList(1);
    cout << "List 3 sorted ascending: " << endl;
    cout << list3;
    cout << "List 4 again: " << endl;
    cout << list4;

    cout << "List 2 sorted descending: " << endl;
    list2.SortList(2);
    cout << list2 << endl;

    //test + operator
    cout << "List 4 + List 3: " << endl;
    NodeSLList list5;
    list5 = (list4 + list2);
    cout << list5 << endl;
    //list5 = (list4 + list3);
    //cout << list5;
}
