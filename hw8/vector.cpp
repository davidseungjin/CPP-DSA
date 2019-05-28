#include<iostream>
#include<vector>

using namespace std;


class David{
public:
	vector<int> edge;

public:
	David(int i){
	edge.push_back(i);
	}
	~David();
};

int main(){

/*
	vector<int> myvector;
	myvector.push_back(3);

	cout << "Vector: ";

	cout << myvector.at(0);

	for(int i = 0; i < 10; i++){
		myvector.push_back(i);
		cout << "myvector[" << i << "] is : " << myvector[i] << endl;
	}
*/
	David a(2);			// error happens a lot
//	a.edge.push_back(1);
	cout << a.edge[0] << endl;


	return 0;

}

