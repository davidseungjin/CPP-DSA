#include <iostream>
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
		:head(NULL){}
	~LinkedStack(){}
	void push(char c) { head = new ListNode(c, head); }
	char pop();
	char top() { return head->info; }
	bool isEmpty() { return head == NULL; }
};

char LinkedStack::pop(){
	ListNode* p = head;
	char c = head->info;
	head = head -> next;
	delete p;
	return c;
}

bool isBalanced(string& d)
{
	LinkedStack L;

	int i;
	for (i=0; i< d.length() ; i++)
	{
		if((d[i]=='{')||( d[i]=='(' )||(d[i]=='[')||(d[i]=='<'))
		{
			L.push(d[i]);
		}
		else if ((d[i]=='}')||(d[i]==')')||(d[i]==']')||(d[i]=='>'))
		{		
			if (d[i] == '}' ){d[i] = '{'; }			//assign to compare
			else if (d[i] == ')' ){d[i] = '('; }
			else if (d[i] == ']' ){d[i] = '['; }
			else {d[i] = '<'; }

			if(L.isEmpty())
			{
				return 0;
			} 
			else
			{
			
				if(L.top() == d[i])
				{
					L.pop();
				}
				else 
				{
					return 0;
				}
			}
		}
	}
	if (!(L.isEmpty()))
	{ 
		return 0;
	}else {
		return 1;
	}
}


int main()
{
	string d;
	cout << "input string brakets...";
	cin >> d;

	cout << boolalpha << isBalanced(d) << endl;

	return 0;
}

