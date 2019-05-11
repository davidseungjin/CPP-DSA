#include <iostream>
#include <cstdlib>

using namespace std;



class BST{
private:
    struct Node{
        int key;
        Node* left;
        Node* right;
    };

    Node* root;
    void AddLeafPrivate(int key, Node* Ptr);
    void PrintInOrderPrivate(Node* Ptr);
    Node* ReturnNodePrivate(int key, Node* Ptr);
    int FindSmallestPrivate(Node* Ptr);
    void RemoveNodePrivate(int key, Node* Parent);
    void RemoveRootMatch();
    void RemoveMatch(Node* Parent, Node* match, bool left);
    
public:
    BST();
    Node* CreateLeaf(int key);
    
    void AddLeaf(int key);
    void PrintInOrder();
    Node* ReturnNode(int key);
    int ReturnRootKey();
    void PrintChildren(int key);
    int FindSmallest();
    void RemoveNode(int key);
    
};

BST::BST(){
    root = NULL;
}
BST::Node* BST::CreateLeaf(int key){
    Node* n = new Node;
    n -> key = key;
    n -> left = NULL;
    n -> right = NULL;
    
    return n;
}


void BST::AddLeaf(int key){                 // part 5
    AddLeafPrivate(key, root);
}

void BST::AddLeafPrivate(int key, Node* Ptr){
    if(root == NULL){
        root = CreateLeaf(key);
    }else if(key < Ptr -> key){
        if(Ptr -> left != NULL){
            AddLeafPrivate(key, Ptr -> left);
        } else{
            Ptr -> left = CreateLeaf(key);
        }
    }else if(key > Ptr -> key){
        if(Ptr -> right != NULL){
            AddLeafPrivate(key, Ptr -> right);
        } else{
            Ptr -> right = CreateLeaf(key);
        }
    }else{
        cout << "The Key " << key << " has already been added to the tree\n";
    }
}

void BST::PrintInOrder(){
    PrintInOrderPrivate(root);
}


void BST::PrintInOrderPrivate(Node* Ptr){
    if(root != NULL){
        if(Ptr -> left != NULL){
            PrintInOrderPrivate(Ptr -> left);
        }
        cout << Ptr -> key << " ";
        if(Ptr -> right != NULL){
            PrintInOrderPrivate(Ptr -> right);
        }
    }else{
        cout << "The tree is empty \n";
    }
}

BST::Node* BST::ReturnNode(int key){
    return ReturnNodePrivate(key, root);
}

BST::Node* BST::ReturnNodePrivate(int key, Node* Ptr){
    if(Ptr != NULL){
        if(Ptr -> key == key){
            return Ptr;
        }else{
            if(key < Ptr -> key){
                return ReturnNodePrivate(key, Ptr -> left);
            }else{
                return ReturnNodePrivate(key, Ptr -> right);
            }
        }
    }else{
        return NULL;
    }
}

int BST::ReturnRootKey(){
    if(root != NULL){
        return root -> key;
    }else{
        return -1000;               // if negative number is in binary search tree, you need to find another way to implement.
    }
}

void BST::PrintChildren(int key){
    Node* Ptr = ReturnNode(key);
    
    if(Ptr != NULL){
        cout << "Parent Node = " << Ptr -> key << endl;
        Ptr -> left == NULL?
        cout << "Left Child = NULL\n":
        cout << "Left Child = " << Ptr -> left -> key << endl;

        Ptr -> right == NULL?
        cout << "Right Child = NULL\n":
        cout << "Right Child = " << Ptr -> right -> key << endl;

    }else{
        cout << "Key " << key << " is not in the tree\n";
    }
}

int BST::FindSmallest(){
    return FindSmallestPrivate(root);
}

int BST::FindSmallestPrivate(Node* Ptr){
    if(root == NULL){
        cout << "The tree is empty\n";
        return -1000;
    }else{
        if(Ptr -> left != NULL){
            return FindSmallestPrivate(Ptr -> left);
        }else{
            return Ptr -> key;
        }
    }
}

