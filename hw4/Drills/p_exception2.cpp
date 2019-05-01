#include <iostream>
using namespace std;
int main()
{
	int money;
	cout << "welcome to back =====" << endl;
	cout << "Enter the amount you want to deposit" << endl;
	cin >> money;
	try{
	if(money > 0)
	{
		cout << "your money deposited successfully " << endl;
	}
	else
	{
		throw (money);
	}
	}
	catch (int n){
	cout << "you have entered anegative value"; }
	return 0;
}

