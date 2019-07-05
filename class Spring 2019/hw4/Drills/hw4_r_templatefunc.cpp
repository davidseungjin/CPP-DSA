#include<iostream>
//using namespace std;

// template function definition

template<typename Type>
Type min(Type a, Type b)
{
	return a<b?a:b;
}

int main()
{
	int x = min(10,20);
	double y = min(10.5,20.5);
	std::cout << x << std::endl << y << std::endl;

	return 0;
}

