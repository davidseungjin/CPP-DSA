#include <iostream>

using namespace std;

class A
{
public:
	virtual void display()
	{
		cout << "this is function of class A" << endl;
	}
};

class B:public A
{
public:
	void display()
	{
		cout << "this is function of class B" << endl;
	}
};

/*
void test(B& L)
{
	L.display();
}
*/

void test(A* p)
{
	p->display();
}


int main(){
	A* a;
	B b;
	a = &b;
	a->display(); // class A function is called when function of class A is not virtual

	cout << "address of *a is pointing to is"<< a << endl;
	cout << "address of *a is(&a) "<< &a << endl;
	cout << "address of b is "<< &b << endl;


	cout << "below is void function test" << endl;
	test(a);


	cout << "other simple pointer and dereference expression" << endl;
	int c = 10;
	int* d = &c;
	
	cout << "value of c is "<< c << endl;
	cout << "address of c is "<< &c << endl;
	cout << "value of *d is pointing to is "<< d << endl;
	cout << "address of d pointer is "<< &d << endl;
	cout << "dereferencing of pointer d is "<< *d << endl;

	
	return 0;
}

