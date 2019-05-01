#include <iostream>
using namespace std;

int main(){

	char* p;
	p = new char[1000];
	cout << "input char ptr?";
	cin >> p;

	char pp[100];
	cout << "input char? ";
	cin >> pp;
	
	for (int i=0; i<(strlen(p)); i++)
		cout << p[i] << endl;
	
	cout << "length of input char ptr is " << strlen(p) << endl;

	for (int i=0; i<(strlen(pp)); i++)
		cout << pp[i] << endl;


	cout << "length of input char ptr is " << strlen(pp) << endl;

	return 0;
}

