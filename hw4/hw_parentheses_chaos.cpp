#include <iostream>
#include <string>

using namespace std;

class LinkedStack
{
	struct ListNode{
		string info;
		ListNode* next;
		ListNode(string new_char, ListNode *new_next)
			:info(new_char), next(new_next){}
	};
	ListNode* head;
public:
	LinkedStack()
		:head(nullptr){}
	~LinkedStack(){}
	void push(string c) { head = new ListNode(c, head); }
	string pop();
	string top() { return head->info; }
	bool isEmpty() { return head == nullptr; }
	bool isFull() { return false; }
	void print(); 		// after confirming insert/remove&creating file works well, delete
	void print_top();    	// after confirming insert/remove&creating file works well, delete
};

string LinkedStack::pop(){
	ListNode* p = head;
	string c = head->info;
	head = head -> next;
	delete p;
	return c;
}

void LinkedStack::print(){
	ListNode* cur=head;
	for (cur = head; cur->next != nullptr; cur=cur->next)
	{
		cout << cur->info << "\n";
	}
}


void LinkedStack::print_top(){
	{
		cout << head->info << "\n";
	}
}

bool isBalanced(string& d)
{
	cout << "function executed" << endl;

	int i;
	for (i=0; i< d.length() ; i++)		//cout << "length of input is " << strlen(d) << endl;
	{
		
		cout << "d[" << i << "] is " << d[i] << endl;
	}
	return 0;
}


/*
		if((d[i]=='{')||( d[i]=='(' )||(d[i]=='[')||(d[i]=='<'))
		{
			L.push(d[i]);
			cout << "1.   pushing " << endl;
			cout << "1.   print_top() test" << endl;
			L.print_top();

		}
		else if ((d[i]=='}')||(d[i]==')')||(d[i]==']')||(d[i]=='>'))
		{		
			cout << "d[i] is "<< d[i] << endl;

// assign })]> to <[({
			if (d[i] == '}' ){d[i] = '{'; }
			else if (d[i] == ')' ){d[i] = '('; }
			else if (d[i] == ']' ){d[i] = '['; }
			else {d[i] = '<'; }

// assign end
			if(L.isEmpty())
			{
				cout << "2.  Stack is empty \n";
				cout << "Missing opening blackets  \n";
				L.print_top();
				return false;
			} 
			else
			{
				cout << "2.  print_top() test" << endl;
				L.print_top();
			
				if(L.top() == d[i])		// not equal, match.
				{
					L.pop();
					cout << "3. print_top() after pop()" << endl;
				}
				else 
				{
					cout << "Brakets are not match!" << endl;
//					return false;
				}
			}
		}
	}
	if (!(L.isEmpty()))
	{ 
		cout << "7. L.isEmpty() function check" << endl;
		cout<< "Missing closing brakets.(some opening brakerts remain.) \n";  
		return false;
	}else {
		cout << "Correctly Matched!" << endl;
		return true;
	}
}
*/


int main()
{
	string d;
	cout << "input string brakets...";
	cin >> d;
	bool isBalanced(string d);

	return 0;
}
