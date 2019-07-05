#include<iostream>
#include<stack>

using namespace std;

//static STACK;

int main(){
	stack<int> list = {1,3,5,7,9,11,13,15};
	for (int i=0; i<6; ++i)
		list.push(list[i]);
	list.top();
	for(int j=0; j<2; ++j)
		list.pop()
	return 0;
}

