#include <iostream>
#include <string>
#include <list>


using namespace std;

class Hash{
	int bucket;		// No. of buckets.
	list<int> *table;	// pointe to an array containing buckets
public:
	Hash(int v);
	void insertItem(string x);
	void deleteItem(string key);
	int hashFunction(string x){
        unsigned result = 0;
        int len = x.size();
        for (int i=0; i<len; i++){ result += i; }
        return (result % bucket);		// hash function to map values to key
	}
	void displayHash();
};

Hash::Hash(int b){
	this->bucket = b;
	table = new list<int>[bucket];
}

void Hash::insertItem(string key){
	int index = hashFunction(key);
	table[index].push_back(key);
}

void Hash::deleteItem(string key){
	int index = hashFunction(key);		//get the hash index of key
	list<int>::iterator i;		//find the key in (index)th list
	for(i = table[index].begin(); i != table[index].end(); i++){
		if (*i == key)
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
/*
void testHash(string file_name, Hash& L)
{
    //call test functions
    ifstream f(file_name.c_str());
    string w;
    if(f.is_open()){
        while(getline(f, w)){
            hasher.insert(w);
        }
    }
    f.close();
    //you may want to instantiate a ChainedHashTable
    //object to pass as a reference to some of your
    //more advanced testing functions
}
*/

int main(int argc, char* argv[]){
    argv[1] = "random_5.txt";
    const char* input_file = argv[1];
    
    
	string a[] = {"a","aa","b","bb","c","cc","abc","abd","adb","dab","ded","ee","ww", "qq", "asa"};
	Hash h(10); 		// 10 is count of buckets in hash table
	for (int i=0; i < 10 ; i++)
		h.insertItem(a[i]);

	h.deleteItem("aa");

	h.displayHash();
	
	return 0;
}

	
