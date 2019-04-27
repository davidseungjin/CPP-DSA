#include <iostream>
#include "Stack.h"
#define ArrayLength(a) (sizeof(a)/sizeof(*a))

using namespace std;

typedef Stack<int> intStack;
typedef Stack<char> charStack;
typedef Stack<double> doubleStack;

template
	<typename T>
void fill(Stack<T>& stk, T* a, int len)
{
	for(int i=0; i<len; ++i)
		stk.push(a[i]);
}

template
	<typename T>
void empty(Stack<T>& stk)
{
	while(stk.size()>0)
		cout<<stk.pop() << ' ';
	cout << endl;
}

int main()
{
	doubleStack dstack;
	charStack cstack;
	intStack istack;

/*

	static double dlist[] = {1.5, 2.5, 3.5, 4.5, 6.5, 9.98};
	static char clist[] = "Hello";
	static int ilist[] = {0,1,2,3,4,5,6,7,8,9,10};

	fill (dstack, dlist, ArrayLength(dlist));
	fill (istack, ilist, ArrayLength(ilist));
	fill (cstack, clist, ArrayLength(clist));

	empty(dstack);
	empty(istack);
	empty(cstack);

*/

}



