#include<iostream>
using std::endl;


class Stack
{
public:
	int len;
	int top;
	int* buf;
public:
	Stack(int capacity=100)
	:len(capacity), top(0),buf(new int[capacity])
	{}
	~Stack()
	{
		delete[] buf;
	}
	void push(int x)
	{
		buf[top++]=x;
	}
	int pop()
	{
		return buf[--top];
	}
	int size()
	{
		return top;
	}

	void print(){
		for(int i=0; i<size(); i++)
		{
			std::cout << buf[i] << std::endl;
		}
	}
};

int main(){
	Stack david;
	for(int i=0; i<10; i++)
	{
		david.push(i);
	}
	
	david.print();
	
	david.pop();
	david.push(22);
	david.print();
	std::cout << "=========" << endl;
	david.size();
	david.pop();
	david.print();
	std::cout << "=========" << endl;
	david.pop();
	david.print();
	std::cout << "=========" << endl;
	david.push(33);
	david.print();
	std::cout << "=========" << endl;

	
	david.pop();
	david.print();
	std::cout << "=========" << endl;
	david.size();
	david.print();
	std::cout << "=========" << endl;
		
	david.pop();
	david.print();
	std::cout << "=========" << endl;
	david.pop();
	david.size();
	david.print();
	std::cout << "=========" << endl;

	return 0;
}

