#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Timer.h"

using namespace std;

template <typename KeyType, typename ElementType>
class BST
{
    struct Node{
        KeyType data;
        ElementType info;
        Node* left;
        Node* right;
    };
    
    Node* root;
    
    Node* makeEmpty(Node* t){
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }
    
Node* insert(KeyType w, Node* t){
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
 
    Node* find(KeyType w, Node* t)
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
   
    Node* remove(KeyType w, Node* t){
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
        root = find(w, root);
    }
};

template <typename KeyType, typename ElementType>
void insertAllWords(BST& T, int partition, KeyType& input_file){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        for(int i=0; i < partition*4500; i++){
            getline(f,w);
            T.insert(w);
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "insertAllWords time of\t" << "partition\t" << partition << " is " << eTime << endl;
}

template <typename KeyType, typename ElementType>
void findAllWords(BST& T, int partition, KeyType& input_file){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        for(int i=0; i < partition*4500; i++){
            getline(f, w);
            T.search(w);
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "findAllWords time of\t" << "partition\t" << partition << " is " << eTime << endl;
}

template <typename KeyType, typename ElementType>
void removeAllWords(BST& T, int partition, KeyType& input_file){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        for(int i=0; i < partition*4500; i++){
            getline(f, w);
            T.remove(w);
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "removeAllWords time of\t" << "partition\t" << partition << " is " << eTime << endl;
}

template <typename KeyType, typename ElementType>
void measureAll(KeyType input_file, BST& T){
    for (int i=1; i<=10; ++i){
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