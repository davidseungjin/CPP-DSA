#include <iostream>
#include <string>
#include <fstream>
#include "Timer.h"

using namespace std;


class UnorderedArrayList
{
	string* buf;
	int capacity;
	int size;

public:
	UnorderedArrayList(int max_len);
	~UnorderedArrayList();
	void insert(string word);
	bool find(string word);
	void remove(string word);
	void print(ostream& out);
	bool isEmpty();
	bool isFull();

};


// David wrote constructor;
UnorderedArrayList::UnorderedArrayList(int max_len)
{
	capacity = max_len;
	buf = new string[capacity];
	size = 0;
}

// David wrote destructor;
UnorderedArrayList::~UnorderedArrayList()
{
	delete[] buf;
}

// David wrote isEmpty();
bool UnorderedArrayList::isEmpty()
{
	if(size == 0)
		return true;
	else
		return false;
}

// David wrote isFull();
bool UnorderedArrayList::isFull()
{
	if(size >= capacity)
		return true;
	else
		return false;
}

// David wrote void insert(string word);
void UnorderedArrayList::insert(string word)
{
//	if(bool isfull = true)
//	{
//		cout << "sorry, size is full. no more insertion" << endl;
//	}	
//	else
	{
		buf[size] = word;
		size++;
	}
}

// David wrote
bool UnorderedArrayList::find(string word)
{
	for(int i=0; i < size; i++)
	{
		if (buf[i] == word)
		{
			return true;
//			cout << "Found";
		} else
		{
			return false;
//			cout << "Not found";
		}
	}
}
			
// David wrote
void UnorderedArrayList::remove(string word)
{
//	if((bool find()) == true)
//	{
		for(int i=0; i < size; i++)
		{
			if (buf[i] == word)
			{ 	
				buf[i]=buf[size-1];
				size = size - 1;
				break; 
				// break: to stop further for-loop 
				// after if-statement achieved.
			}
		}
//	}
}


class UnorderedLinkedList
{
	struct ListNode{
		string info;
		ListNode* next;
		ListNode (string new_info, ListNode *new_next)
			:info(new_info), next(new_next){}
		static void print(ostream& out, ListNode* L)
		{
			if(L)
			{
				out << L->info << endl;
				print(out, L->next);
			}
		}
	};
	ListNode* head;
public:
	UnorderedLinkedList();
	~UnorderedLinkedList();
	void insert(string word);
	bool find(string word);
	void remove(string word);
	void print(ostream& out);
	bool isEmpty();
//	bool isFull(); is it worthy talk about full in linked list?
};


//isEmpty
bool UnorderedLinkedList::isEmpty()
{
	return head==NULL;
}

// constructor
UnorderedLinkedList::UnorderedLinkedList()
:head(NULL){}


// destructor
UnorderedLinkedList::~UnorderedLinkedList()
{
	while(!isEmpty())
	{
		ListNode* old = head;
		head = old->next;
		delete old;
	}
}

//David wrote: insert at the first (study later about inserting at middle and the end.
void UnorderedLinkedList::insert(string word)
{
	ListNode* v = new ListNode(word, head);
//	v->info = word;
//	v->next = head;
	head = v;
}

//David wrote: also, this is remove element from the front of the list. study others later.
//Oh it seems, homework itself looks remove word after searching by looking function signature
//According to GeeksforGeeks, order is 1) find previous node of the node to be deleted, 2) change the vest of previous node. 3) Free memory for the node to be deleted.
// Let's do find function first. I think it can be applied to remove function.

bool UnorderedLinkedList::find(string word)
{
	ListNode* current = new ListNode("", head);
	while (current->next != NULL)
	{
		if (current->info == word)
			return true;
			break;
		current = current->next;
	}
	return false;
	delete current; // is this necessary? 
}





void UnorderedLinkedList::remove(string word)
{
	ListNode* current = new ListNode("", head);
	ListNode* previous = new ListNode("", head);
	current = head;

//	if (current != NULL && current->info == word)
//	{
//		head = current->next;
//		delete current;
//	}
//	Daivd: I think this is redundant. so commented.
//
	while (current !=NULL)
	{
		if (current->info!=word)
		{
			previous = current;
			current = current->next;
		}
		else
		{
			previous->next = current->next;
			delete current;
		}
	}
//	How do I care previous node? I know it is dynamically created as object on the heap
}



void UnorderedArrayList::print(ostream& out){}
//David wrote: when compile, undefined error unless above is declared.

