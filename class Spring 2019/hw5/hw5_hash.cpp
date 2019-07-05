#include <iostream>
#include <fstream>
#include <string>

using namespace std;



//an abstract struct to parent your various hasher classes//



class ChainedHashTable{
/*
    struct Hashbase{
        virtual int hash(string key, int length) = 0;
    };
*/
    struct Hash{
            int hash(string key, int length) {
            //use the “General Hash Function for Strings”
            //algorithm from lecture
            unsigned result = 0;
            int len = key.size();
            for ( int i = 0; i < len; i++ ){ result += i; }
            return result % length;
        }
    };
    
    struct ListNode{
    public:
        Hash& L;
        string key;
        int count;    // value
        ListNode* next;
        
        ListNode(Hash& L, string word, int count, ListNode *next)
        :key(word), count(count), next(nullptr){}

        void insert(string key, int count, T[h]){
            int h = hash(key, length);
            T[h] = new ListNode(key, word, count, T[h]);
        }  // this

        Object find(string key){
            int h = hash(key, length);
            ListNode* L = ListNode::find(key, T[h]);
            //        if(!L)
            return L -> info;

        void remove(string word){
            int h = hash(word, length);
            ListNode* p = T[h];
            string word = T[h]->word;
            T[h] = T[h] -> next;
            delete p;
        }
        
//        bool isEmpty() { return T[] == nullptr; }
//        bool isFull() { return false; }
    };
    ListNode* T[];
    int length;
    
public:
    ChainedHashTable(int capacity){
        int length = capacity;
        T = new ListNode*[length];
        for (int i=0; i<length; ++i)
            T[i] = nullptr;
    }

    ~ChainedHashTable(){            //must free chains, then table
        for(int i=0; i < length; ++i){
            ListNode::deleteList(T[i]);
        }
        delete[] T; // must use delete[] when using new[]
    }
};



    //good place to stop and create your first testing
    //functions and call them from your testHashTable function
    //(see below). Run your testHashTable to check for errors.
    ////////////////////////////////////////////////////
    
    //continue incrementally adding methods to your class
    //and the respective test cases to testHashTable. Continue
    //testing your class incrementally.


/*

//individual method-testing functions//
void testConstructor(Hasher & hasher)
{
    //create an empty ChainedHashTable object
}

void testCopyConstructor(Hasher & hasher)
{
    //create a ChainedHashTable object
    //create a second object as a copy of the first object
}

//etc.

//overall tester function//
void testHash(string file_name, Hash& hh)
{
    //call test functions
    ifstream f(file_name.c_str());
    string w;
    if(f.is_open()){
        while(getline(f, w)){
            hh.insert(w);
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
    
    
    Hash h;
    Hash& hh = h;
//    testHash(input_file, hh);
//    cout << hh.hash("string", N) << endl;

    return 0;
}
