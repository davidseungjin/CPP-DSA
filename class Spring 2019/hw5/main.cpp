#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "Timer.h"

using namespace std;

class Hash{
private:
    static const int tablesize = 10;
    
    struct Node{
        string word;
        int num;
        Node* next;
    };

    Node* HashTable[tablesize];
    
public:
    Hash(){
        for(int i=0 ; i < tablesize; i++){
            HashTable[i]=new Node;
            HashTable[i]->word = "";
            HashTable[i]->num = 0;
            HashTable[i]->next = NULL;
        }
    }
    ~Hash(){
        for(int i = 0; i<tablesize; ++i){
            Node* temp = HashTable[i];
            while(temp != NULL)
            {
                Node* prev = temp;
                temp = temp -> next;
                delete prev;
            }
        }
    }
 
    int hashfunc(string key){
        int hash = 0;
        for (int i=0 ; i < key.length() ; i++){
            hash += ((int)key[i])^2;
        }
        int index = hash % tablesize;
        return index;
    }
    
    void singleinsert(string word, int num){
        int index = hashfunc(word);
        if(HashTable[index] -> word == "empty"){
            HashTable[index] -> word = word;
            HashTable[index] -> num = 1;
        } else {
            Node* ptr = HashTable[index];
            Node* n = new Node;
            n -> word = word;
            n -> num = 1;
            n -> next = NULL;
            while(ptr -> next != NULL){
                ptr = ptr -> next;
            }
            ptr -> next = n;
        }
    }
    
    int NumberofItemsInIndex(int index){
        int count = 0;
        if(HashTable[index] -> word == "empty"){
            return count;
        } else {
            count++;
            Node* ptr = HashTable[index];
            while(ptr -> next != NULL){
                count ++;
                ptr = ptr -> next;
            }
        }
        return count;
    }
    
    void Find(string word){
        int index = hashfunc(word);
        bool found = false;
        int num;
        
        Node* ptr = HashTable[index];
        while(ptr != NULL){
            if(ptr -> word == word){
                found = true;
                num = ptr -> num;
            }
            ptr = ptr -> next;
        }
    }
    
    void Remove(string word){
        int index = hashfunc(word);
        Node* temp;
        Node* p1;
        Node* p2;
        if(HashTable[index] -> word == "empty" && HashTable[index] -> num == 1){
        } else if(HashTable[index] -> word == word && HashTable[index] -> next == NULL){
            HashTable[index] -> word = "empty";
            HashTable[index] -> num = 1;
        } else if(HashTable[index] -> word == word){
            temp = HashTable[index];
            HashTable[index] = HashTable[index] -> next;
            delete temp;
        } else {
            p1 = HashTable[index] -> next;
            p2 = HashTable[index];
            while(p1 != NULL && p1 -> word != word){
                p2 = p1;
                p1 = p1 -> next;
            }
            if(p1 == NULL){
            } else {
                temp = p1;
                p1 = p1 -> next;
                p2 -> next = p1;
                
                delete temp;
            }
        }
    }
};

class BaseFlowException
{
public:
    BaseFlowException(){}
    ~BaseFlowException(){}
};

class ContainerOverFlow:public BaseFlowException
{
private:
    string of_msg;
public:
    ContainerOverFlow(string error)
    :of_msg(error){}
    const char* getError(){ return of_msg.c_str(); }
    ~ContainerOverFlow(){}
};


class ContainerUnderFlow:public BaseFlowException
{
private:
    string uf_msg;
public:
    ContainerUnderFlow(string error)
    :uf_msg(error) {}
    const char* getError(){ return uf_msg.c_str(); }
    ~ContainerUnderFlow(){}
};

void testConstructor(Hash& L)
{
}


//overall tester function//
void insertall(string input_file, Hash& L)
{
    //call test functions
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());

    t.start();
    string w;
    if(f.is_open()){
        while(getline(f, w)){
            try{
                if(L.isFull()){
                    throw ContainerOverFlow("OverFlow Error");
                } else {
                    L.singleinsert(w, 1);
                }
            }
            catch(ContainerOverFlow& exception){
                cerr << exception.getError() << endl;
                break;
            }
        }
        t.elapsedUserTime(eTime);
       f.close();
    }
    cout << "insertall time \t" << eTime << endl;
}

void findall(string input_file, Hash& L)
{
    //call test functions
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        while(getline(f, w)){
            try{
                if(L.isFull()){
                    throw ContainerOverFlow("OverFlow Error");
                } else {
                    L.Find(w);
                }
            }
            catch(ContainerOverFlow& exception){
                cerr << exception.getError() << endl;
                break;
            }
        }
        t.elapsedUserTime(eTime);
        f.close();
    }
    cout << "findall time \t" << eTime << endl;
}


void removeall(string input_file, Hash& L)
{
    //call test functions
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        while(getline(f, w)){
            try{
                if(L.isFull()){
                    throw ContainerOverFlow("OverFlow Error");
                } else {
                    L.Remove(w);
                }
            }
            catch(ContainerOverFlow& exception){
                cerr << exception.getError() << endl;
                break;
            }
        }
        t.elapsedUserTime(eTime);
        f.close();
    }
    cout << "removeall time \t" << eTime << endl;
}

void testHash(string input_file, Hash& L){
    insertall(input_file, L);
    findall(input_file, L);
    removeall(input_file, L);
}



int main(int argc, char* argv[]){
    
    const char* input_file = argc == 2? argv[1] : "random45000.txt";
    
    
    Hash D;
    
    testHash(input_file, D);
    
    return 0;
}
