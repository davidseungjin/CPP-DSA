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
// It is noteworthy that we cannot as easily delete the last node of a singly linked list, even if we had a pointer to it. In order to delete a node, we need to update the next link of the node immediately preceding the deleted node.


/*
Chapter 3.2.4 Implementing a Generic Singly Linked List.

The implementation of the singly slinked list in 3.2.1 assumes that the element type is a character string. It is easy to convert the implementation so that it works for an arbitary element type through the use of C++'s template mechanism. 

In contrast to our earlier version in Code Fragment, references to the data type "string have been replaced by "E". When referring to our templated node and list class, we need to include the suffix "<E>". For example, the class is SLinkedList<E> and the associated node is SNode<E>
*/

template <typename E>
class SNode{
private:
	E elem;
	SNode<E>* next;
	friend class SLinkedList<E>;
};

/* The generic list class is presented below. references to the specific element type "string" have been replaced by reference to the generic type parameter "E". */

template<typename E>
clas SlinkedList {
public:
	SlinkedList();
	~SlinkedList();
	bool empty() const;
	const E& front() cost;
	void addFront(const E& e);
	void removeFront();
private:
	Snode<E>* head;
};

/* Observe that each definition is prefaced by the template specifier template <typename E> */

template <typename E>
SlinkedList<E>::SlinkedList()
:head(NULL){}

template<typename E>
bool SlinkedList<E>::empty() const
{return head == NULL;}

template<typename E>
const E& SLinkedList<E>::front() const
{return head->elem;}

template<typename E>
SlinkedList<E>::~SlinkedList()
{while (!empty()) removeFront();}

template<typename E>
void SlinkedList<E>::addFront(const E& e){
	SNode<E>* v = new SNode<E>;
	v->elem = e;
	v->next = head;
	head = v;
}

template<typename E>
void SLinkedList<E>::removeFront(){
	SNode<E>* old=head;
	head=old->next;
	delete old;
}

/* We can generate singly linked lists of various types by simply setting the template parameter as desired as shown in the following code fragment.

SLinkedList<string> a;
a.addFront("MSP");
// .... 
SlinkedList<int>b;
b.addFront(1);

Because templated classes carry a relatively high notational burden, we oftern sacrifice generality for simplicity, and avoid the use of templated classes in some of our examples.
*/










