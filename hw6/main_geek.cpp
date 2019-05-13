#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Timer.h"

using namespace std;

class BST
{
    struct node{
        string data;
        int info;
        node* left;
        node* right;
    };
    
    node* root;
    
    node* makeEmpty(node* t){
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }
    
    node* insert(string w, node* t){
        if(t == NULL)
        {
            t = new node;
            t->data = w;
            t->info = 1;
            t->left = NULL;
            t->right = NULL;
        }
        else if(w < t->data)
            t->left = insert(w, t->left);
        else if(w > t->data)
            t->right = insert(w, t->right);
        return t;
    }
    
    node* successor(node* t){
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return successor(t->left);
    }
    
    node* predecessor(node* t){
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return predecessor(t->right);
    }
    
    node* remove(string w, node* t){
        node* temp;
        if(t == NULL)
            return NULL;
        else if(w < t->data)
            t->left = remove(w, t->left);
        else if(w > t->data)
            t->right = remove(w, t->right);
        else if(t->left && t->right)
        {
            temp = successor(t->right);
            t->data = temp->data;
            delete temp;
            //            t->right = remove(t->data, t->right);
        }

        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
        
        return t;
    }
    
    void inorder(node* t)
    {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << endl;
        inorder(t->right);
    }
    
    void preorder(node* t)
    {
        if(t == NULL)
            return;
        cout << t->data << endl;
        inorder(t->left);
        inorder(t->right);
    }
    
    void postorder(node* t)
    {
        if(t == NULL)
            return;
        inorder(t->left);
        inorder(t->right);
        cout << t->data << endl;;
    }
    
    
    node* find(node* t, string w)
    {
        if(t == NULL)
            return NULL;
        else if(w < t->data)
            return find(t->left, w);
        else if(w > t->data)
            return find(t->right, w);
        else
            return t;
    }
    
public:
    BST(){
        root = NULL;
    }
    
    ~BST(){
        root = makeEmpty(root);
    }
    
    void insert(string w){
        root = insert(w, root);
    }
    
    void remove(string w){
        root = remove(w, root);
    }
    
    void display(){
        inorder(root);
        cout << endl;
    }

    void display_pre(){
        preorder(root);
        cout << endl;
    }

    void display_post(){
        postorder(root);
        cout << endl;
    }

    
    void search(string w){
        root = find(root, w);
        cout << "in search function calling find function" << endl;
//        cout << root -> left -> data << " is found" << endl;
    }
};


void insertAllWords(BST& T, int partition, string& input_file){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        for(int i=0; i < partition*4500; i++){
            
            getline(f,w);
            cout << "w is " << w << endl;
            T.insert(w);         // test test test test
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "insertAllWords time of\t" << "partition\t" << partition << " is " << eTime << endl;
}

void findAllWords(BST& T, int partition, string& input_file){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        for(int i=0; i < partition*10; i++){
            getline(f, w);
            T.search(w);      // test test test test
            cout << "after T.search" << endl;
            
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "findAllWords time of\t" << "partition\t" << partition << " is " << eTime << endl;
}

void removeAllWords(BST& T, int partition, string& input_file){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        for(int i=0; i < partition*10; i++){
            getline(f, w);
            T.remove(w);
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "removeAllWords time of\t" << "partition\t" << partition << " is " << eTime << endl;
}


void measureAll(string input_file, BST& T){
    for (int i=1; i<=1; ++i){
        cout << " ========= " << "Partition" << i << " ========= " << endl;
        insertAllWords(T, i, input_file);
//        T.display();
//        cout << "\n\n\n\n\n\n\n\n\n\n" ;
//
        T.display_pre();
        cout << "intenional blank line " << endl;
//
//        cout << "\n\n\n\n\n\n\n\n\n\n" ;
//        T.display_post();
        cout << "intenional blank line " << endl;
        findAllWords(T, i, input_file);
//        removeAllWords(T, i, input_file);
    }
}


int main(int argc, char* argv[]){
    
    const char* input_file = argc == 2? argv[1] : "random_120.txt";
    
    BST D;
    measureAll(input_file, D);
    
    return 0;
}
