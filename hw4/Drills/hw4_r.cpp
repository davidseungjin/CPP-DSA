#include<iostream>

using namespace std;

int min(int a, int b)
{
	return a<b?a:b;
}

double min(double a, double b)
{
	return a<b?a:b;
}


int main(){

	cout << min(2,3) << endl;
	cout << min(2.42, 2.50) << endl;

	return 0;
}

