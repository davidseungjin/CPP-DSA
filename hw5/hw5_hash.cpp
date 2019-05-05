#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// const int N = 10;
const int TABLE_SIZE = 100;


//an abstract struct to parent your various hasher classes//

class ListNode{
public:
    string key;
    int count;          // value
    ListNode* next;
    ListNode(string key, int count, ListNode *next)
    :key(key), count(count), next(nullptr){}
};

struct Hasher {
    virtual int hash(string key, int N) = 0;
};

struct GeneralStringHasher: Hasher {
    virtual int hash(string key, int N) {
        //use the “General Hash Function for Strings”
        //algorithm from lecture
        unsigned result = 0;
        int len = key.size();
        for ( int i = 0; i < len; i++ ){ result += i; }
        return result % N;
    }
};

class ChainedHashTable {
    ListNode** T;
public:
    ChainedHashTable(){
//        int length = capacity;
        T = new ListNode*[TABLE_SIZE];
        for (int i=0; i<TABLE_SIZE; ++i)
            T[i] = nullptr;
    }

    ~ChainedHashTable(){
        for(int i=0; i < TABLE_SIZE; ++i){
            ListNode* entry = T[i];
            while (entry != NULL){
                ListNode* prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
        delete[] T; // must use delete[] when using new[]
    }
  // need to pull HASHER class function.
    int hashfunc(string key){
        unsigned result = 0;
        int len = key.size();
        for ( int i = 0; i < len; i++ ){ result += i; }
        return result % TABLE_SIZE;
    }
    
    void insert(string key, int N){
        int t_index = hashfunc(key);
        ListNode* cur = nullptr;
        ListNode* begin = T[t_index];
        while (begin != nullptr){
            cur = begin;
            begin = begin -> next;
        }
    }


/*
        if (begin == nullptr){
            begin = new ListNode(key, count, next);
            if(cur == nullptr){
                T[t_index]=begin;
            } else {
                cur -> next = begin;
            }
        } else {
            begin -> count = count;
        }
    }
*/

    void remove(string key){
        int t_index = hashfunc(key);
        ListNode* begin = T[t_index];
        ListNode* cur = nullptr;
        if(begin == nullptr || begin->key != key){
            cout << "No element found at key: " << key << endl;
            return;
        }
        while (begin -> next != nullptr){
            cur = begin;
            begin = begin -> next;
        }
        if (cur != nullptr){
            cur->next = begin-> next;
        }
        delete cur;
        cout << "element deleted" << endl;
    }

    int find(string key){
        bool flag = false;
        int t_index = hashfunc(key);
        ListNode* begin = T[t_index];
        while (begin != nullptr){
            if(begin->key == key){
                cout << begin->count << " ";
                flag = true;
            }
            begin = begin -> next;
        }
        if (!flag)
            return -1;
    }
};
    //good place to stop and create your first testing
    //functions and call them from your testHashTable function
    //(see below). Run your testHashTable to check for errors.
    ////////////////////////////////////////////////////
    
    //continue incrementally adding methods to your class
    //and the respective test cases to testHashTable. Continue
    //testing your class incrementally.




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
void testHash(string file_name, Hasher & hasher)
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

    
int main(int argc, char* argv[]){
    argv[1] = "random_5.txt";
    const char* input_file = argv[1];
    
    
    GeneralStringHasher h;
    Hasher& hh = h;
    testHash(input_file, hh);
//    cout << hh.hash("string", N) << endl;

    return 0;
}
