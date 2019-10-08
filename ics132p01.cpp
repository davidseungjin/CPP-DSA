#include<iostream>


using namespace std;

double factori(double x){
	if(x <= 1.0){
		return x;
	}else{
		return (factori(x-1) * x);
	}
}

double factori2(double a, double x){
	if(x == 0){
		return 1;
	} else if (x == 1){
		return 1 + a;
	} else {
		return (factori2(a-1, x-1) + ((a^x) / factori(x))); 
	}
}

double factori3(double a, double x){
	return (((a^x)/factori(x))/factori2(a, x));
}

int main(){
	double x;
	double a = 2.5;

//	cout << "what is y? " << endl;
//	cin >> a;
	cout << "what is x? " << endl;
	cin >> x;

	cout << "===================" << endl;
	cout << "reference, get factori 1 and 2" << endl;
	cout << "factori for " << x << " is " << factori(x) << endl;
	cout << "factori2 for " << a << ", " << x << " is " << factori2(a, x) << endl;

	cout << "B value is " << factori3(a, x) << endl;

	return 0;

}


