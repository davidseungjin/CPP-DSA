#include<iostream>
using namespace std;

int main()
{
	int david[]={1,3,4,25,5,9,6,7,8,10,22,32};
	int num;
	cout << "input ?";
	cin >> num;
	int i=0;
	for(i=0;i<12;i++)
		if (num==david[i])
		{
			cout <<"found\n";
		}
		else
		{
			cout << "not found\n";
		}	

	cout << "location is " << i << endl;
}

			
	
