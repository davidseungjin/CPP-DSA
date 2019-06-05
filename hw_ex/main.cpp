#include <iostream>
#include <fstream>
#include <string>
#include "Timer.h"

using namespace std;

// An AVL tree node
// 117 line. find function: error because node->data error


class AVL{
public:
    struct Node{
        string data;
        Node *left;
        Node *right;
        int height;
    };
    
//    Node* root;
    
    int height(Node *N){
        if (N == NULL)
            return 0;
        return N->height;
    }

    int max(int a, int b){
        return (a > b) ? a : b;
    }

    Node *rR(Node *y){
        Node *x = y->left;
        Node *T2 = x->right;
        
        x->right = y;
        y->left = T2;
        
        y->height = max(height(y->left),height(y->right)) + 1;
        x->height = max(height(x->left),height(x->right)) + 1;
        
        return x;
    }

    Node *lR(Node *x){
        Node *y = x->right;
        Node *T2 = y->left;
        
        y->left = x;
        x->right = T2;
        
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        
        return y;
    }

    int getBalance(Node *N){
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }

//
//    Node* newNode(string data){
//        Node* node = new Node();
//        node->data = data;
//        node->left = NULL;
//        node->right = NULL;
//        node->height = 1; // new node is initially
//        // added at leaf
//        return(node);
//    }
    
    Node* insert(Node* node, string data){
        cout << "1. Node* insert" << endl;
        cout << "node data is " << endl;
        cout << node -> data << endl;
        if(node == NULL){
            cout << "NULL if statement" << endl;
            node = new Node;
            node -> data = data;
            node -> left = NULL;
            node -> right = NULL;
            node -> height = 1;
            return node;
        }else if(data < node -> data){
            cout << "2. Node* insert condition" << endl;
            node -> left = insert(node -> left, data);
        }else if (data > node -> data){
            cout << "3. Node* insert condition" << endl;
            node ->right = insert(node -> right, data);
        }else // Equal keys are not allowed in BST
            return node;
        
        cout << "4. Node* insert condition" << endl;
        
        cout << "node -> data after if-statement is : " << node->data << endl;
        cout << "data is " << data << endl;

        
        node->height = 1 + max(height(node->left), height(node->right));
        
        cout << "node -> data is : " << node->data << endl;
        cout << "node -> left is : " << node->left << endl;
        cout << "node -> right is : " << node->right << endl;
        cout << "node -> height is : " << node->height << endl;
        
        
        int balance = getBalance(node);
        
        if (balance > 1 && data < node->left->data){
            return rR(node);
        }
        
        if (balance < -1 && data > node->right->data){
            return lR(node);
        }
        
        if (balance > 1 && data > node->left->data){
            node->left = lR(node->left);
            return rR(node);
        }

        if (balance < -1 && data < node->right->data){
            node->right = rR(node->right);
            return lR(node);
        }
        
        return node;
    }

    Node* minval(Node* node){
        Node* current = node;
        
        while (current->left != NULL)
            current = current->left;
        
        return current;
    }

    Node* find(Node* node, string data){
        node = new Node();
        cout << "1. find func" << endl;
        if(node == NULL){
            cout << "2. find func" << endl;
            return NULL;}
        else if(data < (node->data)){
            cout << "3. find func" << endl;
            return find(node->left, data);}
        else if(data > node->data){
            cout << "4. find func" << endl;
            return find(node->right, data);}
        else{
            cout << "5. before return in find" << endl;
            return node;}
        return 0;
    }
    
    Node* remove(string data){
        Node* root;
        if(root == NULL){
            return root;
        }else if(data < root -> data){
            root->left = remove(data);
        }else if(data > root->data){
            root->right = remove(data);
        }else{
            if((root->left == NULL)||(root->right == NULL) ){
                Node *temp = root->left ?
                root->left :
                root->right;
                
                if (temp == NULL){
                    temp = root;
                    root = NULL;
                }else // One child case
                    *root = *temp; // Copy the contents of
                delete temp;
            }else{
                Node* temp = minval(root->right);
                
                root->data = temp->data;
                
                root->right = remove(temp->data);
            }
        }
        
        if (root == NULL)
            return root;
        
        root->height = 1 + max(height(root->left),
                               height(root->right));
        
        int balance = getBalance(root);
        
        if (balance > 1 && getBalance(root->left) >= 0){
            return rR(root);
        }
        
        if (balance > 1 && getBalance(root->left) < 0){
            root->left = lR(root->left);
            return rR(root);
        }
        
        if (balance < -1 && getBalance(root->right) <= 0){
            return lR(root);
        }
        
        if (balance < -1 && getBalance(root->right) > 0){
            root->right = rR(root->right);
            return lR(root);
        }
        
        return root;
    }

    void preOrder(Node *root){
        if(root != NULL){
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
};

void insertAllWords(AVL& T, int partition, string input_file){
    cout << "1. insertallwords" << endl;
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    AVL::Node* node;
    cout << "2. insertallwords, about node" << endl;
//    cout << node << "  <-- node, node->data -->  " << node->data << endl;
    if(f.is_open()){
        for(int i=0; i < partition*1; i++){
            getline(f, w);
            cout << "3. insertallwords" << endl;
            T.insert(node, w);
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
    AVL::Node* node;
    if(f.is_open()){
        for(int i=0; i < partition*3; i++){
            getline(f, w);
            T.find(node, w);
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
    AVL::Node* node;
    if(f.is_open()){
        for(int i=0; i < partition*3; i++){
            getline(f, w);
            T.remove(w);
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "removeAllWords time of\t" << input_file << "\tpartition\t" << partition << " is\t" << eTime << endl;
}


void measureAll(string input_file, AVL& T){
    for (int i=1; i<=2; ++i){
        cout << " ========= " << "Partition" << i << " ========= " << endl;
        insertAllWords(T, i, input_file);
        //        T.display();
//        findAllWords(T, i, input_file);
//        removeAllWords(T, i, input_file);
    }
}
    
// Driver Code

int main(int argc, char* argv[]){
    
    const char* input_file = argc == 2? argv[1] : "random.txt";
    
    AVL D;

    measureAll(input_file, D);
    
    return 0;
}

