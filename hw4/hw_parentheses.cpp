/*

pending on Lords day. (13:00~14:50)
basic scheme is 

concept is stack. when input value coming is open braket ( {, [, <, ( ), then push on the stack.
when closing braket ( }, ], >, ) ), then pop from the stack.

To-do is, 

Input string, then convert to char[] to compare character one-by-one.


under for loop (i=0; i< strlen(input char value); i++)

1. when input value is opening braket, push() to the stack.
2. when input value is closing braket, compare top() and input value
	If Match? pop(), else --> "dont match" and program termination --> return false

3. befor completing last element of input, when isempty()
	then ---> "not match. closing braket is more", and program termination. return false
4. after completing last element of input, when remained. (meaning 'head != nullptr')
	then ---> "not match. opening braket is more", and program termination. return false

================
if there's nothing related to false happen so that it exit for-loop successfully,
	it means brakets matches, number of opening/closing brakets are matched.
	it means, success. balanced.
	so, return true.

*/






#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class LinkedStack
{
	struct ListNode{
		char info;
		ListNode* next;
		ListNode(char new_char, ListNode *new_next)
			:info(new_char), next(new_next){}

	};
	ListNode* head;
public:
	LinkedStack()
		:head(nullptr){}
	~LinkedStack(){}
//	void push(char c) { if(isFull()) error ("Push on full stack"); head = new ListNode(w, head); }
	void push(char c) { head = new ListNode(c, head); }
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
	char c = head->info;
	head = head -> next;
	delete p;
	return c;
}

void LinkedStack::print(){
	ListNode* cur=head;
	for (cur = head; cur->next != NULL; cur=cur->next)
	{
		cout << cur->info << "\n";
	}
}


// You need to implement void function so-called "decidepp(push and pop) depending on type of braces"
// here 

bool decidepp(d, LinkedStack& L){

// push case
// look character array.
// if value at i is ( < { [, then push.
// else if ] } > ), then pop.

// after all compare
// if(L.empty()==0) --> tell "closing braket is more."
// if(head != nullptr) --> tell "open braket is more" 

// else "what do you input? do not make any space between blankets

	for (i=0; i<strlen(d) ; i++)
	{
		if((d[i]=="{")||(d[i]=="(")||(d[i]=="[")||(d[i]=="<")){
			L.push(c);}
		else if ((d[i]=="}")||(d[i]=="}")||(d[i]=="]")||(d[i]==">")){
			if(L.top() != d[i]){
				cout "braket doesn't match!" << endl;
				return false;}



			else {
				// before L.pop(), need to set error msg when isEmpty().

				L.pop();}

		else { cout << "other reason. not match" << endl; return false;}
	}
	if (head != nullptr){ return false; }

char revert(char k){
	


/*
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
*/

void test_LinkedStack(string file_name, LinkedStack& L)
{
	fillAll(file_name, L);
}

int main(int argc, char* argv[])
{
	char* d;
	d = new char;		
	cout << "input string of brakets"
	cin >> d;
	LinkedStack a;
	test_LinkedStack(d, a);

	return 0;
}

