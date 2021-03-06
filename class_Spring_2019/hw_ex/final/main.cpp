#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Timer.h"

using namespace std;

class AVL{
    struct Node{
        string data;
        int height;
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
    int height(Node *N){
        if (N == NULL)
            return 0;
        return N->height;
    }
    
    int max(int a, int b){
        return (a > b) ? a : b;
    }
    
    Node* rR(Node *y){
        Node *x = y->left;
        Node *T2 = x->right;
        
        x->right = y;
        y->left = T2;
        
        x->height = max(height(x->left),height(x->right)) + 1;
        y->height = max(height(y->left),height(y->right)) + 1;
        
        return x;
    }
    
    Node* lR(Node *x){
        Node *y = x->right;
        Node *T2 = y->left;
        
        x->right = T2;
        y->left = x;
        
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        
        return y;
    }
    int balancing(Node* t){
        return t == NULL ? 0 : (height(t->left) - height(t->right));
    }
    
    Node* insert(string w, Node* t){
        if(t == NULL){
            t = new Node;
            t->data = w;
            t->height = 1;
            t->left = NULL;
            t->right = NULL;
        }else if(w < t->data){
            t->left = insert(w, t->left);
        }else if(w > t->data){
            t->right = insert(w, t->right);
        }

        int heightdiff = balancing(t);

        if (heightdiff > 1){
            if(w > (t -> left -> data)){
            t -> left = lR(t -> left);
            }
            return rR(t);
        }

        if (heightdiff < -1){
            if(w < (t -> right -> data)){
                t->right = rR(t -> right);
            }
            return lR(t);
        }
        
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

    Node* find(string w, Node* t){
        while ( t != NULL ){
            if ( w  <  t->data ){
                find(w, t -> left);
                break;
            }else if ( w  >  t->data ){
                find(w, t -> right);
                break;
            }else{
                return t;    
            }
        }
        return NULL;
    }

   
    Node* remove(string w, Node* t){
        find(w, t);
        if(t == NULL){
            return NULL;
        }else if (t -> left == NULL && t -> right == NULL){
            return NULL;
        }else if (t -> left == NULL && t -> right != NULL){
            Node* temp;
            temp = t -> right;
            t = temp;
            delete temp;
        }else if (t -> left != NULL && t -> right == NULL){
            Node* temp;
            temp = t -> left;
            t = temp;
            delete temp;
        }else{
            Node* temp;
            temp = predecessor(successor(t -> right));
            swap(temp -> data, t -> data);
            temp = NULL;
            delete temp;
        }
        if (t == NULL)
            return t;
        
        t -> height = 1 + max(height(t -> left),
                                 height(t -> right));
        
        int heightdiff = balancing(t);
        
        if (heightdiff > 1){
            if(w > (t -> left -> data)){
                t -> left = lR(t -> left);
            }
            return rR(t);
        }
        
        if (heightdiff < -1){
            if(w < (t -> right -> data)){
                t->right = rR(t -> right);
            }
            return lR(t);
        }
        return t;
    }
    
    void inorder(Node* t){
        if(t == NULL){
            return;
        }
        inorder(t -> left);
        cout << "(" << t -> data << "\t" << t -> height << ")" << endl;
        inorder(t -> right);
    }

    void preorder(Node* t){
        if(t == NULL)
            return;
        cout << t -> data << endl;
        preorder(t -> left);
        preorder(t -> right);
    }
    
    void postorder(Node* t){
        if(t == NULL)
            return;
        postorder(t -> left);
        postorder(t -> right);
        cout << t -> data << endl;;
    }
    
public:
    AVL(){
        t = NULL;
    }
    ~AVL(){
        t = clean(t);
//        delete[] t;
    }
    
    void insert(string w){
        t = insert(w, t);
    }
    
    void search(string w){
        find(w, t);
    }
    
    void remove(string w){
        remove(w, t);
    }
    
    void display(){
        inorder(t);
        cout << endl;
    }

    void display_pre(){
        preorder(t);
        cout << endl;
    }

    void display_post(){
        postorder(t);
        cout << endl;
    }
};

void insertAllWords(AVL& A, int partition, string input_file){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        for(int i=0; i < partition*4500; i++){
            getline(f,w);
            A.insert(w);
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "insertAllWords time of\t" << input_file << "\tpartition\t" << partition << " is\t" << eTime << endl;
}

void findAllWords(AVL& A, int partition, string input_file){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        for(int i=0; i < partition*4500; i++){
            getline(f,w);
            A.search(w);
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "findAllWords time of\t" << input_file << "\tpartition\t" << partition << " is\t" << eTime << endl;
}

void removeAllWords(AVL& A, int partition, string input_file){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        for(int i=0; i < partition*4500; i++){
            getline(f,w);
            A.remove(w);
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "removeAllWords time of\t" << input_file << "\tpartition\t" << partition << " is\t" << eTime << endl;
}

void measureAll(string input_file, AVL& T){
    for (int i=1; i<=10; ++i){
        cout << " ========= " << "Partition" << i << " ========= " << endl;
        insertAllWords(T, i, input_file);
//        T.display();
        findAllWords(T, i, input_file);
        removeAllWords(T, i, input_file);
//        T.display();
    }
}


int main(int argc, char* argv[]){
    
    const char* input_file = argc == 2? argv[1] : "random.txt";
    
    AVL D;
    
    measureAll(input_file, D);
    
    return 0;
}
