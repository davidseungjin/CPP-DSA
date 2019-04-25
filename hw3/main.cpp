#include <iostream>
#include <string>
#include <fstream>
#include "Timer.h"

using namespace std;


class SortedList
{
public:
	SortedList()
	{cout<<"Base class constructor called \n";}
//	virtual void insert(string word){};
//	virtual bool find(string word){};
//	virtual void remove(string word){};
//	virtual bool isEmpty(){};
//	virtual bool isFull(){};
//	virtual void print(ostream& out){};
	virtual ~SortedList()
	{cout<<"Base class destructor called \n";}

};



class SortedArrayList:public SortedList
{
public:
	string* buf;
	int capacity;
	int size;
public:
	SortedArrayList(int max_len);
	~SortedArrayList();
	void insert(string word);
	bool find(string word);
	void remove(string word);
	bool isEmpty();
	bool isFull();
	void print(ostream& out);
};


SortedArrayList::SortedArrayList(int max_len)
{
//	SortedList();
	cout << "SortedArrayList class constructor called \n";
	capacity = max_len;
	buf = new string[size];
	size = 0;
}

SortedArrayList::~SortedArrayList()
{
	delete[] buf;
	cout << "SortedArrayList class destructor called \n";
//	SortedList::~SortedList();
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
	if(isfull()==true)return;
	cout << "word before assigning to buf is: " << word << endl;
	int i=0;
	for (; i<size;i++)
	{
		if(word > buf[i])
		{
			for(int j=size-1; j>=i; --j)
			{
				buf[j+1]=buf[j];
			}
			break;
		}
	}			
	buf[i]=word;
	size++;
}


bool SortedArrayList::find(string word)
{
	int mid = 0;
	int min = 0;
	int max = size;
	while (min <= max)
	{
		mid = min + (max-min)/2;
		if (word < buf[mid])
		{
			max = mid - 1;
		}
		else if (word > buf[mid])
		{
			min = mid + 1;
		}
		else if (word == buf[mid])
		{
			cout << "found\n" << endl;; // David added to check
			cout << "index is " << mid << endl;
			return true;
		}
		else
		{
			cout << "not found\n";
			return false;
		}
	}
	cout << "size is in find " <<size<< endl;
}




void SortedArrayList::remove(string word)
{
	cout << "before for loop" << endl;
	cout << "size is " << size << endl;

	for(int i = 0; i < size ; i++)
	{
		if(buf[i] == word)
		{
			buf[i] = buf[size-1];
			size = size - 1;
			cout << "for loop in remove test" << endl;
		}
//	David added to show
	cout << "size is: " << size << endl;
	cout << "buf is" << buf << endl;
	cout << "*buf is " << *buf << endl;
	}
}




void SortedArrayList::print(ostream& out)
{
	for(int i = 0; i < size ; i++)
	{
		out << buf[i] << "\n";
	}
}

ostream& operator << (ostream& out, SortedArrayList& L)
{
	L.print(out);
	return out;
}


void insert_all_words(string file_name, SortedArrayList& L)
{
	Timer t;
	double eTime;
	ifstream f(file_name.c_str()); // it error if it is omit .c_str().
	string word;

	t.start();
	int count =0;
	if(f.is_open())
	{
		cout << "file is once opened";
		while(getline(f, word))
		{
// here here
			cout << "\nhere before count and L.insert" << endl; 
//David : estimate it really get lines
			count++; 
//David: count lines
			cout << "count is " << count << endl; 
// David: print count
			L.insert(word); // core function.
// here here
		}
		

	cout << "\n after loop: here here \n " << endl;
	cout << count << endl; // David: print how many lines
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
	cout << "remove_all_words function executed" << endl;
	while(getline(f,word))
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
//	cout << "before L \n" << L << " should be L.buf[something]\n";

//	for (int i=0; i<L.size; i++)
//		cout << L.buf[i] << "\n";
	find_all_words(file_name, L);
	remove_all_words(file_name, L);	
}


int main(int argc, char* argv[])
{
	const char* input_file = argc == 2? argv[1] : "random_5.txt";

	SortedArrayList a(45500);	
	test_SortedArrayList_methods(input_file, a);	
//	SortedLinkedList b;
//	test_SortedLinkedList(input_file, b);
	return 0;
}

