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

void fillAll(string file_name, StackArray& L){
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

void emptyAll(StackArray& L, string output_file)
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
	fillAll(file_name, L);
	emptyAll(L, output_file);
}

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class LinkedStack
{
	struct ListNode{
		string info;
		ListNode* next;
		ListNode(string new_info, ListNode *new_next)
			:info(new_info), next(new_next){}

	};
	ListNode* head;
public:
	LinkedStack()
		:head(nullptr){}
	~LinkedStack(){}
//	void push(string w) { if(isFull()) error ("Push on full stack"); head = new ListNode(w, head); }
	void push(string w) { head = new ListNode(w, head); }
	string pop();
//	string top() { if(isEmpty()) error("top on empty stack"); return head->info; }
	string top() { return head->info; }
	bool isEmpty() { return head == nullptr; }
	bool isFull() { return false; }
	void print(); 				// after confirming insert/remove&creating file works well, delete
};

string LinkedStack::pop(){
//	if(isEmpty())error("pop on empty stack");
	ListNode* p = head;
	string w = head->info;
	head = head -> next;
	delete p;
	return w;
}

void LinkedStack::print(){
	ListNode* cur=head;
	for (cur = head; cur->next != NULL; cur=cur->next)
	{
		cout << cur->info << "\n";
	}
}


void fillAll(string file_name, LinkedStack& L){
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

void emptyAll(LinkedStack& L, string output_file)
{
	ofstream f(output_file, ios::app);		//David: is there any other way that doesn't use ios::app?
//	f.open(output_file);
	int count = 0;				//David: to see which one contribute to segmentation error.
	while((L.isEmpty()) == 0)
	{
		cout << count++ << endl;	// David: counting
		L.print();
		f << L.top() << endl;
		L.pop();
	}
//	f.close();
}

void test_LinkedStack(string file_name, LinkedStack& L, string output_file)
{
	cout << "\n Testing StackArray==== " << endl;
	fillAll(file_name, L);
	emptyAll(L, output_file);
}


int main(int argc, char* argv[])
{
	const char* input_file = argc == 2? argv[1]: "random_1000.txt";
	const char* output_file = "LinkedStackOutput.txt";
	
	LinkedStack a;
	test_LinkedStack(input_file, a, output_file);

	return 0;
}


int main(int argc, char* argv[])
{
	const char* input_file = argc == 2? argv[1]: "random_1000.txt";
	const char* output_file = "StackArrayOutput.txt";

	StackArray a(2000);
	test_StackArray(input_file, a, output_file);

	return 0;
}
