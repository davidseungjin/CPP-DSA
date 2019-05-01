#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Stack
{
public:
	Stack(){};
	virtual void push(string w)=0;
	virtual string pop()=0;
	virtual string top()=0;
	virtual bool isEmpty()=0;
	virtual bool isFull()=0;
	virtual void print()=0;
	~Stack(){};
};


class StackArray:public Stack
{
	string* buf;
	int tp;
	int capacity;
public:
	StackArray(int maxsize)
		:capacity(maxsize=100), tp(0), buf(new string[maxsize]){
	cout << "Constructor is created\n";}
	~StackArray(){ cout << "Destructor is called\n";}
	void push(string w) { cout<< "push function working?" << endl; buf[tp++] = w; }
	string pop() { return buf[--tp]; }
	string top() { return buf[tp-1]; cout << buf[tp-1] << endl; }
	bool isEmpty() { return tp <= 0; }
	bool isFull() { return tp >= capacity;}
	void print(); 				// after confirming insert/remove&creating file works well, delete
};

void StackArray::print(){
	int i=0;
	cout << "print function is working" << endl;
	for (;i < tp ; i++)
		cout << "buf[" << i << "] is " << buf[i] << endl;
}

void fillAll(string file_name, Stack& L){
	ifstream f(file_name.c_str());
	string w;	
	if(f.is_open()){
		while(getline(f, w)){	
			L.push(w);
		}
	}
	f.close();
	cout << "insert_all_word done \n" << endl;
	L.print();
}

void emptyAll(Stack& L, string output_file)
{
	ofstream f(output_file.c_str(), ios::out);		//David: is there any other way that doesn't use ios::app?
//	f.open(output_file);

	while(L.isEmpty() == 0)
	{
		f << L.top() << endl;
		L.pop();
		L.print();
	}
	f.close();
}


void Stack_test(string file_name, Stack& L, string output_file)
{
	cout << "\n Testing StackArray==== " << endl;
	fillAll(file_name, L);
	emptyAll(L, output_file);
}

int main(int argc, char* argv[])
{
	const char* input_file = argc == 2? argv[1]: "random_1000.txt";
	const char* output_file = "StackArrayOutput.txt";
	
	StackArray a(2000);

	Stack& s = a;
	
	Stack_test(input_file, s, output_file);

	return 0;
}

