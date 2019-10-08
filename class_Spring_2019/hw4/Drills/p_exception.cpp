#include <iostream>
using namespace std;

double division(int a, int b){
	if (b==0){
		throw "Division by zero condition";
	}
	return (a/b);
}

int main(){
	cout << "x, y  : " << endl;
	int x, y;
	cin >> x >> y;
	double z=0;

	try{
		z=division(x,y);
		cout << z << endl;
	}
	catch (const char* msg){
		cerr << msg << " this" << endl;
	}
	return 0;
}

