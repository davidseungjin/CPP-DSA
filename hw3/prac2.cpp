#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Array
{
private:
	string* buf;
	int capacity;
	int size;
public:
	Array(int max_len);
	~Array();
	void insert(string w);
	void find(string w);
	void remove(string w);
	bool isEmpty();
	bool isFull();
	void print(ostream& out);
};


