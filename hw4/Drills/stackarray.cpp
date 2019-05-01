#include <iostream>
#define max 4
using namespace std;

class StackArray{
	int top;
public:
	int a[max];	//Maximum size of Stack

	StackArray(){ top = -1; }
	bool push(int x);
	int pop();
	bool isEmpty();
};

bool StackArray::push(int x)
{
	if(top>=(max-1))
	{
		cout << "Stack Overflow";
		return false;
	}
	else
	{
		a[++top] = x;
		cout << x << "pushed into stack \n";
		return true;
	}
}

int StackArray::pop()
{
	if (top < 0)
	{
		cout << "Stack Underflow \n";
		return 0;
	}
	else
	{
		cout << "stack at top is " << a[top] << endl;
		int x = a[top--];
		return x;
	}
}

bool StackArray::isEmpty()
{
	return (top < 0);
}

int main()
{
	class StackArray s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.pop();
	s.push(50);
	s.push(60);
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	
	return 0;
}

