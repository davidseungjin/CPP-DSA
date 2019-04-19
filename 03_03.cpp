

/*

A C++ Implementation

First, we present a C++ class for a node of the list.

To keep the code simple, we have chosen not to derive a templated class as we did in section 3.2.1 for singly linked list. Instead, we provide a typedef statement that defines the element type called Elem. 

We define it to be a string, but any other type could be used instead.

We declare DLinkedList to be a friend, so it can access the node's private members.

*/

#include <iostream>

using namespace std;

typedef string Elem;
class DNode {
private:
	Elem elem;		//node element value
	DNode* prev;		//previous node in list
	DNode* next;		//next node in list
	friend class DlinkedList;
};


/*
Next, we present the definition of the doubly linked list class, DLinkedList.
There are two private data members, header and trailor, which point to the sentinels. Finally we provide two protected utility memeber functions, add and remove. They are used internally by the class and by its subclasses, but they cannot be invoked from outside the class */

class DLinkedList{
public:
	DLinkedList();
	~DLinkedList();
	bool empty() const;
	const Elem& front() const;		//get front element
	const Elem
