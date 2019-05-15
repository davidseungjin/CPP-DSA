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
    Node* root;
    
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
        if(t == NULL)
            return NULL;
        else if(w < t->data)
            return find(w, t->left);
        else if(w > t->data)
            return find(w, t->right);
        else
            return t;
    }
   
    Node* remove(string w, Node* t){
        Node* temp;
        if(t == NULL){
            return NULL;
        }else if(w < t->data){
            t->left = remove(w, t->left);
        }else if(w > t->data){
            t->right = remove(w, t->right);
        }else if (t->left == NULL && t-> right == NULL){
            return NULL;
        }else if (t->left == NULL && t-> right != NULL){
            temp = successor(t->right);
            t = temp;
            delete temp;
        }else if (t-> left != NULL && t->right == NULL){
            temp = predecessor(t->left);
            t = temp;
            delete temp;
        }else{
        // two pointers are alive.
            temp = successor(t->right);
            t = temp;
            delete temp;
        }
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
        root = NULL;
    }
    ~BST(){
        root = clean(root);
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
        root = find(w, root);
    }
};

void insertAllWords(BST& T, int partition, string input_file){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        for(int i=0; i < partition*10; i++){
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
        for(int i=0; i < partition*10; i++){
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
        for(int i=0; i < partition*10; i++){
            getline(f,w);
            T.insert(w);
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "removeAllWords time of\t" << input_file << "\tpartition\t" << partition << " is\t" << eTime << endl;
}

void measureAll(string input_file, BST& T){
    for (int i=1; i<=5; ++i){
        cout << " ========= " << "Partition" << i << " ========= " << endl;
        insertAllWords(T, i, input_file);
//        T.display();
        findAllWords(T, i, input_file);
        removeAllWords(T, i, input_file);
    }
}


int main(int argc, char* argv[]){
    
    const char* input_file = argc == 2? argv[1] : "random.txt";
    
    BST D;

    
    measureAll(input_file, D);
    
    return 0;
}