void BST::RemoveNode(int key){
    RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, Node* Parent){
    if(root != NULL){
        if(root -> key == key){
            RemoveRootMatch();
        }else{
            if((key < Parent -> key) && (Parent -> left != NULL)){
                Parent -> left -> key == key?
                RemoveMatch(Parent, Parent -> left, true):
                RemoveNodePrivate(key, Parent -> left);
            }else if((key > Parent -> key) && (Parent -> right != NULL)){
                Parent -> right -> key == key?
                RemoveMatch(Parent, Parent -> right, false) :
                RemoveNodePrivate(key, Parent -> right);
            }else{
                cout << "The key " << key << " was not found in the tree\n";
            }
        }
    }else{
        cout << "The tree is empty\n";
    }
}


void BST::RemoveRootMatch(){
    if(root != NULL){
        Node* delPtr = root;
        int rootKey = root -> key;
        int smallestInRightSubtree;
        
        // case 0 - 0 children
        if((root -> left == NULL) && (root -> right == NULL)){
            root = NULL;
            delete delPtr;
        }else if((root -> left == NULL) && (root -> right != NULL)){
            root = root -> right;
            delPtr -> right = NULL;
            delete delPtr;
            cout << "The root Node with key " << rootKey << " was deleted. " << endl <<
            "The new root contains key " << root -> key << endl;
        }else if((root -> left != NULL) && (root -> right == NULL)){
            root = root -> left;
            delPtr -> left = NULL;
            delete delPtr;
            cout << "The root Node with key " << rootKey << " was deleted. " << endl <<
            "The new root contains key " << root -> key << endl;
        }else{
            smallestInRightSubtree = FindSmallestPrivate(root -> right);
            RemoveNodePrivate(smallestInRightSubtree, root);
            root -> key = smallestInRightSubtree;
            cout << "The root key containing key " << rootKey <<
            " was overwritten with key " << root -> key << endl;
        }
        
        
    }else{
        cout << "Can not remove root because the tree is empty\n";
    }
}


void BST::RemoveMatch(Node* Parent, Node* match, bool left){
    if(root != NULL){
        Node* delPtr;
        int matchkey = match -> key;
        int smallestInRightSubtree;
        
        if(match -> left == NULL && match -> right == NULL){
            delPtr = match;
            left == true? Parent -> left = NULL: Parent -> right = NULL;
            delete delPtr;
            cout << "The Node containing key " << matchkey << " was removed\n";
        }else if(match -> left == NULL && match -> right != NULL){
            left == true? Parent -> left = match -> right: Parent -> right = match -> right;
            match -> right = NULL;
            delPtr = match;
            delete delPtr;
            cout << "The Node containing key " << matchkey << " was removed\n";
        }else if(match -> left != NULL && match -> right == NULL){
            left == true? Parent -> left = match -> left: Parent -> right = match -> left;
            match -> left = NULL;
            delPtr = match;
            delete delPtr;
            cout << "The Node containing key " << matchkey << " was removed\n";
        }else{
            smallestInRightSubtree = FindSmallestPrivate(match -> right);
            RemoveNodePrivate(smallestInRightSubtree, match);
            match -> key = smallestInRightSubtree;
        }
        
    }else{
        cout << "Can not remove match. The tree is empty\n";
    }
}








int main(){
    
    int TreeKeys[] = {50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};
    BST myTree;
    
    cout << "Printin the tree in order \nBefore adding numbers \n";
    
    myTree.PrintInOrder();
    
    
    for(int i=0; i < 16; i++){
        myTree.AddLeaf(TreeKeys[i]);
    }
    
    cout << "Printin the tree in order \nAfter adding numbers \n";
    
    myTree.PrintInOrder();
    cout << endl;
    
//    myTree.PrintChildren(myTree.ReturnRootKey());
    
//    for(int i=0; i < 16; i++){
//        myTree.PrintChildren(TreeKeys[i]);
//        cout << endl;
//    }

    cout << "The smallest value in the tree is " << myTree.FindSmallest() << endl;
    
    cout << "Enter a key value to delete. Enter -1 to stop the process \n";
    int input;
    while(input!= -1){
        cout << "Delete Node: ";
        cin >> input;
        {
            if(input != -1){
                cout << endl;
                myTree.RemoveNode(input);
                myTree.PrintInOrder();
                cout << endl;
            }
        }
    }
    
    return 0;
}
