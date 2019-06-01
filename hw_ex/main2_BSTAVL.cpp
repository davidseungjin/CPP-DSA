#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Timer.h"

using namespace std;

class BST
{
    struct Node{
        string data;
        int info;
        Node* left;
        Node* right;
    };
    Node* t;
    
    Node* clean(Node* t){
        if(t == NULL)
            return NULL;
        else{
            clean(t->left);
            clean(t->right);
            delete t;
        }
        return NULL;
    }
    
    Node* insert(string w, Node* t){
        if(t == NULL)
        {
            t = new Node;
            t->data = w;
            t->info = 1;
            t->left = NULL;
            t->right = NULL;
        }
        else if(w < t->data)
            t->left = insert(w, t->left);
        else if(w > t->data)
            t->right = insert(w, t->right);
        cout << t->data <<"\t t-> left is \t" << t-> left << "\t t->right is \t" << t->right<< endl;
        return t;
    }
    
    Node* successor(Node* t){
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return successor(t->left);
    }
    
    Node* predecessor(Node* t){
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return predecessor(t->right);
    }
 
    Node* find(string w, Node* t)
    {
        cout << "w is " << w << endl;
        cout << "t data/left/right are " << t->data <<"\t"<< t->left <<"\t"<< t->right << endl;
        cout << "t decendants are " << t->left->data <<"\t"<< t->right->data <<"\t"<< endl;
        
        
        while ( t != NULL )
            if ( w  <  t->data ){
                cout << "w is " << w << " and t-> data is " << t->data << " so " << endl;
                cout << "go to t-> left" << endl;
                t = t->left;
            }else if ( w  >  t->data ){
                cout << "w is " << w << " and t-> data is " << t->data << " so " << endl;
                cout << "go to t-> right" << endl;
                t = t->right;
            }else{ // found it!
                cout << " fount it because w and t-> data is " << w << "\t /" << t-> data << endl;
                return t;
            }
        return NULL;
    }

        /*
        if(t == NULL){
            cout << "NULL" << endl;
            return NULL;
        }
        else if(w < t->data){
            cout << "w is " << w << " and t is " << t->data << " t is not NULL, but less than t->data so, go to find(w, t->left)" << endl;
            return find(w, t->left);
        }
        else if(w > t->data){
            cout << "w is " << w << " and t is " << t->data << " t is not NULL, but greater than t->data so, go to find(w, t->right)" << endl;
            return find(w, t->right);
        }
        else{
            cout << "w is " << w << " and Found in nodes contain " << t->data << endl;
            return t;
        }
     
    }
         */
   
    Node* remove(string w, Node* t){
        cout << "remove starting" << endl;
        cout << "w is " << w << endl;
        cout << "t -> data is " << t-> data << endl;
        Node* temp;
        if(t == NULL){
            cout << "1. return if-statement: NULL" << endl;
            return NULL;
        }else if(w < t->data){
            cout << "condition when w < t-> data: go remove(w, t->left)" << endl;
            t->left = remove(w, t->left);
        }else if(w > t->data){
            cout << "condition when w > t-> data: go remove(w, t->right)" << endl;
            t->right = remove(w, t->right);
        }else if (t->left == NULL && t-> right == NULL){
            cout << "both left, right are null" << endl;
            return NULL;
        }else if (t->left == NULL && t-> right != NULL){
            cout << "left is NULL, right is NOT null" << endl;
            temp = successor(t->right);
            t = temp;
            delete temp;
        }else if (t-> left != NULL && t->right == NULL){
            cout << "left is NOT NULL, right is null" << endl;
            temp = predecessor(t->left);
            t = temp;
            delete temp;
        }else{
        // two pointers are alive.
            temp = successor(t->right);
            t = temp;
            delete temp;
        }
        cout << "w is " << w << " and t-> data now is " << t->data << endl;
        return t;
    }
    
    void inorder(Node* t){
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << endl;
        inorder(t->right);
    }

    /*
    void preorder(Node* t){
        if(t == NULL)
            return;
        cout << t->data << endl;
        inorder(t->left);
        inorder(t->right);
    }
    
    void postorder(Node* t){
        if(t == NULL)
            return;
        inorder(t->left);
        inorder(t->right);
        cout << t->data << endl;;
    }
    */
     
public:
    BST(){
        t = NULL;
    }
    ~BST(){
        t = clean(t);
    }
    
    void insert(string w){
        t = insert(w, t);
        
    }
    
    void remove(string w){
        t = remove(w, t);
    }
    
    void display(){
        inorder(t);
        cout << endl;
    }

    /*
    void display_pre(){
        preorder(root);
        cout << endl;
    }

    void display_post(){
        postorder(root);
        cout << endl;
    }
     */
    
    void search(string w){
        t = find(w, t);
    }
};

void insertAllWords(BST& T, int partition, string input_file){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        for(int i=0; i < partition*200; i++){
            getline(f,w);
            T.insert(w);
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "insertAllWords time of\t" << input_file << "\tpartition\t" << partition << " is\t" << eTime << endl;
}

void findAllWords(BST& T, int partition, string input_file){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        for(int i=0; i < partition*200; i++){
            getline(f,w);
            T.search(w);
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "findAllWords time of\t" << input_file << "\tpartition\t" << partition << " is\t" << eTime << endl;
}

void removeAllWords(BST& T, int partition, string input_file){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        for(int i=0; i < partition*1; i++){
            getline(f,w);
            T.remove(w);
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "removeAllWords time of\t" << input_file << "\tpartition\t" << partition << " is\t" << eTime << endl;
}

void measureAll(string input_file, BST& T){
    for (int i=1; i<=1; ++i){
        cout << " ========= " << "Partition" << i << " ========= " << endl;
        insertAllWords(T, i, input_file);
//        T.display();
        findAllWords(T, i, input_file);
//        removeAllWords(T, i, input_file);
        T.display();
    }
}


int main(int argc, char* argv[]){
    
    const char* input_file = argc == 2? argv[1] : "random.txt";
    
    BST D;

    
    measureAll(input_file, D);
    
    return 0;
}
