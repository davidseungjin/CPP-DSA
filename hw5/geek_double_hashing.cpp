/* double hasing is a collision resolving technique in open addressed hash tables. double hashing uses the idea of applying a second hash function to key when a collision occurs. 

double hasing can be done using :
(hash1(key) + i* hash2(key)) % TABLE_SIZE.
here hash1() and hash2() are hash functions and TABLE_SIZE is size of hash table.

First hash function is typically hash1*key) = key % TABLE_SIZE
A popular second hash function is : hash2(key) = PRIME - (key % PRIME) where PRIME is a prime smaller than the TABLE_SIZE

A good second Hash function is :
	It must never evaluate to zero
	Mush make sure that all cells can be probed. 

Ex, 	Hash1(key) = key % 13
	Hash2(key) = 7 - (key % 7)
*/

#include <iostream>
using namespace std;


#define TABLE_SIZE 13
#define PRIME 7

class DoubleHash
{
	// Pointer to an array containing buckets
	int* hashTable;
	int curr_size;

public:
	bool isFull(){				// func to check if has table is full
		return (curr_size == TABLE_SIZE);	// if hash size reaches maximum size
	}

	int hash1(int key){
		return (key % TABLE_SIZE);		//func to calculate
	}

	int hash2(int key){
		return (PRIME - (key % PRIME));
	}

	DoubleHash(){
		hashTable = new int[TABLE_SIZE];
		curr_size = 0;
		for (int i=0; i<TABLE_SIZE; i++)
			hashTable[i] = -1;
	}

	void insertHash(int key){		// function to insert key into hash table
		if(isFull())			// if hash table is full
			return;
		int index = hash1(key);		// get index from first hash
		if (hashTable[index] != -1){
			int index2 = hash2(key); 	//get index2 from second hash
			int i = 1;
			while(1){
				int newIndex = (index + i*index2) % TABLE_SIZE;
				if (hashTable[newIndex] == -1){
					hashTable[newIndex] = key;
					break;
				}
				i++;
			}
		}
		else
			hashTable[index] = key;

		curr_size++;
	}

	void displayHash(){
		for (int i=0; i < TABLE_SIZE; i++){
			if (hashTable[i] != -1)
				cout << i << "--> "
				<< hashTable[i] << endl;
			else
				cout << i << endl;
		}
	}
};

int main(){
	int a[] = {19,27,36,10,64,12,13,14,15,16,17,18,19,20,21, 22, 23, 24, 25};
	int n = sizeof(a)/sizeof(a[0]);

	DoubleHash h;
	for (int i=0; i<n; i++)
		h.insertHash(a[i]);

	h.displayHash();
	return 0;
}

