#include <iostream>
#include <string>

using namespace std;

template <typename E>
class Stack{
public:
	int size() const;
	bool empty() const;
	const E& top() const throw(StackEmpty);
	void push(const E& e);
	void pop() throw(StackEmpty);
};

// RuntimeException in ch. 2.4
template <typename E>
class RuntimeException{
private:
	string errorMsg;
public:
	RuntimeException(const string& err){ errorMsg = err; }
	string getMessage() const { return errorMsg; }
};




// Exception thrown on performing top or pop of an empty stack
template <typename E>
class StackEmpty: public RuntimeException{
public:
	StackEmpty(const string& err):RuntimeException(err){}
};

/* 5.1.4 Simple Array Based Stack Implementation.
Recalling that arrays in C++ starts at index 0, 
we initialize t to -1 and use this value for t to identify when the stack is empty.
Likewise, we can use this variable to determine the number of element in a Stack (t+1). 
We also introdue a new type of exception, called StackFull, to signal the error condition that arises if we try to insert a new element and the array S is full.*/

/* David: Below looks pseudocode
Algorithm size():
	return t+1;
Algorithm empty():
	return(t<0)
Algorithm top():
	if empty() then throw StackEmpty exception
	return S[t]
Algorithm push(e):
	if size() = N then
		throw StackFull exception
	t = t+1
	S[t] = e
Algorithm pop():
	if empty() then
		throw StackEmpty exception
	t = t-1;
 Our approach is to storethe elements of a stack in an array. To keep the code simple, we have omitted the standard housekeeping utilities, such as a destructor, an assignment operator, and a copy constructor. we leave their implementations as an exercise. 
 We begin by providing the ArrayStack class definition in Code Fragment 5.4
*/

template <typename E>
class ArrayStack {
	enum {DEF_CAPACITY = 100};		//default stack capacity
public:
	ArrayStack(int cap=DEF_CAPACITY);
	int size() const;
	bool empty() const;
	const E& top() const throw(StackEmpty);
	void push(const E& e) throw(Stackfull);
	void pop() throw(StackEmpty);
	// ... housekeeping functions omiotted
private:
	E* S;
	int capacity;
	int t;
};

// Next, we present the implementations of the ArrayStack memeber functions below. The first check Stack is empty before pop and top. Likewise, isFull before push.

// constructor from capacity
template<typename E> ArrayStack<E>::ArrayStack(int cap)
	:S(new E[cap]), capacity(cap), t(-1){}

// number of items in the stack
template<typename E> int ArrayStack<E>::size() const{ return (t+1);}

// is the stack empty?
template<typename E> bool ArrayStack<E>::empty() const{ return (t<0);}

//return top of stack
template<typename E>
const E& ArrayStack<E>::top() const throw(StackEmpty){
	if(empty()) throw StackEmpty("Top of empty stack");
	return S[t];
}

//push element onto the stack
template<typename E>
void ArrayStack<E>::push(const E& e) throw(StackFull){
	if(empty()) throw StackEmpty("Pop from empty stack");
	--t;
}

// original code in text: void ArrayStack<E>::push(const E& e) throw(StackFull){

int main(){
	ArrayStack<int> A;
	A.push(7);
	A.push(13);
	std::cout << A.top() << std::endl;
	A.pop();
	A.push(9);

	return 0;
}
