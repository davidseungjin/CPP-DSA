#include<iostream>
#include<array>

using namespace std;

/*
void copy_down(int k){
	

	
	for(int i=k; i<(size-1); i++)
		david[i] = david[i+1];
	size = size -1;
}
*/
	

int main(){
	int david[]={0,1,2,3,4,5,6,7,8,9};

	int size = sizeof(david)/sizeof(david[0]);
	for (int i=0; i<(size-1); i++)
		cout << david[i] << endl;

	cout << "size of david array is " << size << endl;
	int num;

	cout << "which index do you want to remove?" << endl;
	cin >> num;

//	copy_down(num);
	
	for(int i=num ; i<(9); i++)
		david[i] = david[i+1];
//		size = size -1;

	for (int i=0; i<(9); i++)
		cout << david[i] << endl;

	return 0;
}