void UnorderedLinkedList::print(ostream& out){}
//David wrote: when compile, undefined error unless above is declared.




ostream& operator << (ostream& out, UnorderedArrayList& L)
{
	L.print(out);
	return out;
}


ostream& operator << (ostream& out, UnorderedLinkedList& L)
{
	L.print(out);
	return out;
}

void insert_all_words(string file_name, UnorderedArrayList& L)
{

//declare timer object
	Timer t;
	double eTime;
//open file
	ifstream f(file_name.c_str());
	string w;	

//start timer
	t.start();
//for each word, w, in file
	if(f.is_open())
	{
		while(getline(f, w))
		{	
		L.insert(w); 
		}	
	}
	else
	{
		cout << "file is not opened. check" << endl;
	}
//stop timer
	t.elapsedUserTime(eTime); 
//close file
	f.close();
//report time
	cout << "insert_all_words run time \t\t" << eTime << endl;

}

void find_all_words(string file_name, UnorderedArrayList& L)
{
//declare timer object
	Timer t;
	double eTime;
//open file
	ifstream f(file_name.c_str());
	string word;
//	assume file is opened and object L is already created and inserted.	
	
//start timer
	t.start();
	while(getline(f, word))
	{
		L.find(word);
	}
//stop timer
	t.elapsedUserTime(eTime); 
//close file
	f.close();

	cout << "find_all_words run time \t\t" << eTime << endl;
}

void remove_all_words(string file_name, UnorderedArrayList& L)
{
//declare timer object
	Timer t;
	double eTime;
//open file
	ifstream f(file_name.c_str());
	string word;
//	assume file is opened and object L is already created and inserted.	

//start timer
	t.start();
	while(getline(f, word))
	{
		L.remove(word);
	}
//stop timer
	t.elapsedUserTime(eTime); 
//close file
	f.close();
	cout << "remove_all_words run time \t\t" << eTime << endl;
}


void insert_all_words(string file_name, UnorderedLinkedList& L)
{

//declare timer object
	Timer t;
	double eTime;
//open file
	ifstream f(file_name.c_str());
	string w;	

//start timer
	t.start();
//for each word, w, in file
	if(f.is_open())
	{
		while(getline(f, w))
		{	
		L.insert(w); 
		}	
	}
	else
	{
		cout << "file is not opened. check" << endl;
	}
//stop timer
	t.elapsedUserTime(eTime); 
//close file
	f.close();
//report time
	cout << "insert_all_words run time \t\t" << eTime << endl;

}

void find_all_words(string file_name, UnorderedLinkedList& L)
{
//declare timer object
	Timer t;
	double eTime;
//open file
	ifstream f(file_name.c_str());
	string word;
//	assume file is opened and object L is already created and inserted.	
	
//start timer
	t.start();
	while(getline(f, word))
	{
		L.find(word);
	}
//stop timer
	t.elapsedUserTime(eTime); 
//close file
	f.close();

	cout << "find_all_words run time \t\t" << eTime << endl;
}

void remove_all_words(string file_name, UnorderedLinkedList& L)
{
//declare timer object
	Timer t;
	double eTime;
//open file
	ifstream f(file_name.c_str());
	string word;
//	assume file is opened and object L is already created and inserted.	

//start timer
	t.start();
	while(getline(f, word))
	{
		L.remove(word);
	}
//stop timer
	t.elapsedUserTime(eTime); 
//close file
	f.close();
	cout << "remove_all_words run time \t\t" << eTime << endl;
}


void test_UnorderedArrayList_methods(string file_name, UnorderedArrayList& L)
{
	cout << "Testing UnorderedArrayList: " << endl;
	insert_all_words(file_name, L);
	find_all_words(file_name, L);
	remove_all_words(file_name, L);
}


void test_UnorderedLinkedList_methods(string file_name, UnorderedLinkedList& L)
{
	cout << "Testing UnorderedLinkedList: " << endl;
	insert_all_words(file_name, L);
	find_all_words(file_name, L);
	remove_all_words(file_name, L);
}


int main(int argc, char * argv[])
{
	const char * input_file = argc == 2 ? argv[1] : "random_b.txt";
	UnorderedArrayList UAL(45500);
	test_UnorderedArrayList_methods(input_file, UAL);
	cout << "\n\n\n";
	UnorderedLinkedList ULL;
	test_UnorderedLinkedList_methods(input_file, ULL);


	return 0;
}



