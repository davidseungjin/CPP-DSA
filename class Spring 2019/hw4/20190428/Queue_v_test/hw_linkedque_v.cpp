#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Queue
{
public:
    Queue(){};
	virtual void enque(string w)=0;
	virtual string deque()=0;
	virtual string front()=0;
	virtual bool isEmpty()=0;
	virtual bool isFull()=0;
	virtual void print()=0;
    ~Queue(){};
};

class LinkedQueue:public Queue
{
	struct ListNode{
		string info;
		ListNode* next;
		ListNode(string new_info, ListNode *new_next)
			:info(new_info), next(new_next){}

	};
	ListNode* head;
	ListNode* tail;
public:
	LinkedQueue()
		:head(nullptr), tail(nullptr){}
	~LinkedQueue(){}
	void enque(string w) 
	{ 
		cout << "get into enque function" << endl;
		ListNode* newNode = new ListNode(w, nullptr);
		if(isEmpty()){
			head = newNode;}
		else{
			tail->next = newNode;}
		tail = newNode;
	}

//	void enque(string w) { head = new ListNode(w, head); }

	string deque();

	string front() { return head->info; }
	bool isEmpty() { return head == nullptr; }
	bool isFull() { return false; }
	void print(); 		// after confirming insert/remove&creating file works well, delete
};

string LinkedQueue::deque(){
//	if(isEmpty())error("pop on empty stack");
	ListNode* p = head;
	string w = head->info;		// comment because of same reason below.
	head = head -> next;
	delete p;
	return w;			// is it necessary to be object? void isn't possible?
}


void LinkedQueue::print(){
	ListNode* cur=head;
	for (cur = head; cur->next != NULL; cur=cur->next)
	{
		cout << cur->next->info << endl;
	}
}


void fillAll(string file_name, Queue& L){
	cout << "1. fillall function called" << endl;
	ifstream f(file_name.c_str());
	cout << "2. second in fillall" << endl;
	string w;
	cout << "3. thrid in fillall" << endl;
//	f.open(file_name);	
	if(f.is_open()){
		while(getline(f, w)){	
			cout << "enqueing? " << endl;
			L.enque(w);
		}
	}
	f.close();
	cout << "fill_all_word done \n" << endl;
//	L.print();
}


void emptyAll(Queue& L, string output_file)
{
	ofstream f(output_file.c_str(), ios::app);		//David: is there any other way that doesn't use ios::app?
//	f.open(output_file);
	int count = 0;				//David: to see which one contribute to segmentation error.
	while((L.isEmpty()) == 0)
	{
		cout << count++ << endl;	// David: counting
		L.print();
		f << L.front() << endl;
		L.deque();
	}
//	f.close();
}


void Queue_test(string file_name, Queue& L, string output_file)
{
	cout << "\n Testing Linked Que==== " << endl;
	fillAll(file_name, L);
	emptyAll(L, output_file);
}

int main(int argc, char* argv[])
{
	const char* input_file = argc == 2? argv[1]: "random_120.txt";
	const char* output_file = "LinkedQueue.txt";
	
	LinkedQueue a;
    
	Queue& q = a;
    
	Queue_test(input_file, q, output_file);

	return 0;
}
