#include <iostream>
#include <fstream>
#include <string>
#include "Timer.h"

using namespace std;

// An AVL tree node


class AVL{
public:
    
    struct Node{
        string data;
        Node *left;
        Node *right;
        int height;
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

    int getBalance(Node* t){
//        if (N == NULL)
//            return 0;
        return t == NULL ? 0 : (height(t->left) - height(t->right));
    }

    
    Node* insert(string w, Node* t){
        if(t == NULL){
//            cout << "NULL if statement" << endl;
            t = new Node;
            t -> data = w;
            t -> left = NULL;
            t -> right = NULL;
            t -> height = 1;
//            return t;
        }else if(w < t -> data){
//            cout << "2. Node* insert condition" << endl;
            t -> left = insert(w, t -> left);
        }else if(w > t -> data){
//            cout << "3. Node* insert condition" << endl;
            t ->right = insert(w, t -> right);
        // Equal keys are not allowed in BST
        }
        
        t->height = 1 + max(height(t->left), height(t->right));
        /*
        cout << "t -> data is : " << t->data << endl;
        cout << "t -> left is : " << t->left << endl;
        cout << "t -> right is : " << t->right << endl;
        cout << "t -> height is : " << t->height << endl;
        */
        return t;
    }
//
//        int balance = getBalance(t);
//
//        if (balance > 1 && w < t->left->data){
//            return rR(t);
//        }
//
//        if (balance < -1 && w > t->right->data){
//            return lR(t);
//        }
//
//        if (balance > 1 && w > t->left->data){
//            t->left = lR(t->left);
//            return rR(t);
//        }
//
//        if (balance < -1 && w < t->right->data){
//            t->right = rR(t->right);
//            return lR(t);
//        }
//
//
//        return t;
//    }

    Node* successor(Node* t){
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return successor(t->left);
    }
    Node* minval(Node* t){
        Node* current = t;
        
        while (current->left != NULL)
            current = current->left;
        
        return current;
    }

//    Node* find(Node* t, string w){
//        t = new Node();
//        cout << "1. find func" << endl;
//        if(t == NULL){
//            cout << "2. find func" << endl;
//            return NULL;}
//        else if(w < (t->data)){
//            cout << "3. find func" << endl;
//            return find(t->left, w);}
//        else if(w > t->data){
//            cout << "4. find func" << endl;
//            return find(t->right, w);}
//        else{
//            cout << "5. before return in find" << endl;
//            return t;}
//        return 0;
//    }
    Node* find(string w, Node* t){
        while ( t != NULL ){
            if ( w  <  t->data ){
                find(w, t -> left);
                break;
            }else if ( w  >  t->data ){
                find(w, t -> right);
                break;
            }else{ // found it!
                return t;
            }
        }
        return NULL;
    }
    
    
    
    Node* remove(string w, Node* t){
        Node* root_t;
        if(root_t == NULL){
            return root_t;
        }else if(w < root_t -> data){
            root_t->left = remove(w, root_t -> left);
        }else if(w > root_t->data){
            root_t->right = remove(w, root_t -> right);
        }else{
            if((root_t->left == NULL)||(root_t->right == NULL) ){
                Node *temp = root_t->left ?
                root_t->left :
                root_t->right;
                
                if (temp == NULL){
                    temp = root_t;
                    root_t = NULL;
                }else // One child case
                    *root_t = *temp; // Copy the contents of
                delete temp;
            }else{
                Node* temp = successor(root_t->right);
                
                root_t->data = temp->data;
                
                root_t->right = remove(temp->data, root_t -> right);
            }
        }
        
        /*
        if (root_t == NULL)
            return root_t;
        
        root_t->height = 1 + max(height(root_t->left),
                               height(root_t->right));
        
        int balance = getBalance(root_t);
        
        if (balance > 1 && getBalance(root_t->left) >= 0){
            return rR(root_t);
        }
        
        if (balance > 1 && getBalance(root_t->left) < 0){
            root_t->left = lR(root_t->left);
            return rR(root_t);
        }
        
        if (balance < -1 && getBalance(root_t->right) <= 0){
            return lR(root_t);
        }
        
        if (balance < -1 && getBalance(root_t->right) > 0){
            root_t->right = rR(root_t->right);
            return lR(root_t);
        }
         */
        
        return root_t;
    }

    void inorder(Node* t){
        if(t == NULL){
            return;
        }
        inorder(t->left);
        cout << t->data << endl;
        inorder(t->right);
    }

    
    AVL(){
        cout << "AVL constructor called" << endl;
        t = NULL;
    }
    
    ~AVL(){
        cout << "AVL destructor called" << endl;
        while( t != NULL){
            t = clean(t);
        }
//        t = clean(t);
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

};

void insertAllWords(AVL& T, int partition, string input_file){
    cout << "1. insertallwords" << endl;
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        for(int i=0; i < partition*25000; i++){
            getline(f, w);
//            cout << "3. insertallwords" << endl;
            T.insert(w);
//            cout << " count i number is " << i << endl;
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "insertAllWords time of\t" << input_file << "\tpartition\t" << partition << " is\t" << eTime << endl;
}


void findAllWords(AVL& T, int partition, string input_file){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        for(int i=0; i < partition*25000; i++){
            getline(f, w);
            T.search(w);
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "findAllWords time of\t" << input_file << "\tpartition\t" << partition << " is\t" << eTime << endl;
}

void removeAllWords(AVL& T, int partition, string input_file){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        for(int i=0; i < partition*25000; i++){
            getline(f, w);
            T.remove(w);
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "removeAllWords time of\t" << input_file << "\tpartition\t" << partition << " is\t" << eTime << endl;
}


void measureAll(string input_file, AVL& T){
    for (int i=1; i<=1; ++i){
        cout << " ========= " << "Partition" << i << " ========= " << endl;
        insertAllWords(T, i, input_file);
//                T.display();vim 
        findAllWords(T, i, input_file);
        removeAllWords(T, i, input_file);
        T.display();
    }
}
    
// Driver Code

int main(int argc, char* argv[]){
    
    const char* input_file = argc == 2? argv[1] : "random.txt";
    
    AVL D;

    measureAll(input_file, D);
    
    return 0;
}

