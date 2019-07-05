#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Timer.h"

using namespace std;

class BST{
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
    int getBalance(Node* t){
        //        if (N == NULL)
        //            return 0;
        return t == NULL ? 0 : (height(t->left) - height(t->right));
    }
    
    Node* insert(string w, Node* t){
        if(t == NULL){
//            cout << "NULL if statement" << endl;
            t = new Node;
            t->data = w;
            t->height = 1;
            t->left = NULL;
            t->right = NULL;
        }else if(w < t->data){
//            cout << "go to left\n";
            t->left = insert(w, t->left);
        }else if(w > t->data){
//            cout << "go to right\n";
            t->right = insert(w, t->right);
        }
//        cout << t->data << "  t address is " << t << "  t-> left is  " << t-> left << "  t->right is  " << t->right<< endl;
//        cout << "t -> data is : " << t->data << endl;
//        cout << "t -> left is : " << t->left << endl;
//        cout << "t -> right is : " << t->right << endl;
        int balance = getBalance(t);

        if (balance > 1 && (w < (t -> left -> data))){
            return rR(t);
        }

        if (balance < -1 && (w > (t -> right -> data))){
            return lR(t);
        }

        if (balance > 1 && (w > (t -> left -> data))){
            t -> left = lR(t -> left);
            return rR(t);
        }

        if (balance < -1 && (w < (t -> right -> data))){
            t->right = rR(t -> right);
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
//            cout << t << "  " << t-> data << endl;
//            t = t -> right;
//            cout << t << "  " << t-> data << endl;
//
//             cout << "w is " << w << endl;
//            cout << "t data/address/left/right are " << t->data <<"  "<< t << "  " << t->left <<"  "<< t->right << endl;
//            cout << "t decendants are " << t->left->data <<"\t"<< t->right->data <<"\t"<< endl;
//          If it is included, segmentation error occurs because I guess t->left crashes becuase of asking no allocated memory location.
            if ( w  <  t->data ){
//                cout << "w is " << w << " and t-> data is " << t->data << " so " << endl;
//                cout << "go to t-> left" << endl;
                find(w, t -> left);
//                t = t->left;
                break;
            }else if ( w  >  t->data ){
//                cout << "w is " << w << " and t-> data is " << t->data << " so " << endl;
//                cout << "go to t-> right" << endl;
                find(w, t -> right);
                break;
//                t = t->right;
            }else{ // found it!
//                cout << " fount it because w and t-> data is " << w << "\t /" << t-> data << endl;
                return t;
             
                
            }
        }
        return NULL;
    }

//    {
////        Node* temp = new Node;
////        temp = t;
////
////        cout << t << t-> data << t -> left << t -> right << endl;
////        cout << temp << temp-> data << temp -> left << temp -> right << endl;
////
//
//        if(t == NULL){
//            cout << "NULL" << endl;
//            return NULL;
//        }else if(w < temp->data){
//            cout << "w is " << w << " and t is " << temp->data << " t is not NULL, but less than t->data so, go to find(w, t->left)" << endl;
//            return find(w, temp->left);
//        }else if(w > temp->data){
//            cout << "w is " << w << " and t is " << temp->data << " t is not NULL, but greater than t->data so, go to find(w, t->right)" << endl;
//            return find(w, temp->right);
//        }else{
//            cout << "w is " << w << " and Found in nodes contain " << temp->data << endl;
////            delete temp;
//            return t;
//        }
//
//    }

   
    Node* remove(string w, Node* t){
//        cout << "Remove\t\tstarting" << endl;
//        cout << "w is\t\t" << w << endl;
//        cout << "t is " << t << endl;
//        cout << "t -> data is \t"<< t-> data << endl;
        
        /*
        if(t == NULL){
            cout << "1. return if-statement: NULL" << endl;
            return NULL;
        }else if(w < t->data){
            cout << "condition when w < t-> data: go remove(w, t->left)" << endl;
            t= t->left;
            cout << "t -> left -> data is " << t->data << endl;
            remove(w, t);
        }else if(w > t->data){
            cout << "condition when w > t-> data: go remove(w, t->right)" << endl;
            t = t->right;
            cout << "t -> right -> data is " << t->data << endl;
            remove(w, t);
        }else{
            return t;
        }
        */
        
//        cout << " ===== before find function =====" << endl;
        find(w, t);
//        cout << " ===== after find function =====" << endl;
        if(t == NULL){
//            cout << "return NULL" << endl;
            return NULL;
        }else if (t->left == NULL && t-> right == NULL){
//            cout << "\t\tBOTH NULL" << endl;
            return NULL;
        }else if (t->left == NULL && t-> right != NULL){
//            cout << "\t\tLeft only NULL" << endl;
            Node* temp;
            temp = t->right;
            t = temp;
            delete temp;
//            return t;
        }else if (t-> left != NULL && t->right == NULL){
//            cout << "\t\tRight only NULL" << endl;
            Node* temp;
            temp = t->left;
            t = temp;
            delete temp;
//            return t;
        }else{
        // two pointers are alive.
//            cout << "\t\tBoth Alive" << endl;
//            cout << "t-> right: successor is " << t->right->data << endl;
//            cout << "t address/data/left/right before successor is \n: " << t << "  " << t->data << "  " << t->left << "  " << t->right << endl;
//
//            cout << "successor is " << successor(t -> right) << endl;
//            cout << "predecessor(successor) is " << predecessor(successor(t ->right)) << endl;
//
            Node* temp;
            temp = predecessor(successor(t -> right));
            swap(temp->data, t->data);
            
//            cout << "temp and its address, left, right is \n: " << temp << "  " << temp -> data << "  " << temp -> left << "  " << temp -> right << endl;
//            cout << "t address/data/left/right after successor is\n: " << t  << "  " << t->data  << "  " << t->left << "  " << t->right << endl;

//            cout << "temp -> data before NULL: " << temp -> data << endl;
            
//            remove(w, temp);
//            cout << "temp after NULL: " << temp << endl;
            
            temp = NULL;
            delete temp;
            
            
            
//            return t;
        }
        if (t == NULL)
            return t;
        
        t->height = 1 + max(height(t->left),
                                 height(t->right));
        
        int balance = getBalance(t);
        
        if (balance > 1 && getBalance(t->left) >= 0){
            return rR(t);
        }
        
        if (balance > 1 && getBalance(t->left) < 0){
            t->left = lR(t->left);
            return rR(t);
        }
        
        if (balance < -1 && getBalance(t->right) <= 0){
            return lR(t);
        }
        
        if (balance < -1 && getBalance(t->right) > 0){
            t->right = rR(t->right);
            return lR(t);
        }
        return t;
    }
    
    void inorder(Node* t){
        if(t == NULL){
            return;
        }
        inorder(t->left);
        cout << t->data << endl;
        inorder(t->right);
    }

    void preorder(Node* t){
        if(t == NULL)
            return;
        cout << t->data << endl;
        preorder(t->left);
        preorder(t->right);
    }
    
    void postorder(Node* t){
        if(t == NULL)
            return;
        postorder(t->left);
        postorder(t->right);
        cout << t->data << endl;;
    }
    
public:
    BST(){
        cout << "BST constructor called" << endl;
        t = NULL;
    }
    ~BST(){
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

void insertAllWords(BST& A, int partition, string input_file){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        for(int i=0; i < partition*4500; i++){
            getline(f,w);
//            cout << "w is " << w << endl;
            A.insert(w);
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "insertAllWords time of\t" << input_file << "\tpartition\t" << partition << " is\t" << eTime << endl;
}

void findAllWords(BST& A, int partition, string input_file){
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

void removeAllWords(BST& A, int partition, string input_file){
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

void measureAll(string input_file, BST& T){
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
    
    BST D;
    
    measureAll(input_file, D);
    
    return 0;
}
