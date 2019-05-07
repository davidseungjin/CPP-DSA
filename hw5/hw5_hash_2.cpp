
#include<iostream>
//#include<cstdlib>
//#include<string>
//#include<cstdio>
#include <fstream>
#include<string>

using namespace std;
const int TABLE_SIZE = 13;

/*
 * ListNode Class Declaration
 */
class ListNode{
public:
    string key;
    int value;
    ListNode* next;
    ListNode(string key, int value){
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};

/* Hash function, Hash code: base, derived.
 */
struct Hasher{
    virtual int hash(string key) = 0;
};

struct GeneralStringHasher:public Hasher{
    virtual int hash(string key){
        unsigned result = 0;
        int len = key.size();
        for(int i=0; i < len ; i++){result += i;}
        return result % TABLE_SIZE;
    }
};

/*
 * Hashtable Class Declaration
 */
class Hashtable:public GeneralStringHasher{
private:
    ListNode** htable;
    ListNode* head;

    
public:
    Hashtable(){
        htable = new ListNode*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
            htable[i] = NULL;
        cout << "constructor is called" << endl;
    }
    ~Hashtable(){
        for (int i = 0; i < TABLE_SIZE; ++i){
            ListNode* entry = htable[i];
            while (entry != NULL){
                ListNode* prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
        delete[] htable;
        cout << "destructor for htable is called" << endl;
    }
    
    /*
     * Insert Element at a key
     */
    void insert(string key, int value){
        int hash_value = GeneralStringHasher::hash(key);
  //      cout << "hash key is : " << GeneralStringHasher::hash(key) << endl;
        ListNode* prev = NULL;
        ListNode* entry = htable[hash_value];
// this while-loop looks insert at tail position. what if we just want to add at head, what should I do?
        cout << "insert function is called\n" << hash_value << ' ' << value << endl;
        
        
        while (entry != NULL){
            prev = entry;
            entry = entry->next;
        }
// above.
        if (entry == NULL){
            entry = new ListNode(key, value);
            // if-else: it's little confusing: why this is necessary?
            if (prev == NULL){
                htable[hash_value] = entry;
                cout << "entry NULL prev NULL case execute?" << endl;
            }else{
                prev->next = entry;
                cout << "entry NULL prev negate NULL case execute" << endl;
            }
        }else{
            entry->value = value;
        }
    }
    
    /*
     * Remove Element at a key
     */
    void remove(string key)
    {
        int hash_value = GeneralStringHasher::hash(key);
cout << "remove hashcode" << endl;
        ListNode* entry = htable[hash_value];
cout << "ListNode entry pointer creation" << endl;
        ListNode* prev = NULL;
cout << "prev = NULL" << endl;
        if (entry == NULL || entry->key != key){
            cout<<"No Element found at key "<<key<<endl;
            return;
        }
        cout << "remove: before while" << endl;
        while (entry->next != NULL){
            prev = entry;
            entry = entry->next;
        }
        cout << "remove: after while, before if "<< endl;
        if (prev != NULL){
            prev->next = entry->next;
        }
        delete entry;
        cout<<"Element Deleted"<<endl;
    }
 
    int find(string key){
        bool flag = false;
        int hash_value = GeneralStringHasher::hash(key);
        ListNode* entry = htable[hash_value];
        cout << "find before while" << endl;
        while (entry != NULL){
            if (entry->key == key){
                cout<<entry->value<<" ";
                flag = true;
            }
            entry = entry->next;
        }
        cout << "find after while"<< endl;
        if (!flag)
            return -1;
    }
};
 
 
//insert all
void insertAll(string file_name, Hashtable& hash){
    cout << "1.  insertAll start?" << endl;
    ifstream f(file_name.c_str());
    cout << "2.  insertAll start?" << endl;
    string w;
    cout << "3.  insertAll start?" << endl;
    if(f.is_open()){
        while(getline(f, w)){
            hash.insert(w, 1);
        }
        cout << "4.  insertAll start?" << endl;
        f.close();
        cout << "5.  insertAll start?" << endl;
    }
}

//overall tester function//
void testHash(string input_file, Hashtable& hash)
{
    //call test functions
    void insertAll(string input_file, Hashtable& hash);
    //you may want to instantiate a ChainedHashTable
    //object to pass as a reference to some of your
    //more advanced testing functions
}


/*
 * Main Contains Menu
 */
int main(int argc, char* argv[]){
//    const char* input_file = argv[1];
    const char* input_file = argc == 2? argv[1] : "random_5.txt";
//
//    Hashtable test;
//    Hashtable& a = test;
//    a.insert("testtest", 1);
//    a.insert("testtes", 2);
//    a.insert("testte", 3);
//    a.insert("testt", 4);
//    a.insert("testt", 5);
//    a.insert("testte", 6);
//
//    a.find("testte");
//    a.find("testtes");


    GeneralStringHasher h;
    Hasher& hasher = h;
    testHash(input_file, h);

    return 0;
}
