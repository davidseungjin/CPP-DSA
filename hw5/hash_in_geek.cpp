#include <iostream>
#include <list>

using namespace std;

class Hash{
	int bucket;		// No. of buckets.
	list<int> *table;	// pointe to an array containing buckets
public:
	Hash(int v);
	void insertItem(int x);
	void deleteItem(int key);
	int hashFunction(int x){
		return (x % bucket);		// hash function to map values to key
	}
	void displayHash();
};

Hash::Hash(int b)
{
	this->bucket = b;
	table = new list<int>[bucket];
}

void Hash::insertItem(int key)
{
	int index = hashFunction(key);
	table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
	int index = hashFunction(key);		//get the hash index of key
	list<int>::iterator i;			//find the key in (index)th list
	for(i = table[index].begin(); i != table[index].end(); i++){
		if (*i==key)
			break;
	}
	if (i != table[index].end())
		table[index].erase(i);
}

void Hash::displayHash(){
	for(int i=0;i<bucket;i++){
		cout << i;
		for (auto x: table[i])
			cout << " --> " << x;
		cout << endl;
	}
}

int main(){
	int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14, 15, 27};
	int n = sizeof(a)/sizeof(a[0]);

	Hash h(7); 		// 7 is count of buckets in hash table
	for (int i=0; i < n ; i++)
		h.insertItem(a[i]);

	h.deleteItem(12);

	h.displayHash();
	
	return 0;
}

	
