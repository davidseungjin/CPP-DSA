template
	<typename Type>
Stack<Type>::Stack(int capacity=100)
	:max(capacity), len(0), buf(new Type[capacity])
{
 std::cout << "constructor called" << endl;

}

tempate
	<typename Type>
Stack<Type>::~Stack()
{
	std::cout << "destructor called" << endl;
	delete[] buf;
}

template
	<typename Type>
void Stack<Type>::push(Type x)
{
	buf[len++]=x;
}

template
	<typename Type>
Type Stack<Type>::pop()
{
	return buf[--len];
}
template
	<typename Type>
int Stack<Type>::size()
{
	return len;
}

