#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Timer.h"

using namespace std;

/* Node Structure */
class BstNode
{
    string data;
    int info;
    BstNode* left;
    BstNode* right;
};

public:
/* Create New Node */
    BstNode *createNode(string data)
    {
        BstNode *newNode = new BstNode();
    
        newNode -> data = data;
        newNode -> info = 1;
        newNode -> left = NULL;
        newNode -> right = NULL;
        return newNode;
    }

/* Insert Node in Binary Search Tree */
    BstNode* insert(string data, int info, BstNode* root)
    {
        if (root == NULL)
            root = createNode(data);
        else if (data <= root->data)
            root->left = insert(data, info, root->left);
        else
            root->right = insert(data, info, root->right);
        return root;
    }

/* Search Node Value in Binary Search Tree */
    bool find(BstNode *root, string data)
    {
        if (root == NULL)
            return false;
        else if(data <= root->data)
            return find(root->left, data);
        else if (data > root->data)
            return find(root->right, data);
        else
            return true;
    }

/* Find Minimal Node Value in Binary Search Tree */
    BstNode *findMinNode(BstNode* root)
    {
        while (root->left != NULL)
            root = root->left;
        return root;
    }


/* Delete Node in Binary Search Tree */
    BstNode *remove(string data, BstNode* root)
    {
        if (root == NULL)
            return root;
        else if (data < root->data)
            root->left = remove(data, root->left);
        else if (data > root->data)
            root->right = remove(data, root->right);
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
            }
            else if (root->left == NULL)
            {
                BstNode *temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == NULL)
            {
                BstNode *temp = root;
                root = root->left;
                delete temp;
            }
            else
            {
                static BstNode *min = findMinNode(root->right);
                root->data = min->data;
                root->right = remove(min->data, root->right);
            }
        }
        return root;
    }
};

/*
class BinarySearchTree{
    BstNode* root;
public:
    void insert(string key, int info);
    int find(string key);
    void remove(string key);
    void print(ostream & out);
};

void BinarySearchTree::insert(string key, int info){
    root = BstNode::insert(key, info, root);
}

int BinarySearchTree::find(string data){
    cout << "1.             find function of BST class" << endl;
    BstNode* t = BstNode::find(data, root);
    cout << "2.             find function of BST class" << endl;
    return 0;
}

void BinarySearchTree::remove(string key){
    root = BstNode::remove(key, root);
}

void BinarySearchTree::print(ostream& out){
    TreeNode::print(out, root);
    
}
*/

void insertAllWords(BstNode& T, int partition, string& input_file){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    BstNode* root;
    root = new BstNode;
    if(f.is_open()){
        for(int i=0; i < partition*9000; i++){
            
            getline(f,w);
            cout << "w is " << w << endl;
            T.insert(w, 1, BstNode* root);         // test test test test
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "insertAllWords time of\t" << "partition\t" << partition << " is " << eTime << endl;
}

void findAllWords(BstNode& T, int partition, string& input_file){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        for(int i=0; i < partition*4500; i++){
            getline(f, w);
            T.find(BstNode* root, string data);      // test test test test
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "findAllWords time of\t" << "partition\t" << partition << " is " << eTime << endl;
}

void removeAllWords(BstNode& T, int partition, string& input_file){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        //        while(getline(f, w)){
        for(int i=0; i < partition*10; i++){
            T.remove(string data, BstNode* root);
        }
    }
    
    t.elapsedUserTime(eTime);
    f.close();
    cout << "removeAllWords time of\t" << "partition\t" << partition << " is " << eTime << endl;
}

void measureAll(string input_file, BstNode& T){
    for (int i=1; i<=1; ++i){
//        BinarySearchTree T;             //important to start with an empty Tree here
        insertAllWords(T, i, input_file);
        
        //        T.print(ostream& out);
        
//        findAllWords(T, i, input_file);
        //        removeAllWords(T, i, input_file);
        cout << "test" << endl;
    }
}

int main(int argc, char* argv[]){
    
    const char* input_file = argc == 2? argv[1] : "random.txt";
    
    BstNode D;
    
    measureAll(input_file, D);
    
    return 0;
}
