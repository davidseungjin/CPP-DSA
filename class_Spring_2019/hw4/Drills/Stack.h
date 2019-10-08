
template
	<typename Type>
class Stack
{
	int max;
	int len;
	Type* buf;
public:
	Stack(int capacity = 100);
	~Stack();
	void push(Type x);
	Type pop();
	int size();
};

