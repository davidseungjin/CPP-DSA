#include <iostream>
#include <string>
#include <fstream>
#include "Timer.h"

using namespace std;

class SortedList
{
protected:
	virtual void insert(string word);
	virtual bool find(string word);
	virtual void remove(string word);
	virtual bool isEmpty();
	virtual bool isFull();
	void print(ostream& out);
public:
	SortedList();
	virtual ~SortedList();
};

class SortedArrayList : public SortedList
{
	string* buf;
	int capacity;
	int size;

public:
	SortedArrayList(int max_len);
	virtual ~SortedArrayList();
};


SortedArrayList::SortedArrayList(int max_len)
	:SortedList(), capacity(max_len), buf(new string[capacity]), size(0){}

SortedArrayList::~SortedArrayList()
{
	delete[] buf;
}

bool SortedArrayList::isEmpty()
{
	if(size == 0)
		return true;
	else
		return false;
}

bool SortedArrayList::isFull()
{
	if(size >= capacity)
		return true;
	else
		return false;
}

void SortedArrayList::insert(string word)
{

	buf[size] = word;
	size++;
	int mid;
	int min=0;
	int max=size;
	while(min <= max) {
		mid = min+(max-min)/2;
		if(word < buf[mid]){
			max = mid -1;}
		else if (word>buf[mid]){
			mid = mid+1;}
		else if (word == buf[mid]){
			size++
			for(int i=mid; i < size; i++){
				buf[i+1]=buf[i];
			}
			buf[mid] = word;


}

bool SortedArrayList::find(string word){
	int mid;
	int min = 0;
	int max = size;
	while(min <= max){
		mid = min + (max-min)/2;
		if (word < buf[mid]){
			max = mid - 1;}
		else if (word > buf[mid]){
			min = mid + 1;}
		else if (word == buf[mid]){
			return true;}
		else
			return false;
	}
}
			
void SortedArrayList::remove(string word)
{
	for(int i=0; i < size; i++)
	{
		if (buf[i] == word)
		{ 	
			buf[i]=buf[size-1];
			size = size - 1;
		}
	}
}

void SortedArrayList::print(ostream& out){
	for(int i=0; i < size; i++)
	{
		out << buf[i] << "\n";
	}
}

ostream& operator << (ostream& out, SortedArrayList& L)
{
	L.print(out);
	return out;
}


		
/*
class SortedLinkedList : public SortedList
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
	SortedLinkedList();
	virtual ~SortedLinkedList();
//	David: needs to delete below because all is located in base class.
//	void insert(string word);
//	bool find(string word);
//	void remove(string word);
//	void print(ostream& out);
};


SortedLinkedList::SortedLinkedList()
:SortedList(), head(NULL){}

SortedLinkedList:: virtual ~SortedLinkedList() // is that syntactically right? (space between double colon and "virtual"
{
	while(head!=NULL) 
	{
		ListNode* old = head;
		head = old->next;
		delete old;
	}
}

void SortedLinkedList::insert(string word)
{
	ListNode* v = new ListNode(word, head);
	head = v;
}

bool SortedLinkedList::find(string word) // sequence search
{
	ListNode* current = head;
	while (current != NULL)
	{
		if (current->info == word)
		{	
			return true;
		}
		current = current->next;
	}
	return false;
}

void SortedLinkedList::remove(string word)
{
	if(head->info==word)
	{
		ListNode* oldhead = head;
		head = head->next;
		delete oldhead;
		return;
	}
	
	ListNode* prev=head;
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

void SortedLinkedList::print(ostream& out){
	ListNode* cur=head;
	for(head; cur->next != NULL; cur=cur->next)
	{
		out << cur->info << "\n";
	}
}

ostream& operator << (ostream& out, SortedLinkedList& L)
{
	L.print(out);
	return out;
}

*/



void insert_all_words(string file_name, SortedArrayList& L)
{

	Timer t;
	double eTime;
	ifstream f(file_name.c_str());
	string word;	

	t.start();
	if(f.is_open())
	{
		while(getline(f, word))
		{	
		L.insert(word); 
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

void find_all_words(string file_name, SortedArrayList& L)
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

void remove_all_words(string file_name, SortedArrayList& L)
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


void insert_all_words(string file_name, SortedLinkedList& L)
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
/*	
	ostream& operator << (ostream& out, SortedArrayList& L)
	{
		L.print(out);
	}
*/	
	
}

void find_all_words(string file_name, SortedLinkedList& L)
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

void remove_all_words(string file_name, SortedLinkedList& L)
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


void test_SortedArrayList_methods(string file_name, SortedArrayList& L)
{
	cout << "Testing SortedArrayList: " << endl;
	insert_all_words(file_name, L);
	find_all_words(file_name, L);
	remove_all_words(file_name, L);
}


void test_SortedLinkedList_methods(string file_name, SortedLinkedList& L)
{
	cout << "Testing SortedLinkedList: " << endl;
	insert_all_words(file_name, L);
	find_all_words(file_name, L);
	remove_all_words(file_name, L);
}


int main(int argc, char * argv[])
{
	const char * input_file = argc == 2 ? argv[1] : "random_120.txt";
	SortedArrayList UAL(45500);
	test_SortedArrayList_methods(input_file, UAL);
	cout << "\n\n\n";
	SortedLinkedList ULL;
	test_SortedLinkedList_methods(input_file, ULL);


	return 0;
}
