#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class StackArray
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

void insert_all_words(string file_name, StackArray& L){
	ifstream f(file_name.c_str());
	string w;
	
	if(f.is_open()){
		while(getline(f, w)){	
			L.push(w);
		}
	}
	f.close();
	cout << "insert_all_word done \n" << endl;
//	L.print();
}

void remove_all_words(StackArray& L, string output_file)
{
	ofstream f(output_file, ios::app);		//David: is there any other way that doesn't use ios::app?
//	f << "2.     test before open" << endl;
//	f.open(output_file);
//	f << "3.       test right after open" << endl;

	while(L.isEmpty() == 0)
	{
		f << L.top() << endl;
		L.pop();
		L.print();
	}
	f.close();
}

void test_StackArray(string file_name, StackArray& L, string output_file)
{
	cout << "\n Testing StackArray==== " << endl;
	insert_all_words(file_name, L);
	remove_all_words(L, output_file);
}

int main(int argc, char* argv[])
{
	const char* input_file = argc == 2? argv[1]: "random_120.txt";
	const char* output_file = "StackArrayOutput.txt";

	StackArray a(1000);
	test_StackArray(input_file, a, output_file);

	return 0;
}

