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


UnorderedArrayList::UnorderedArrayList(int max_len)
{
	capacity = max_len;
	buf = new string[capacity];
	size = 0;
}

UnorderedArrayList::~UnorderedArrayList()
{
	delete[] buf;
}

bool UnorderedArrayList::isEmpty()
{
	if(size == 0)
		return true;
	else
		return false;
}

bool UnorderedArrayList::isFull()
{
	if(size >= capacity)
		return true;
	else
		return false;
}

void UnorderedArrayList::insert(string word)
{
	buf[size] = word;
	size++;
}

bool UnorderedArrayList::find(string word)
{
	for(int i=0; i < size; i++)
	{
		if (buf[i] == word)
		{
			return true;
		} 
		else
		{
			return false;
		}
	}
}
			
void UnorderedArrayList::remove(string word)
{
	for(int i=0; i < size; i++)
	{
		if (buf[i] == word)
		{ 	
			buf[i]=buf[size-1];
			size = size - 1;
			break; 
		}
	}
}


class UnorderedLinkedList
{
	struct ListNode
	{
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
};


UnorderedLinkedList::UnorderedLinkedList()
:head(NULL){}

UnorderedLinkedList::~UnorderedLinkedList()
{
	while(head==NULL)
	{
		ListNode* old = head;
		head = old->next;
		delete old;
	}
}

void UnorderedLinkedList::insert(string word)
{
	ListNode* v = new ListNode(word, head);
	head = v;
}

bool UnorderedLinkedList::find(string word)
{
	ListNode* current = head;
	while (current != NULL)
	{
		if (current->info == word)
			return true;
		current = current->next;
	}
	return false;
}

void UnorderedLinkedList::remove(string word)
{
	if(head->info == word) 
	{
		ListNode* oldhead = head;
		head = head->next;
		delete oldhead;
		return;
	}
	
	// when head delete case, when delete other than head
	ListNode* prev = head;
	for(head; prev->next != NULL; prev=prev->next)
	{
		if(prev->next->info==word)
		{
			ListNode* temp = prev->next;
			prev->next = prev->next->next;
			delete temp;
			break;

		}
	}
}


void UnorderedArrayList::print(ostream& out){}

void UnorderedLinkedList::print(ostream& out){}

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

	Timer t;
	double eTime;
	ifstream f(file_name.c_str());
	string w;	

	t.start();
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
	t.elapsedUserTime(eTime); 
	f.close();
	cout << "insert_all_words run time \t\t" << eTime << endl;

}

void find_all_words(string file_name, UnorderedArrayList& L)
{
	Timer t;
	double eTime;
	ifstream f(file_name.c_str());
	string word;
	
	t.start();
	while(getline(f, word))
	{
		L.find(word); // this needs to be modified
	}
	t.elapsedUserTime(eTime); 
	f.close();

	cout << "find_all_words run time \t\t" << eTime << endl;
}

void remove_all_words(string file_name, UnorderedArrayList& L)
{
	Timer t;
	double eTime;
	ifstream f(file_name.c_str());
	string word;

	t.start();
	while(getline(f, word))
	{
		L.remove(word);
	}
	t.elapsedUserTime(eTime); 
	f.close();
	cout << "remove_all_words run time \t\t" << eTime << endl;
}


void insert_all_words(string file_name, UnorderedLinkedList& L)
{

	Timer t;
	double eTime;
	ifstream f(file_name.c_str());
	string w;	

	t.start();
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
	t.elapsedUserTime(eTime); 
	f.close();
	cout << "insert_all_words run time \t\t" << eTime << endl;

}

void find_all_words(string file_name, UnorderedLinkedList& L)
{
	Timer t;
	double eTime;
	ifstream f(file_name.c_str());
	string word;
	
	t.start();
	while(getline(f, word))
	{
		L.find(word);
	}
	t.elapsedUserTime(eTime); 
	f.close();

	cout << "find_all_words run time \t\t" << eTime << endl;
}

void remove_all_words(string file_name, UnorderedLinkedList& L)
{
	Timer t;
	double eTime;
	ifstream f(file_name.c_str());
	string word;

	t.start();
	while(getline(f, word))
	{
		L.remove(word);
	}
	t.elapsedUserTime(eTime); 
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
	const char * input_file = argc == 2 ? argv[1] : "random_c.txt";
	UnorderedArrayList UAL(45500);
	test_UnorderedArrayList_methods(input_file, UAL);
	cout << "\n\n\n";
	UnorderedLinkedList ULL;
	test_UnorderedLinkedList_methods(input_file, ULL);


	return 0;
}



