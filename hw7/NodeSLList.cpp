///////////////////////////////////////////////////////////////////////
// Sam Hagan
// CIS 554 Homework 7
// NodeSLList.cpp
// Class NodeSLList Implementation
//
// Description - This file implements a singly linked list.
///////////////////////////////////////////////////////////////////////
#include "NodeSLList.h"
#include <iostream>
using namespace std;


///////////////////////////////////////////////////////////////////////
// default constructor
///////////////////////////////////////////////////////////////////////
NodeSLList::NodeSLList()
{ 
	head = tail = 0;
}

///////////////////////////////////////////////////////////////////////
// copy constructor
///////////////////////////////////////////////////////////////////////
NodeSLList::NodeSLList(NodeSLList & list)
{ 
	IntNode * hold = list.head;

	for (int i = 0; i < list.GetSize(); i++){
		AddToTail(*hold);
		hold = hold->next;
	}
}

///////////////////////////////////////////////////////////////////////
// destructor
///////////////////////////////////////////////////////////////////////
NodeSLList::~NodeSLList()
{
	// call destroyList() to remove all nodes
	// and reset linked list
	DestroyList();
}

///////////////////////////////////////////////////////////////////////
// IsEmpty
///////////////////////////////////////////////////////////////////////
bool NodeSLList::IsEmpty()
{ 
	// if head is NULL, then the list is empty, and we will return true
	// otherwise, we will return false
	return (head == 0); 
}

///////////////////////////////////////////////////////////////////////
// GetSize
///////////////////////////////////////////////////////////////////////
int NodeSLList::GetSize()
{
	// check to see if the list is empty. if 
	// so, just return 0
	if ( IsEmpty() ) return 0;

	int size = 1;
	IntNode *p = head;
	// compute the number of nodes and return
	while (p != tail)
	{
		// until we reach the tail, keep counting
		size++;
		p = p->next;
	}
	return size;
}

///////////////////////////////////////////////////////////////////////
// AddToHead
///////////////////////////////////////////////////////////////////////
void NodeSLList::AddToHead(const IntNode & node)
{
	// create a new node, and make it the head. the 
	// previous head will become head->next
	IntNode * next = head;
	head = new IntNode;
	head->next = next;
	head->data = node.data;

	// if this is the first node, make the tail the 
	// same as the head
	if (tail == 0)
		tail = head;
}

///////////////////////////////////////////////////////////////////////
// DeleteFromHead
///////////////////////////////////////////////////////////////////////
IntNode NodeSLList::DeleteFromHead()
{
	IntNode temp;
	temp.data=0;
	temp.next=NULL;
	if (IsEmpty())
	{
		cout << "*****ERROR: Can't delete from head. List is Empty" << endl;
		return temp;
	}

	// get current value of node we are about to delete, 
	// so we can return it.
	temp.data = head->data;

	IntNode *tmp = head;

	// if there is only one node, set the head and pointer tails
	// to NULL (0)
	if (head == tail)
		head = tail = 0;

	// otherwise, move the head pointer to the next node 
	// in the list
	else
		head = head->next;

	// delete head node
	delete tmp;

	// return value of node that was deleted
	return temp;
}

///////////////////////////////////////////////////////////////////////
// AddToTail
///////////////////////////////////////////////////////////////////////
void NodeSLList::AddToTail(const IntNode & node)
{
	
	if (head == 0){ 
		tail = new IntNode;
		tail->data = node.data;
		tail->next = 0;
		head = tail;
	}
	else{
		IntNode * hold = tail;
		tail = new IntNode;
		tail->data = node.data;
		tail->next = 0;
		hold->next = tail;
	}
}

///////////////////////////////////////////////////////////////////////
// DeleteFromTail
///////////////////////////////////////////////////////////////////////
IntNode NodeSLList::DeleteFromTail()
{
	IntNode nodeData;

	// get the current data at the tail
	nodeData.data = tail->data;


	// if there is only one node, delete the only node, and set the 
	// head and tail pointers to NULL (0) 
	if (head == tail)
	{
		delete head;
		head = tail =0;
	}

	// otherwise, traverse to the tail node and delete it
	else
	{
		IntNode * temp;
		// traverse to tail pointer
		for (temp = head; temp->next != tail; temp = temp->next);
		delete tail;
		tail = temp;
		tail->next = 0;
	}

	return nodeData;
}



///////////////////////////////////////////////////////////////////////
// DeleteNode
///////////////////////////////////////////////////////////////////////
IntNode NodeSLList::DeleteNode(int nodeNum)
{
	if (nodeNum <= 0) nodeNum = 1;
	IntNode *prev=head , *temp=head;
	IntNode current;

	// traverse to the node
	for (int loop=1; loop<nodeNum; loop++)
	{
		prev=temp, temp=temp->next;
		// check for case where nodeNum is > the number of 
		// nodes in the list. if we reach the tail before
		// we traverse to the node, delete the tail 
		if ( temp == tail )
			return DeleteFromTail();
	}

	// if deleting the head just call 
	// the appropriate member function 
	// and don't repeat that logic here
	if (temp == head) return DeleteFromHead();

	// otherwise, delete the node we traversed to
	prev->next = temp->next;
	current.data = temp->data;

	delete temp;

	return current;
}


