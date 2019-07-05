#include<iostream>

using namespace std;

int main(){
	cout << "Hello World" << endl;
	vector<double> temps;

	for (double temp; cin>>temp;)
		temps.push_back(temp);

	cout << temps << endl;

	return 0;
}

