#include<iostream>

using namespace std;

/* Arrays are nice and simple for storing things in a certain order, but they have drawbacks. They are not very adaptable. For instance, we ahve to fix the size n of an array in advance, which makes resizing an array difficult. (This is drawback is remedied in STL vectors.) Insertions and deletions are difficult because elements need to be shifted around to make space for insertion or to fill empty positions after deletion. 

A linked list is a collection of nodes that together form a linear ordering. The next pointer inside a node is a link or pointer to the next node of the list. THe first and last nodes of a linked list are called the head and tail of th list, respectively. 

Like an array, a singly linked list maintains its elements in a certain order, as determined by the chain of next links. Unlike an array, a singly linked list does not have a predetermined fixed sie. It can be resized by addiong or removing nodes.


The node stores two values, the member elem stores the element stored in this node. The member next stores a pointer to the next node of the list.
*/

class StringNode{
private:
	string elem;
	StringNode* next;

	frind class StringLinkedList;
};

/* Its private data consists of a pointer to the head node of the list */

class StringLinkedList {
public:
	StringLinkedList();
	~StringLinkedList();
	bool empty() const;
	const string& front() const;
	void addFront(const string& e);
	void removeFront();
private:
	StringNode* head;
};

/* To test whether the list is empty, we simply test whether the head pointer is NULL */

StringLinkedList::StringLinkedList()
: head(NULL){}

StringLinkedList::~StringLinkedList()
{while(!empty()) removeFront();}

bool StringLinkedList::empty() const
{return head==NULL;}

const string& StringLinkedList::front() const
{return head-> NULL;}
// what is the meaning of const, const?

/* below is the insertion to the Front of a Singly Linked List */

void StringLinkedList::addFront(const string& e){
	StringNode* v = new StringNode; // create new node
	v->elem=e;			// store data
	v->next=head;			//head now follows v
	head=v;
}

/* Below is the removal from the Front of a Singly Linked List */
void StringLinkedList::removeFront(){
	StringNode* old=head;
	head = old->next;
	delete old;
}