///////////////////////////////////////////////////////////////////////
// InsertNode
///////////////////////////////////////////////////////////////////////
void NodeSLList::InsertNode(int nodeNum, const IntNode &node)
{
	if (nodeNum <= 1){
		AddToHead(node);
		return;
	}
	IntNode *tmp = head;

	IntNode *newNode = new IntNode;
	newNode->data = node.data;
	for (int i=1; i< (nodeNum-1) && tmp != tail; i++){
		tmp = tmp->next;
	}
	if (tmp == tail){
		AddToTail(node);
		return;
	}
	IntNode *hold = tmp->next;
	tmp->next = newNode;
	newNode->next = hold;
}


///////////////////////////////////////////////////////////////////////
// UpdateNode
///////////////////////////////////////////////////////////////////////
void NodeSLList::UpdateNode(int nodeNum, const IntNode &node)
{
	IntNode *tmp = head;

	// traverse to the node, or to the last node, whichever comes
	// first. if the last node is reached, then that is the node
	// that is updated
	for (int i=1; i< nodeNum && tmp != tail; i++)
		tmp = tmp->next;

	tmp->data = node.data;
}

///////////////////////////////////////////////////////////////////////
// SortList
///////////////////////////////////////////////////////////////////////
void NodeSLList::SortList(unsigned int order)
{
	if (order==1){
		SortListAscending();
	}
	else if (order==2){
		SortListDescending();
	}
	else{
		cout << "Error: Unrecognized sorting order." << endl;
		return;
	}
}
//Selection Sort Ascending
void NodeSLList::SortListAscending(){
	int smallest;
	for (int i = 1; i < GetSize(); i++){
		smallest = i;
		for (int j = i+1; j <= GetSize(); j++){
			if (RetrieveNode(j).data < RetrieveNode(smallest).data){
				smallest = j;
			}
		}
		Swap(i,smallest);
		
	}
}
//Selection Sort Descending
void NodeSLList::SortListDescending(){
	int largest;
	for (int i = 1; i < GetSize(); i++){
		largest = i;
		for (int j = i+1; j <= GetSize(); j++){
			if (RetrieveNode(j).data > RetrieveNode(largest).data){
				largest = j;
			}
		}
		Swap(i,largest);
	}
}

//swap the nodes at two indices of the linked list
void NodeSLList::Swap(int val1, int val2){
	//Delete the node at the larger index first
	if (val1 < val2){
		IntNode node2 = DeleteNode(val2);
		IntNode node1 = DeleteNode(val1);
		//Insert the node at the smaller index back in first
		InsertNode(val1,node2);
		InsertNode(val2,node1);
	}
	else if(val2 < val1){
		IntNode node1 = DeleteNode(val1);
		IntNode node2 = DeleteNode(val2);
		InsertNode(val2,node1);
		InsertNode(val1,node2);
	}
}

///////////////////////////////////////////////////////////////////////
// DestroyList
///////////////////////////////////////////////////////////////////////
void NodeSLList::DestroyList()
{
	// while the list is NOT empy
	// keep removing the head node and make
	// the next node the head node
	for (IntNode *p; !IsEmpty(); )
	{
		p = head->next;
		delete head;
		head = p;
	}
	head = tail = 0;
}

///////////////////////////////////////////////////////////////////////
// operator=
///////////////////////////////////////////////////////////////////////
NodeSLList & NodeSLList::operator=(NodeSLList & list)
{
	//if this already has the contents of list, just return it
	if (*this != list){
		DestroyList(); //Destroy the current contents on this
		IntNode *hold = list.head;
		for (int i = 0; i < list.GetSize(); i++){ //fill this with list
			AddToTail(*hold);
			hold = hold->next;
		}
	}

	return *this;
}

///////////////////////////////////////////////////////////////////////
// operator==
///////////////////////////////////////////////////////////////////////
bool NodeSLList::operator==(NodeSLList & list)
{
	//if the two lists are different sizes, they aren't equal
	if (list.GetSize() != GetSize()){
		return false;
	}
	IntNode *tmp1 = list.head;
	IntNode * tmp2 = head;
	for (int i = 0; i < list.GetSize(); i++){
		//if any node's data is not equal to the same node's data
		//in the other list, then they aren't equal
		if (tmp1->data != tmp2->data){
			return false;
		}
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	return true;
}

///////////////////////////////////////////////////////////////////////
// operator!=
///////////////////////////////////////////////////////////////////////
bool NodeSLList::operator!=(NodeSLList & list)
{
	return !(*this==list);
}

///////////////////////////////////////////////////////////////////////
// operator+
///////////////////////////////////////////////////////////////////////
NodeSLList & NodeSLList::operator+(NodeSLList & list)
{
	NodeSLList &result(*this); //copy this into result
	NodeSLList *temp = new NodeSLList(list); //create a new list with list

	//append temp to result
	result.tail->next = temp->head;
	result.tail = temp->tail;

	//delete the temporary list
	temp->head = temp->tail = 0;
	delete temp;

	return result;
}

///////////////////////////////////////////////////////////////////////
// RetrieveNode
// 
// Description: retrieve data from a node without removing it from 
//              the list
// Input: node number (1-N; not 0-N-1)
// Output: none
// Returns: reference to node data
///////////////////////////////////////////////////////////////////////
IntNode & NodeSLList::RetrieveNode(int nodeNum) const
{
	IntNode *tmp = head;

	// traverse to the node, or to the last node, whichever comes
	// first
	for (int i=1; i< nodeNum && tmp != tail; i++)
		tmp = tmp->next;

	return *tmp;
}

ostream & operator<<(ostream & output, NodeSLList & list)
{
	IntNode *hold = list.head;
	for (int i = 0; i < list.GetSize(); i++){
		output << hold->data << " ";
		hold = hold->next;
	}
	output << endl;
	return output;
}

